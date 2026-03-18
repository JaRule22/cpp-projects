#ifndef AUTHOR_STATS_H
#define AUTHOR_STATS_H
#define _CRT_DBG_MAP_ALLOC
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <crtdbg.h>
using namespace std;

const int MAX_WORDS = 10000;
const int MAX_LENGTH = 35;
const int MAX_AUTHORS = 100;

struct AuthorStats {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    double averageWordLength;
    double typeTokenRatio;
    double hapaxLegomenaRatio;
};

int loadAuthorStats(AuthorStats ** authorInfo, int & numAuthors);

/// @brief This function will set unique words from the text file into an array called wordList, will set uniqueWords array to 1 if a new unique word appears, and add +1 to uniqueWordCount
/// @param wordList An array of unique words
/// @param uniqueWords A list of numbers(array) that has the count of every unique word that shows up in the text file 
/// @param word Buffer to read words
/// @param uniqueWordCount Total number of unique words in the text file
void setWordsAndCount(char wordList[][MAX_LENGTH + 1], int uniqueWords[], char word[MAX_LENGTH + 1], int &uniqueWordCount);

/// @brief This function will make sure that every word will be in lower case and that it won't have any punctuations.
/// @param word Buffer to read words
void normalizeWord(char word[]);

/// @brief This function will print the words and the total number of unique words
/// @param wordList An array of unique words
/// @param uniqueWords A list of numbers(array) that has the count of every unique word that shows up in the text file 
/// @param uniqueWordCount Total number of unique words in the text file
void printSets(char wordList[][MAX_LENGTH + 1], int uniqueWords[], int &uniqueWordCount);

/// @brief This function computes the total character count and divides it by the total token count
/// @param wordList An array of unique words
/// @param uniqueWords A list of numbers(array) that has the count of every unique word that shows up in the text file 
/// @param uniqueWordCount Total number of unique words in the text file
/// @param totalTokenCount The total of every single word coming from the text file
double averageWords(char wordList[][MAX_LENGTH + 1], int uniqueWords[], int &uniqueWordCount, int &totalTokenCount);

/// @brief This function computes the numbe of different words used in a text divided by the total number of words to measure how repetitive the vocabulary is
/// @param uniqueWordCount Total number of unique words in the text file
/// @param totalTokenCount The total of every single word coming from the text file
double typeTokenRatio(int &uniqueWordCount, int &totalTokenCount);

/// @brief This function computes the number of words occuring exactly once from the text file
/// @param uniqueWords A list of numbers(array) that has the count of every unique word that shows up in the text file 
/// @param uniqueWordCount Total number of unique words in the text file
/// @param totalTokenCount The total of every single word coming from the text file
double hapaxLegomanaRatio(int uniqueWords[], int &uniqueWordCount, int &totalTokenCount);

void identifyTheAuthor(AuthorStats ** authorInfo, double averageWords, double typeTokenRatio, double hapaxLegomanaRatio, int & numAuthors);

#endif