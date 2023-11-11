#pragma once

#include "MapT.h"
#include "SharkT.h"
#include "GameT.h"

class DolphinT: public SharkT::SharkT{
    public:
        DolphinT(int breed, int starve, int turns): SharkT{breed, starve, turns}{}

        void Turn(int turns, MapT& map, CoordT cord, GameT& game) override;
    private:
        int moveTimer{0}; 
};