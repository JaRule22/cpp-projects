#include "Node.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

void serializeInt(void* i) {
	ofstream fout("out\\ints.bin", ios::binary | ios::app);
	if (fout.is_open())
	{
		int *p = (int *)(i);
		int n = *p;
		cout << "Serializing" << n << endl;
		fout.write(reinterpret_cast<char*>(&n), sizeof(int));
		fout.close();
	}
}

void displayInt(void* i) {
	int* p = (int*)(i);
	int n = *p;
	cout << n << "->";
}
void displayStr(void* i) {
	char* p = (char *)(i);
	cout << p << "->";
}
////from Learn by Doing Chapter 12, slide 105
int compare_ints(void* arg1, void* arg2)  
{
	int return_value = 0;

	if (*(int*)arg1 < *(int*)arg2)
		return_value = -1;
	else if (*(int*)arg1 > *(int*)arg2)
		return_value = 1;

	return return_value;
}

int compare_strs(void* arg1, void* arg2){
	return (_stricmp(((char*)arg1), ((char*)arg2)));
}
//end attribution to Learn by Doing slides

void serializeStr(void* i) {
	ofstream fout("out\\animals.bin", ios::binary | ios::app);
	if (fout.is_open()){
		char * p = (char *)(i);
		int n = strlen(p);
		fout.write(reinterpret_cast<char*>(&n), sizeof(n));
		fout.write(p, n);
		fout.close();
	}
}

LinkedList* deserializeInts() {
	ifstream fin("out\\ints.bin", ios::in | ios::binary);
	LinkedList * myList = new LinkedList;
	int n;
	if (fin.is_open()){
		while (!fin.eof()) {
			fin.read(reinterpret_cast<char*>(&n), sizeof(int));
			// myList->appendNode(new int(n));
			cout << "Deserializing" << n << endl;
		}
		fin.close();
	}
	return myList;
}

LinkedList* deserializeString() {
	ifstream fin("out\\animals.bin", ios::in | ios::binary);
	LinkedList * myList = new LinkedList;
	if (fin.is_open())
	{
		while (!fin.eof()) {
			int n;
			fin.read(reinterpret_cast<char*>(&n), sizeof(n));
			char* p = new char[n + 1];
			fin.read(p, n);
			p[n] = '\0';
			myList->appendNode(p);
		}
		fin.close();
	}
	return myList;
}

int main() {
	int num2 = 2;
	int* pnum2 = &num2;
	int num1 = 1;
	int* pnum1 = &num1;
	int num3 = 3;
	int* pnum3 = &num3;
	LinkedList * nums = new LinkedList();
	nums->insert(pnum3, compare_ints);
	nums->insert(pnum1, compare_ints);
	nums->insert(pnum2, compare_ints);
	nums->setDisplay(displayInt);
	// nums->setSerialize(serializeInt);
	// nums->serialize();
	nums->display();
	char cat[4]= "cat";
	char dog[4] = "dog";
	char bird[5] = "bird";
	LinkedList* animals = new LinkedList();
	animals->insert(&dog[0], compare_strs);
	animals->insert(&bird[0], compare_strs);
	animals->insert(&cat[0], compare_strs);
	animals->setDisplay(displayStr);
	// animals->setSerialize(serializeStr);
	animals->display();
	// animals->serialize();
	cout << "Hello" << endl;

	LinkedList* deserializedNums = deserializeInts();
	// deserializedNums->setDisplay(displayInt);
	deserializedNums->display();

	LinkedList* deserializedAnimals = deserializeString();
	// deserializedAnimals->setDisplay(displayStr);
	deserializedAnimals->display();
}

