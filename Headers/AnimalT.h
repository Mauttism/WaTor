#pragma once 

class MapT;
class CoordT;
class GameT;

class AnimalT{
    public:
        virtual void Turn(int turns, MapT& map, CoordT cord, GameT& game) = 0;
        virtual void Remove(MapT& map, CoordT cord) = 0;
};