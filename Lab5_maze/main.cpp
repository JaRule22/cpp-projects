#include <iostream>
#include "GamePlayer.h"
#include "GamePlayer.cpp"

using namespace std;

int main(){
    cout << "Let's play a game!" << endl;
    string name = "";
    cout << "What is your name?" << endl;
    cin >> name;

    GamePlayer defaultPlayer;
    GamePlayer * gamePlayer = new GamePlayer(name, 3, 0);
    cout << gamePlayer->getName() << " has " << gamePlayer->getLives() 
        << " lives and " << gamePlayer->getScore() << " points." << endl;
    
        cout << defaultPlayer.getName() << " has " << defaultPlayer.getLives() 
        << " lives and " << defaultPlayer.getScore() << " points." << endl;    
    return 0;
}

//Create a room class similar to GamePLayer class