#pragma once
#include <iostream>
#include <string>
using namespace std;

class GamePlayer {
private:
    string name;
    int lives;
    double score;

public:
    GamePlayer();
    GamePlayer(string name, int lives, double score);
    string getName();
    int getLives();
    double getScore();
    void setName(string name);
    void setLives(int lives);
    void setScore(double score);
    ~GamePlayer();
};