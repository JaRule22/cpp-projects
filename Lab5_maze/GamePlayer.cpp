#include "GamePlayer.h"

GamePlayer::GamePlayer(){
    name = "Bob";
    lives = 0;
    score = 0;
}

GamePlayer::GamePlayer(string name, int lives, double score){
    this->name = name;
    this->lives = lives;
    this->score = score;
}

string GamePlayer::getName(){
    return name;
}

int GamePlayer::getLives(){
    return lives;
}

double GamePlayer::getScore(){
    return score;
}

void GamePlayer::setName(string name){
    this->name = name;
}

void GamePlayer::setLives(int lives){
    if(lives > 0){
        this->lives = lives;
    }
}

void GamePlayer::setScore(double score){
    this->score = score;
}

GamePlayer::~GamePlayer(){

}
