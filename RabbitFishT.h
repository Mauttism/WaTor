#pragma once

#include "MapT.h"
#include "FishT.h"
#include "GameT.h"

/*I made this because, with both Sharks and Dolphins eating fish,
I realised they were dying Way Too Quick. They are counted as Fish,
but also have their number displayed seperately.*/
class RabbitFishT: public FishT::FishT{
    public:
        RabbitFishT(int breed, int turns): FishT{breed, turns}, breedTimer{breed}, breedAt{breed}, moveTimer{turns-1} {}

        void Turn(int turns, MapT& map, CoordT cord, GameT& game) override;
    protected:
        void Breed(CoordT oldCord, GameT& game, MapT& map) override;
    private:
        int breedTimer;
        int breedAt;
        int moveTimer;
};