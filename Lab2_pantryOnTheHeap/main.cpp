#define _CRT_DBG_MAP_ALLOC
#include <iostream>
#include <fstream>
#include <cstring>
#include <crtdbg.h>
using namespace std;

const int PANTRY_MAX_SIZE = 360;
const int MAX_OF_CHARS = 35;

//part1
int loadFromFile(char** pStrs, int& numIngredients, char* fileName);
int displayIngredients(char** pStrs, int numIngredients);

//part2
int addIngredient(char** pStrs, int& numIngredients, char* addedIngredient);
int searchIngredients(char** pStrs, int numIngredients, char* checkIngredient);
int saveToFile(char** pStrs, int numIngredients, char* fileName);

//part3
int changeIngredient(char** pStrs, int numIngredients, char* oldIngredient, char* newIngredient);
int removeIngredient(char** pStrs, int& numIngredients, char* removeIngredient);



// Check Memory Leaks


int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    ifstream file;
    char** pStrs = nullptr;// pStrs is going to be the pantry. This pointer is pointing to the string mem address to the real value of the string
    char buffer[MAX_OF_CHARS];//buffer to read words from text file
    int numberOfPantryItems = 0;//number of pantry Items from the text file
    char fileName[] = "food.txt";//file name is stored in a char array
    char newFileName[] = "newPantry.txt";

    file.open(fileName);

    while (file >> buffer) {  //Sets the initial total number of items in the text file
        numberOfPantryItems++;
    }


    //part1
    pStrs = new char* [numberOfPantryItems + 1];
    loadFromFile(pStrs, numberOfPantryItems, fileName);
    displayIngredients(pStrs, numberOfPantryItems);

    //part2
    char newIngredient[] = "celery";
    char findIngredient[] = "rice";

    addIngredient(pStrs, numberOfPantryItems, newIngredient);
    searchIngredients(pStrs, numberOfPantryItems, findIngredient);
    saveToFile(pStrs, numberOfPantryItems, newFileName);

    //part3
    char oldIngredient[] = "rice";
    char ingredientReplacement[] = "red bull";
    changeIngredient(pStrs, numberOfPantryItems, oldIngredient, ingredientReplacement);

    char ingredientToBeRemoved[] = "fruit";
    removeIngredient(pStrs, numberOfPantryItems, ingredientToBeRemoved);

    for (int i = 0; i < numberOfPantryItems; i++) {
        delete[] pStrs[i];
    }

    delete[] pStrs;
    // pStrs = nullptr;
    file.close();
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    return 0;
}

//Part1
int loadFromFile(char** pStrs, int& numIngredients, char* fileName) {
    ifstream file;
    char* str = nullptr;
    char buffer[MAX_OF_CHARS];

    file.open(fileName);

    for (int i = 0; i < numIngredients; i++) {
        file >> buffer;

        str = new char[strlen(buffer) + 1];
        strcpy_s(str, strlen(buffer) + 1, buffer);

        pStrs[i] = str;
    }

    return 0;
}

int displayIngredients(char** pStrs, int numIngredients) {
    for (int i = 0; i < numIngredients; i++) {
        cout << pStrs[i] << endl;
    }

    return 0;
}

//Part2
int addIngredient(char** pStrs, int& numIngredients, char* addedIngredient) {
    pStrs[numIngredients] = new char[strlen(addedIngredient) + 1];
    strcpy_s(pStrs[numIngredients], strlen(addedIngredient) + 1, addedIngredient);
    // pStrs[numIngredients] = pStrs[numIngredients];
    numIngredients++;

    return 0;
}

int searchIngredients(char** pStrs, int numIngredients, char* checkIngredient) {

    for (int i = 0; i < numIngredients; i++) {
        if (strcmp(checkIngredient, pStrs[i]) == 0) {
            cout << "Found " << pStrs[i] << endl;
            break;
        }
    }
    return 0;
}

int saveToFile(char** pStrs, int numIngredients, char* fileName) {
    ofstream newFile("newPantry.txt");

    for (int i = 0; i < numIngredients; i++) {
        newFile << pStrs[i] << endl;
    }

    newFile.close();

    return 0;
}

//Part3
int changeIngredient(char** pStrs, int numIngredients, char* oldIngredient, char* newIngredient) {
    for (int i = 0; i < numIngredients; i++) {
        if (strcmp(oldIngredient, pStrs[i]) == 0) {
            delete[] pStrs[i];
            pStrs[i] = new char[strlen(newIngredient) + 1];
            strcpy_s(pStrs[i], strlen(newIngredient) + 1, newIngredient); // define stack pointer
            break;
        }
    }

    return 0;
}

int removeIngredient(char** pStrs, int& numIngredients, char* removeIngredient) {
    // char ** updatedPantry = new char *[numIngredients + 1];
    bool found = false;

    for (int i = 0; i < numIngredients; i++) {
        if (found) {
            pStrs[i - 1] = pStrs[i];
        }
        else if (strcmp(removeIngredient, pStrs[i]) == 0) {
            delete[] pStrs[i];
            found = true;
        }
    }

    if (found) {
        // delete[] pStrs[numIngredients - 1];
        pStrs[numIngredients - 1] = nullptr;
        numIngredients--;
    }

    return 0;
}

//deallocate memory: Change!