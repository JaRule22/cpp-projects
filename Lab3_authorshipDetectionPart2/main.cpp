//Jahaziel Alcala
//Lab1: Authorship Detection Part I
#include "authorStats.h"

int main(){
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    ifstream file;
    char word[MAX_LENGTH + 1]; //Buffer to read words
    char wordList[MAX_WORDS][MAX_LENGTH + 1];
    int uniqueWords[MAX_WORDS] = {0};
    int uniqueWordCount = 0;
    int totalTokenCount = 0;

    file.open("mystery5.txt");
    if (file.fail()){
        cout << "Input file failed to open\n";
        return 1;
    }

    while(file >> word){
        normalizeWord(word);

        if(strlen(word) == 0){
            continue;
        }
        totalTokenCount++;
        setWordsAndCount(wordList, uniqueWords, word, uniqueWordCount);
    }

    double totalAverageWords = averageWords(wordList, uniqueWords, uniqueWordCount, totalTokenCount);
    double totalTypeTokenRatio = typeTokenRatio(uniqueWordCount, totalTokenCount);
    double totalHapaxRatio = hapaxLegomanaRatio(uniqueWords, uniqueWordCount, totalTokenCount);

    //Part2
    AuthorStats** authors = nullptr;
    int numAuthors = 0;
    ifstream authorFile;

    int categoryCount = 0;
    int rowCount = 1;
    authorFile.open("authorStats.txt");
    char buffer[MAX_LENGTH];

    while(authorFile >> buffer){//Counts the number of authors in the text file
        categoryCount++;
        if(categoryCount / 5 == rowCount){
            rowCount++;
            numAuthors++;
        }
    }
    authorFile.close();

    authors = new AuthorStats*[numAuthors];// Sets double pointer

    loadAuthorStats(authors, numAuthors);
    identifyTheAuthor(authors, totalAverageWords, totalTypeTokenRatio, totalHapaxRatio, numAuthors);

    file.close();

    for (int i = 0; i < numAuthors; i++){
        delete authors[i]; 
    }

    delete[] authors;
    
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

double averageWords(char wordList[][MAX_LENGTH + 1], int uniqueWords[], int &uniqueWordCount, int &totalTokenCount){

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
    return (double)average;
} 

double typeTokenRatio(int &uniqueWordCount, int &totalTokenCount){
    double ratio = (double)uniqueWordCount / totalTokenCount;

    cout << fixed << setprecision(7);
    return (double)ratio;
    
}

double hapaxLegomanaRatio(int uniqueWords[], int &uniqueWordCount, int &totalTokenCount){
    double wordsAppearingOnceTotal = 0.0;

    for (int i = 0; i < uniqueWordCount; i++){
        if (uniqueWords[i] == 1){
            wordsAppearingOnceTotal++;
        }
    }

    cout << fixed << setprecision(7);
    return (double)wordsAppearingOnceTotal/totalTokenCount;
}

int loadAuthorStats(AuthorStats ** authorInfo, int & numAuthors){
    fstream authorFile;
    authorFile.open("authorStats.txt");
    // authorFile.clear();
    // authorFile.seekg(0, std::ios::beg);//reset reading the file

    for(int i = 0; i < numAuthors; i++){
        AuthorStats* author = new AuthorStats();// sets memory space for author

        authorFile >> author->firstName;
        authorFile >> author->lastName;
        authorFile >> author->averageWordLength;
        authorFile >> author->typeTokenRatio;
        authorFile >> author->hapaxLegomenaRatio;

        authorInfo[i] = author; //Adds pointer inside of the double pointer 
    }

    return 0;
}

void identifyTheAuthor(AuthorStats ** authorInfo, double averageWords, double typeTokenRatio, double hapaxLegomanaRatio, int & numAuthors){
    double lowestSimilarityScore = 0.0;
    int bestAuthorIndex = 0;

    for(int i = 0; i < numAuthors; i++){
        double authorAvgWordLength = authorInfo[i]->averageWordLength;
        double authorTypeTokenRatio = authorInfo[i]->typeTokenRatio;
        double authorHapaxRatio = authorInfo[i]->hapaxLegomenaRatio;

        double avgWordLengthDifference = abs(authorAvgWordLength - averageWords) * 11.0;
        double typeTokenRatioDifference = abs(authorTypeTokenRatio - typeTokenRatio) * 33.0;
        double hapaxRatioDifference = abs(authorHapaxRatio - hapaxLegomanaRatio) * 50.0;

        double similarityScore = avgWordLengthDifference + typeTokenRatioDifference + hapaxRatioDifference;

        if (similarityScore < lowestSimilarityScore){
            lowestSimilarityScore = similarityScore;
            bestAuthorIndex = i;
        } else if (lowestSimilarityScore == 0){
            lowestSimilarityScore = similarityScore;
            bestAuthorIndex = i;
        }
    }

    cout << "This text was most likely written by " << authorInfo[bestAuthorIndex]->firstName  << " " << authorInfo[bestAuthorIndex]->lastName << ".\n";
}   