#include <fstream>
#include <cstring>
#include "Room.h"

Room::Room(){
    north = 0;
    east = 0;
    south = 0;
    west = 0;
    gameOver = 0;
    roomName = "No Name";
}

Room::Room(int north, int south, int east, int west, int gameOver){
    this->north = north;
    this->east = east;
    this->south = south;
    this->west = west;
    this->gameOver = gameOver;
}

Room::Room(int north, int south, int east, int west, int gameOver, string roomName){
    char *token = strtok(roomName.data(), ",");

    for(int i = 0; i < 6; i++){
        if (i == 0){
            this->roomName = token;
        } else if(i == 1){
            this->north = stoi(token);
        } else if(i == 2){
            this->south = stoi(token);
        } else if(i == 3){
            this->east = stoi(token);
        } else if (i == 4){
            this->west = stoi(token);
        } else {
            this->gameOver = stoi(token);
        }
        token = strtok(NULL, ",");
    }

}

int Room::getNorth(){
    return north;
}

int Room::getEast(){
    return east;
}

int Room::getSouth(){
    return south;
}

int Room::getWest(){
    return west;
}

string Room::getRoomName(){
    return roomName;
}

int Room::getGameOver(){
    return gameOver;
}

void Room::setNorth(int north){
    this->north = north;
}

void Room::setEast(int east){
    this->east = east;
}

void Room::setSouth(int south){
    this->south = south;
}

void Room::setWest(int west){
    this->west = west;
}

void Room::setGameOver(int gameOver){
    this->gameOver = gameOver;
}

void Room::setRoomName(string roomName){
    this->roomName = roomName;
}

Room::~Room(){
}
