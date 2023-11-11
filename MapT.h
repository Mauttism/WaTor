#pragma once

#include <memory>
#include "AnimalT.h"

using AnimalPtr = std::shared_ptr<AnimalT>;

struct CoordT{
    size_t x, y;
};

//You should really write your algorithms before you try and write anything else 
class MapT{
    public:
        MapT(size_t w, size_t h): width{w}, height{h}{}

        AnimalPtr WhatsUp(const CoordT& cord);
        AnimalPtr WhatsDown(const CoordT& cord);
        AnimalPtr WhatsLeft(const CoordT& cord);
        AnimalPtr WhatsRight(const CoordT& cord);
        AnimalPtr WhatsHere(const CoordT& cord);
        AnimalPtr WhatsHere(size_t x, size_t y);

        CoordT CoordUp(const CoordT& cord);
        CoordT CoordDown(const CoordT& cord);
        CoordT CoordLeft(const CoordT& cord);
        CoordT CoordRight(const CoordT& cord);

        void PlaceAnimal(AnimalPtr animal, const CoordT& cord);

    private:
        size_t width, height;
        std::unique_ptr<AnimalPtr[]> map = std::make_unique<AnimalPtr[]>(width*height);
};