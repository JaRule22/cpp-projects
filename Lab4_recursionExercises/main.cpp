#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const int MAX_ARRAY = 6;
const int MAX_NUM_FIBONACCI = 50;
const int MAX_WORDS = 35;

enum verses { VERSE1 = 1, VERSE2, VERSE3, VERSE4, VERSE5, VERSE6, VERSE7, VERSE8, VERSE9, VERSE10, VERSE11, VERSE12};

//part 1: Exercise 1
int powerFunction(int base, int power);

//Exercise 2
bool binarySearch(int numArray[], int index, int searchNumber, size_t arraySize);

//part 2: Exercise 3
void reversedString(char word[]);

//Exercise 4 Fibonacci Sequence
int fibonacciSequence(int fibonacciSequenceNumber);

//part 3: Exercise 5 Use switch statement to print all 12 verses of the Twelve Days of Christmas
void outputingFile(fstream& myFile, int verse, char buffer[]);
void twelveDaysOfChristmasTwelveVerses(fstream& myFile, int verse);

int main(){
    fstream myFile("The 12 Days of Christmas Lyrics.txt");
    int numArray[MAX_ARRAY] = {2, 4, 6, 8, 10, 12};
    int fibonacciSequenceNumber = 0;
    int index = 0;
    int searchNumber = 4;
    int verse = 1;
    char word[MAX_ARRAY];

    cout << powerFunction(4, 2) << endl;

    size_t arraySize = sizeof(numArray) / sizeof(numArray[0]);
    cout << binarySearch(numArray, index, searchNumber, arraySize) << endl;

    // cout << "Enter a word[Max letters = 5]: ";
    // cin >> word;
    // reversedString(word);
    // cout << endl;

    cout << "Enter a number to output the Fibonacci result[Max numbers = 50]: ";
    cin >> fibonacciSequenceNumber;
    cout << fibonacciSequence(fibonacciSequenceNumber) << endl;

    // if(myFile.is_open()){
    //     twelveDaysOfChristmasTwelveVerses(myFile, verse);
    // }

    // myFile.close();

    return 0;
}

/*Exercise 1:  Write a recursive function that simulates the predefined pow function.  
Your function should take two parameters, the base and the power and return the number 
raised to the power.  */
int powerFunction(int base, int power){
    if(power == 0){
        return 0;
    }

    return base * powerFunction(base, power - 1);
}

/*Exercise 2:   Write the recursive version of binary search.  Your function should take an array 
of integers as a parameter and the index to begin searching, an index to end searching, and a 
number to search for.(4 parameters total) and return a boolean indicating whether or not the 
number was found. 
Create a main method and call the two exercises, no need to have user input.*/
bool binarySearch(int numArray[], int index, int targetNumber, size_t arraySize){
    if (numArray[index] == targetNumber){//If target has been found then True
        return true;
    } else if (index == MAX_ARRAY - 1){//If target has not been found in the array then False
        return false;
    } else if (index == 0){//Sets the index to be half of the array size
        size_t halfArrayNum = arraySize / 2;
        index = halfArrayNum;
        return binarySearch(numArray, index, targetNumber, arraySize);
    } else if (numArray[index] < targetNumber){//If the target number is greater than array(mid)
        return binarySearch(numArray, index + 1, targetNumber, arraySize);
    } else {//If the target number is smaller than array(mid)
        if (index <= 1){
            return false;
        }
        return binarySearch(numArray, index - 1, targetNumber, arraySize);
    }

    return 0;
}

/*Exercise 3: Write a recursive function that displays any cString character by character in 
reverse order.  Ideally, this function requires just one parameter. Hint:  Look at the examples 
in 12.6*/
void reversedString(char * word){
    if(*word != '\0'){
        reversedString(word + 1);
    } else {
        return;
    }

    cout << *word;
}

/*Exercise 4: Write a recursive function that calculates the Fibonacci sequence up to a 
given number(e.g. given 5 it should return the 5th number of the Fibonacci sequence. 
Add code to your main method to call these two methods and prompt the user for any needed input.*/
int fibonacciSequence(int fibonacciSequenceNumber){//Single parameter, single integer
    if (fibonacciSequenceNumber == 0) {
        return 0;
    } else if(fibonacciSequenceNumber == 1){
        return 1;
    } else {
        return fibonacciSequence(fibonacciSequenceNumber - 1) + fibonacciSequence(fibonacciSequenceNumber - 2);
    }

    return 0;
}


/*Exercise 5: Write a function that prints all 12 verses of the Twelve Days of Christmas.  
You may only hard code each lyrical line of the song in your function once. You will need 
to use a recursive call and make clever use of a switch statement.*/
void outputingFile(fstream& myFile, int verse, char buffer[]){
    if (strchr(buffer, '.')){
        cout << buffer << endl << endl;
        return twelveDaysOfChristmasTwelveVerses(myFile, verse + 1);
    } else {
        cout << buffer << " ";
    }
}

void twelveDaysOfChristmasTwelveVerses(fstream& myFile, int verse){
    char buffer[MAX_WORDS];
    char *character = strchr(buffer, '.');

    while(myFile >> buffer){
        switch (verse){
            case VERSE1: outputingFile(myFile, verse, buffer); break;
            case VERSE2: outputingFile(myFile, verse, buffer); break;
            case VERSE3: outputingFile(myFile, verse, buffer); break;    
            case VERSE4: outputingFile(myFile, verse, buffer); break;
            case VERSE5: outputingFile(myFile, verse, buffer); break;          
            case VERSE6: outputingFile(myFile, verse, buffer); break;
            case VERSE7: outputingFile(myFile, verse, buffer); break;
            case VERSE8: outputingFile(myFile, verse, buffer); break;
            case VERSE9: outputingFile(myFile, verse, buffer); break; 
            case VERSE10: outputingFile(myFile, verse, buffer); break;
            case VERSE11: outputingFile(myFile, verse, buffer); break;     
            case VERSE12: outputingFile(myFile, verse, buffer); break;      
            default: break;     
        }
    }
}
