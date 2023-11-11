#include <random>
#include <memory>
#include <vector>
#include "FishT.h"
#include "AnimalT.h"
#include "MapT.h"
#include "GameT.h"

using namespace std;

using AnimalPtr = shared_ptr<AnimalT>;

void FishT::Turn(int turns, MapT& map, CoordT cord, GameT& game){
    if(moveTimer != turns){    
        Move(map, cord);
        if(breedTimer == 0){
            Breed(cord, game, map);
            breedTimer = breedAt;
        }else{
            breedTimer--;
        }
    }
}

void FishT::Remove(MapT& map, CoordT cord){
    map.WhatsHere(cord) = nullptr;
}

void FishT::Breed(CoordT oldCord, GameT& game, MapT& map){
    map.PlaceAnimal(game.CreateFish(), oldCord);
}

void FishT::Move(MapT& map, CoordT cord){
    random_device rd;
    mt19937 gen(rd());
    vector<CoordT> locations;

  
    if(map.WhatsUp(cord) == nullptr){
        locations.push_back(map.CoordUp(cord));
    }
    if(map.WhatsDown(cord) == nullptr){
        locations.push_back(map.CoordDown(cord));
    }    
    if(map.WhatsLeft(cord) == nullptr){
        locations.push_back(map.CoordLeft(cord));
    }
    if(map.WhatsRight(cord) == nullptr){
        locations.push_back(map.CoordRight(cord));
    }

    uniform_int_distribution<> move(0, static_cast<int>(locations.size())-1);

    if(locations.size() != 0){
        map.PlaceAnimal(map.WhatsHere(cord), locations[move(gen)]);
        map.PlaceAnimal(nullptr, cord);
    }

    moveTimer++;
}