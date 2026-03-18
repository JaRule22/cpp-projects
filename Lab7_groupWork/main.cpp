#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

const int JPEG_SIZE_BYTES = 512;

int main(){
    int numberOfFiles = -1;
    ifstream raw("C:\\VSCode_cpp\\CST126\\lab7_groupWork\\card.raw", ios::in | ios::binary);
    ofstream outFile;
    

    if(raw.is_open()){

        const unsigned char jpgHeader1[4] = {0xFF, 0xD8, 0xFF, 0xE0};
        const unsigned char jpgHeader2[4] = {0xFF, 0xD8, 0xFF, 0xE1};
        unsigned char rawFileBlock[JPEG_SIZE_BYTES];

            while(raw.read(reinterpret_cast<char*>(rawFileBlock), JPEG_SIZE_BYTES)){
                if(memcmp(jpgHeader1, rawFileBlock, 4) == 0 || memcmp(jpgHeader2, rawFileBlock, 4) == 0){
                    outFile.close();
                    cout << "There is a JPG file." << endl;
                    numberOfFiles++;
                    outFile.open("000" + to_string(numberOfFiles) + ".jpg", ios::out | ios::binary);
                    cout << &outFile << endl;
                    outFile.write(reinterpret_cast<char*>(rawFileBlock), JPEG_SIZE_BYTES);
                    } else if (numberOfFiles >= 0) {
                        outFile.write(reinterpret_cast<char*>(rawFileBlock), JPEG_SIZE_BYTES);
                    }
        }
    }
    return 0;
}
    
//think about the first block of the output file before the succeeding files