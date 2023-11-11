#include <memory>
#include <iostream>
#include "MapT.h"
#include "AnimalT.h"
#include "GameT.h"

using namespace std;

using AnimalPtr = shared_ptr<AnimalT>;

AnimalPtr MapT::WhatsUp(const CoordT& cord){
    if(cord.y == 0){
        return map[(height-1)* (width)  + cord.x];
    }else{
        return map[(cord.y-1)* (width)  + cord.x];
    }
}
AnimalPtr MapT::WhatsDown(const CoordT& cord){
    if(cord.y == height-1){
        return map[(0)* (width)  + cord.x];
    }else{
        return map[(cord.y+1)* (width)  + cord.x];
    }
}
AnimalPtr MapT::WhatsLeft(const CoordT& cord){
    if(cord.x == 0){
        return map[(cord.y)* (width)  + width-1];
    }else{
        return map[(cord.y)* (width)  + cord.x-1]; 
    }
}
AnimalPtr MapT::WhatsRight(const CoordT& cord){
    if(cord.x == width-1){
        return map[(cord.y)* (width)  + 0]; 
    }else{
        return map[(cord.y)* (width)  + cord.x+1]; 
    }
}

AnimalPtr MapT::WhatsHere(const CoordT& cord){
    return map[(cord.y) * (width) + cord.x];

}

AnimalPtr MapT::WhatsHere(size_t x, size_t y){
    return map[y * (width) + x];
}


CoordT MapT::CoordUp(const CoordT& cord){
    CoordT CordUp = cord;
    if(CordUp.y == 0){
        CordUp.y = height-1;
    }else{
        CordUp.y--;
    }
    return CordUp;
}
CoordT MapT::CoordDown(const CoordT& cord){
    CoordT CordDown = cord;
    if(CordDown.y == height-1){
        CordDown.y = 0;
    }else{
        CordDown.y++;
    }
    return CordDown;
}
CoordT MapT::CoordLeft(const CoordT& cord){
    CoordT CordLeft = cord;
    if(CordLeft.x == 0){
        CordLeft.x = width-1;
    }else{
        CordLeft.x--; 
    }
    return CordLeft;
}
CoordT MapT::CoordRight(const CoordT& cord){
    CoordT CordRight = cord;
    if(CordRight.x == width-1){
        CordRight.x = 0;
    }else{
        CordRight.x++; 
    }
    return CordRight;
}

void MapT::PlaceAnimal(AnimalPtr animal, const CoordT& cord){
    map[(cord.y) * (width) + cord.x] = animal;
}
