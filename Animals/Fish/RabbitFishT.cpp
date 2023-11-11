#include "FishT.h"
#include "AnimalT.h"
#include "MapT.h"
#include "GameT.h"
#include "RabbitFishT.h"

using namespace std;

using AnimalPtr = shared_ptr<AnimalT>;

void RabbitFishT::Turn(int turns, MapT& map, CoordT cord, GameT& game){
    if(moveTimer != turns){    
        Move(map, cord);
        if(breedTimer <= 0){
            Breed(cord, game, map);
            breedTimer = breedAt;
        }else{
            breedTimer -= 2;
        }
    }
}

void RabbitFishT::Breed(CoordT oldCord, GameT& game, MapT& map){
    map.PlaceAnimal(game.CreateRabbit(), oldCord);
}
