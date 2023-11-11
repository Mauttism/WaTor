#include <memory>
#include <iostream>
#include <iomanip>
#include <random>
#include "GameT.h"
#include "MapT.h"
#include "FishT.h"
#include "SharkT.h"
#include "DolphinT.h"
#include "RabbitFishT.h"

using namespace std;
using AnimalPtr = shared_ptr<AnimalT>;

const int CH_WIDTH = 2;

void GameT::Turn(size_t x, size_t y){
    static size_t callCount{1};
    CoordT cord{x,y};

    if(callCount == width*height){
        turnCounter++;
        callCount = 0;
    }else{
        callCount++;
    }
    if(map.WhatsHere(cord) != nullptr){
        map.WhatsHere(cord)->Turn(turnCounter, map, cord, *this);
    }
}

// Combine these two into one function, maybe? Feels smarter to seperate them, but idk
AnimalPtr GameT::CreateShark(){
    auto newShark = make_shared<SharkT>(sharkBreed, sharkStarve, turnCounter);
    return newShark;
}
AnimalPtr GameT::CreateFish(){
    auto newFish = make_shared<FishT>(fishBreed, turnCounter);
    return newFish;
}

AnimalPtr GameT::CreateDolphin(){
    auto autoDolphin = make_shared<DolphinT>(sharkBreed, sharkStarve, turnCounter);
    return autoDolphin;
}
AnimalPtr GameT::CreateRabbit(){
    auto autoRabbit = make_shared<RabbitFishT>(fishBreed, turnCounter);
    return autoRabbit;
}

void GameT::Start(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> randX(0, static_cast<int>(width)-1);
    uniform_int_distribution<> randY(0, static_cast<int>(height)-1);

    //This generates a number of dolphins, from 5-10% of the size of the board.
    int dolphinMin = static_cast<int>(static_cast<double>(width*height)*0.05);
    int dolphinMax = static_cast<int>(static_cast<double>(width*height)*0.10);
    uniform_int_distribution<> randDolphin(dolphinMin, dolphinMax);

    //This generates random about of the Fish that are Rabbit Fish, from 20-30%.
    int rabbitMin = static_cast<int>(static_cast<double>(fishNumber)*0.2);
    int rabbitMax = static_cast<int>(static_cast<double>(fishNumber)*0.3);
    uniform_int_distribution<> randRabbit(rabbitMin, rabbitMax);

    rabbitNumber = randRabbit(gen);


    for(int i = 0; i < fishNumber-rabbitNumber; i++){
        CoordT cord{static_cast<size_t>(randX(gen)), static_cast<size_t>(randY(gen))};
        while(map.WhatsHere(cord) != nullptr){
            cord.x = randX(gen);
            cord.y = randY(gen);
        }
        map.PlaceAnimal(CreateFish(), cord);
    }
    for(int i = 0; i < rabbitNumber; i++){
        CoordT cord{static_cast<size_t>(randX(gen)), static_cast<size_t>(randY(gen))};
        while(map.WhatsHere(cord) != nullptr){
            cord.x = randX(gen);
            cord.y = randY(gen);
        }
        map.PlaceAnimal(CreateRabbit(), cord);
    }
    for(int i = 0; i < sharkNumber; i++){
        CoordT cord{static_cast<size_t>(randX(gen)), static_cast<size_t>(randY(gen))};
        while(map.WhatsHere(cord) != nullptr){
            cord.x = randX(gen);
            cord.y = randY(gen);
        }
        map.PlaceAnimal(CreateShark(), cord);
    }

    dolphinNumber = randDolphin(gen);
    for(int i = 0; i < dolphinNumber; i++){
        CoordT cord{static_cast<size_t>(randX(gen)), static_cast<size_t>(randY(gen))};
        while(map.WhatsHere(cord) != nullptr){
            cord.x = randX(gen);
            cord.y = randY(gen);
        }
        map.PlaceAnimal(CreateDolphin(), cord);
    }
    
}

void GameT::Display(){

    cout << "Turn Number: " << turnCounter << endl << endl;

    if(turnCounter == 42){
        cout << "So Long, and Thanks For All the Fish!" << endl;
    }

    fishNumber = 0;
    sharkNumber = 0;
    dolphinNumber = 0;
    rabbitNumber = 0;

    cout << setw(CH_WIDTH) << right << "";
    // print 0(...) width-1
    for(size_t i = 0; i < width; i++){
        cout << setw(CH_WIDTH) << right << i;
    }
    cout << endl;
    // print the rest of rows
    for(size_t i = 0; i < height; i++){
        cout << setw(CH_WIDTH) << right << i;
        for(size_t j = 0; j < width; j++){
            cout << setw(CH_WIDTH) << right << DisplayAnimal(j,i);
        }
        cout << endl;
    }
    cout << "Fish (F):    " << fishNumber << endl;
    cout << "Shark (S):   " << sharkNumber << endl;
    cout << "Dolphin (D): " << dolphinNumber << endl;
    cout << "Rabbit (R):  " << rabbitNumber << endl;
}

char GameT::DisplayAnimal(size_t x, size_t y){

    if(dynamic_cast<RabbitFishT*>(map.WhatsHere(x,y).get()) != nullptr){
        rabbitNumber++;
        fishNumber++;
        return 'R';
    }else if(dynamic_cast<FishT*>(map.WhatsHere(x,y).get()) != nullptr){
        fishNumber++;
        return 'F';
    }else if(dynamic_cast<DolphinT*>(map.WhatsHere(x,y).get()) != nullptr){
        dolphinNumber++;
        return 'D';
    }else if(dynamic_cast<SharkT*>(map.WhatsHere(x,y).get()) != nullptr){
        sharkNumber++;
        return 'S';
    }else{
        return '*';
    }
}