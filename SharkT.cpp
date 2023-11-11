#include <random>
#include <memory>
#include <vector>
#include "SharkT.h"
#include "AnimalT.h"
#include "MapT.h"
#include "GameT.h"
#include "FishT.h"

using namespace std;

using AnimalPtr = shared_ptr<AnimalT>;


void SharkT::Turn(int turns, MapT& map, CoordT cord, GameT& game){
    if(starveTimer == 0){
        Remove(map, cord);
    }else{     
        if(moveTimer != turns){
            Move(map, cord);
            moveTimer++;
            if(breedTimer == 0){
                Breed(cord, game, map);
                breedTimer = breedAt;
            }else{
                breedTimer--;
            }
        }
        starveTimer--;
    }
}


void SharkT::Remove(MapT& map, CoordT cord){
    map.PlaceAnimal(nullptr, cord);
}   

void SharkT::Breed(CoordT oldCord, GameT& game, MapT& map){
    map.PlaceAnimal(game.CreateShark(), oldCord);
}

void SharkT::Move(MapT& map, CoordT cord){
    random_device rd;
    mt19937 gen(rd());
    vector<CoordT> fishLocation;
    vector<CoordT> blankLocation;
    CoordT fishCord;
    CoordT blankCord;
    
    if(map.WhatsUp(cord) == nullptr){
        blankLocation.push_back(map.CoordUp(cord));
    }else if(dynamic_cast<FishT*>(map.WhatsUp(cord).get()) != nullptr){
        fishLocation.push_back(map.CoordUp(cord));
    }
    if(map.WhatsDown(cord) == nullptr){
        blankLocation.push_back(map.CoordDown(cord));
    }else if(dynamic_cast<FishT*>(map.WhatsDown(cord).get()) != nullptr){
        fishLocation.push_back(map.CoordDown(cord));
    }   
    if(map.WhatsLeft(cord) == nullptr){
        blankLocation.push_back(map.CoordLeft(cord));
    }else if(dynamic_cast<FishT*>(map.WhatsLeft(cord).get()) != nullptr){
        fishLocation.push_back(map.CoordLeft(cord));
    }
    if(map.WhatsRight(cord) == nullptr){
        blankLocation.push_back(map.CoordRight(cord));
    }else if(dynamic_cast<FishT*>(map.WhatsRight(cord).get()) != nullptr){
        fishLocation.push_back(map.CoordRight(cord));
    }

    uniform_int_distribution<> fishMove(0, static_cast<int>(fishLocation.size()-1));
    uniform_int_distribution<> blankMove(0, static_cast<int>(blankLocation.size()-1));

    
    if(fishLocation.size() != 0){
        fishCord = fishLocation[fishMove(gen)];
        map.PlaceAnimal(map.WhatsHere(cord), fishCord);
        map.PlaceAnimal(nullptr, cord);
    }else if (blankLocation.size() != 0){
        blankCord = blankLocation[blankMove(gen)];
        map.PlaceAnimal(map.WhatsHere(cord), blankCord);
        map.PlaceAnimal(nullptr, cord);
    }
}
