#pragma once
#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    int north;
    int east;
    int south;
    int west;
    int gameOver;
    string roomName;

public:
    Room();
    Room(int north, int south, int east, int west, int gameOver);
    Room(int north, int south, int east, int west, int gameOver, string roomName);
    int getNorth();
    int getEast();
    int getSouth();
    int getWest();
    string getRoomName();
    int getGameOver();
    void setNorth(int north);
    void setEast(int east);
    void setSouth(int south);
    void setWest(int west);
    void setGameOver(int gameOver);
    void setRoomName(string roomName);
    ~Room();
};
