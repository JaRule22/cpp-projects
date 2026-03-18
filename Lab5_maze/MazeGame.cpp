#include <iostream>
#include <cstring>
#include <fstream>
#include "Room.h"
#include "GamePlayer.h"
#include "Room.cpp"
#include "GamePlayer.cpp"

//set constants to store the max length of a line and the max number of rooms
const int MAX_LENGTH = 256;
const int MAX_NUM_ROOMS = 10;

void gameOverText();

int main(){
    int north = 0;
    int south = 0;
    int east = 0;
    int west = 0;
    int gameOver = 0;
    int index = 0;
    string roomName = "";
    string line = "";
    Room **rooms_array = new Room*[MAX_NUM_ROOMS];
    ifstream myFile("mansion.txt");
    
     while(getline(myFile, roomName)){
        Room *room = nullptr;
        room = new Room(north, south, east, west, gameOver, roomName);
        rooms_array[index] = room;
        index++;
    }

    cout << "Welcome!" << endl;
    string name = "";
    cout << "What is your name? ";
    cin >> name;

    GamePlayer * newPlayer = new GamePlayer(name, 3, 0);
    cout << "Welcome, " << name << endl;
    cout << "You will be play a Maze Game." << endl;

    int i = 0;
    cout << "You are currently in " << rooms_array[i]->getRoomName() << endl;
    string userInput = "";
    while(rooms_array[i]->getGameOver() != 0){
        if(rooms_array[i]->getNorth() > -1){
            cout << "North is open. " << rooms_array[i]->getNorth() << endl;
        }
        if(rooms_array[i]->getSouth() > -1){
            cout << "South is open. " << rooms_array[i]->getSouth() << endl;
        }
        if(rooms_array[i]->getEast() > -1){
            cout << "East is open. " << rooms_array[i]->getEast() << endl;
        }
        if(rooms_array[i]->getWest() > -1){
            cout << "West is open. " << rooms_array[i]->getWest() << endl;
        }

        cout << "Select the location listed: ";
        cin >> userInput;

        int num = stoi(userInput);
        i = num;
        cout << "You are currently in " << rooms_array[i]->getRoomName() << endl;
    }

    if(rooms_array[i]->getGameOver() == 0){
        cout << "You are currently in " << rooms_array[i]->getRoomName() << endl;
        cout << "You have found the exit!\nGAME OVER." << endl;
    }
    
    return 0;
}