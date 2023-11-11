#include <iostream>
#include <fstream>
#include <random>
#include "GameT.h"

using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    MapInfoT MapInfo;
    FishInfoT FishInfo;
    SharkInfoT SharkInfo;
    fstream init;
    string junk;
    size_t gameLength;


    init.open("wator.init");
    

    init >> MapInfo.w;
    init >> MapInfo.h;
    init >> FishInfo.num;
    init >> FishInfo.breed;
    init >> SharkInfo.num;
    init >> SharkInfo.breed;
    init >> SharkInfo.starve;

    GameT game(MapInfo, FishInfo, SharkInfo);

    cout << "Starting Game" << endl;
    game.Start();

    cout << "Display Game" << endl;
    game.Display();

    getline(cin, junk);

    uniform_int_distribution<> afterDolphins(1, 15);

    gameLength = 42 + static_cast<size_t>(afterDolphins(gen));

    for(size_t i = 1; i <= gameLength; i++){
        for(size_t j = 0; j < (MapInfo.h); j++){
            for (size_t k = 0; k < (MapInfo.w); k++){
                game.Turn(k,j);
            }
        }
        game.Display();
        getline(cin, junk);
    }


    cout << "Oh no! The planet was destroyed by Vogons!" << endl;

    cout << "Quick, cover your ears! He has a poety book!" << endl;



    return 0;
}