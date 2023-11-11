#pragma once

#include "MapT.h"
#include "AnimalT.h"
#include "GameT.h"

class SharkT: public AnimalT::AnimalT{
    public:
        SharkT(int breed, int starve, int turns): breedTimer{breed}, starveTimer{starve}, breedAt{breed}, moveTimer{turns-1} {}
        
        void Turn(int turns, MapT& map, CoordT cord, GameT& game) override;
        void Remove(MapT& map, CoordT cord) override;
    protected:
        void Breed(CoordT oldCord, GameT& game, MapT& map);
        void Move(MapT& map, CoordT cord);
    private:
        int breedTimer;
        int starveTimer;
        int breedAt;
        int moveTimer; 
};