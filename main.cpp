//Jahaziel Alcala
//Lab1: Authorship Detection Part I
#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

const int MAX_WORDS = 10000;
const int MAX_LENGTH = 35;
// Part 1:  

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
void averageWords(char wordList[][MAX_LENGTH + 1], int uniqueWords[], int &uniqueWordCount, int &totalTokenCount);

/// @brief This function computes the numbe of different words used in a text divided by the total number of words to measure how repetitive the vocabulary is
/// @param uniqueWordCount Total number of unique words in the text file
/// @param totalTokenCount The total of every single word coming from the text file
void typeTokenRatio(int &uniqueWordCount, int &totalTokenCount);

/// @brief This function computes the number of words occuring exactly once from the text file
/// @param uniqueWords A list of numbers(array) that has the count of every unique word that shows up in the text file 
/// @param uniqueWordCount Total number of unique words in the text file
/// @param totalTokenCount The total of every single word coming from the text file
void hapaxLegomanaRatio(int uniqueWords[], int &uniqueWordCount, int &totalTokenCount);

int main(){
    // ifstream file;
    // char word[MAX_LENGTH + 1]; //Buffer to read words
    // char wordList[MAX_WORDS][MAX_LENGTH + 1];
    // int uniqueWords[MAX_WORDS] = {0};
    // int uniqueWordCount = 0;
    // int totalTokenCount = 0;

    // file.open("mystery1.txt");
    // if (file.fail()){
    //     cout << "Input file failed to open\n";
    //     return 1;
    // }

    // while(file >> word){
    //     normalizeWord(word);

    //     if(strlen(word) == 0){
    //         continue;
    //     }
    //     // cout << word << endl;
    //     // part 2
    //     totalTokenCount++;
    //     setWordsAndCount(wordList, uniqueWords, word, uniqueWordCount);
    // }
    // // printSets(wordList, uniqueWords, count);
    // //part 3
    // averageWords(wordList, uniqueWords, uniqueWordCount, totalTokenCount);
    // typeTokenRatio(uniqueWordCount, totalTokenCount);
    // hapaxLegomanaRatio(uniqueWords, uniqueWordCount, totalTokenCount);

    double ** dp = new double*[10];
    cout << sizeof(new double*[10]) << endl;

    return 0;
}

void setWordsAndCount(char wordList[][MAX_LENGTH + 1], int uniqueWords[], char word[MAX_LENGTH + 1], int &uniqueWordCount){
    for(int i = 0; i < uniqueWordCount; i++){
        if (strcmp(wordList[i], word) == 0) {
            uniqueWords[i]++;
            return;
        }
    }
    
    strcpy(wordList[uniqueWordCount], word);
    uniqueWords[uniqueWordCount] = 1;
    uniqueWordCount++;
}

void normalizeWord(char word[]){
    for (int i = 0; word[i]; i++){ // convert to lowercase
        word[i] = tolower(word[i]);
    }
}


void printSets(char wordList[][MAX_LENGTH + 1], int uniqueWords[], int uniqueWordCount){
    for(int i = 0; i < uniqueWordCount; i++){
        cout << wordList[i] << " " << uniqueWords[i] << endl;
    }
}

void averageWords(char wordList[][MAX_LENGTH + 1], int uniqueWords[], int &uniqueWordCount, int &totalTokenCount){

    double average = 0.0;
    double totalLetterCount = 0.0;
    int totalWordOccurences = 0;

    for (int i = 0; i < uniqueWordCount; i++){
        double letterLength = strlen(wordList[i]);
        totalLetterCount += letterLength * uniqueWords[i];
        totalWordOccurences += uniqueWords[i];
    }

    average = totalLetterCount / totalTokenCount;

    cout << fixed << setprecision(7);
    cout << "The average word length is: " << (double)average << endl;
} 

void typeTokenRatio(int &uniqueWordCount, int &totalTokenCount){
    double ratio = (double)uniqueWordCount / totalTokenCount;

    cout << fixed << setprecision(7) << "The type token ratio is: " << (double)ratio << endl;
}

void hapaxLegomanaRatio(int uniqueWords[], int &uniqueWordCount, int &totalTokenCount){
    double wordsAppearingOnceTotal = 0.0;

    for (int i = 0; i < uniqueWordCount; i++){
        if (uniqueWords[i] == 1){
            wordsAppearingOnceTotal++;
        }
    }

    cout << fixed << setprecision(7) << "The Hapax Legomana ratio is: " << (double)wordsAppearingOnceTotal/totalTokenCount << endl;
}