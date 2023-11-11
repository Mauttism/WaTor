#pragma once

#include <memory>
#include "MapT.h"
#include "AnimalT.h"

using AnimalPtr = std::shared_ptr<AnimalT>;

struct MapInfoT{
    size_t w, h;
};

struct FishInfoT{
    int num, breed;
};

struct SharkInfoT{
    int num, breed, starve;
};

class GameT{
    public:
        GameT(const MapInfoT& MapInfo, const FishInfoT& FishInfo, const SharkInfoT& SharkInfo): 
        width{MapInfo.w}, height{MapInfo.h}, map{width, height}, fishNumber{FishInfo.num}, sharkNumber{SharkInfo.num}, 
        fishBreed{FishInfo.breed}, sharkBreed{SharkInfo.breed}, sharkStarve{SharkInfo.starve}{}
        ~GameT() = default;

        void Start();
        void Turn(size_t x, size_t y);
        void Display();
        //Wish I can make these two private, but I need my Map to get to them.
        AnimalPtr CreateShark();
        AnimalPtr CreateFish();
        AnimalPtr CreateDolphin();
        AnimalPtr CreateRabbit();
    private:
        char DisplayAnimal(size_t x, size_t y);

        size_t width;
        size_t height;
        MapT map;
        int turnCounter{1};
        int fishNumber;
        int sharkNumber;
        int fishBreed;
        int sharkBreed;
        int sharkStarve;
        int dolphinNumber;
        int rabbitNumber;
};