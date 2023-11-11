#pragma once

#include "MapT.h"
#include "AnimalT.h"
#include "GameT.h"

class FishT: public AnimalT::AnimalT{
    public:
        FishT(int breed, int turns): breedTimer{breed}, breedAt{breed}, moveTimer{turns-1} {}

        void Turn(int turns, MapT& map, CoordT cord, GameT& game) override;
        void Remove(MapT& map, CoordT cord) override;
    protected:
        virtual void Breed(CoordT oldCord, GameT& game, MapT& map);
        void Move(MapT& map, CoordT cord);
    private:
        int breedTimer;
        int breedAt;
        int moveTimer;
};