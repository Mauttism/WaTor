#include <random>
#include <memory>
#include <vector>
#include "SharkT.h" 
#include "DolphinT.h"
#include "AnimalT.h"
#include "MapT.h"
#include "GameT.h"
#include "FishT.h"

using namespace std;

using AnimalPtr = shared_ptr<AnimalT>;


void DolphinT::Turn(int turns, MapT& map, CoordT cord, GameT& game){ 
    if(moveTimer >= 41){
        Remove(map, cord);
    }else{
        if(moveTimer != turns){
            Move(map, cord);
            moveTimer++;
        }
    }

    if(turns == 60){
        Breed(cord, game, map);
    }

}