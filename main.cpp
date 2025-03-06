/*
   CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s):
Your team alias: 
*/

#include <iostream>
#include <iomanip>
#include <string>

#include <fstream>

#include "hash.h"
#include "hash.cpp"
using namespace std;

int main(int argc, char** argv) {
	/*


	   int k = 0;
	   int n = 0;
	   string texts[500];

	// WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
	cin >> k;
	string line;
	getline(cin, line);

	while (getline(cin, line)) {
	texts[n] = line;
	n++;
	}
	// WARNING: End of the tokenizer, DO NOT change this part!

	// By this point, k is the # of slots, and n is the # of tokens to fit in
	// texts[] stores the input sequence of tokens/keys to be inserted into your hash table

	// The template is able to be compiled by running 
	//   make
	//   ./encoder < inputs/sample_input.txt
	// which puts out the placeholders only.

	// Your time to shine starts now
	*/

	if(argc < 2){
		cerr << "Must specify an input file!!" << endl;
		return 1;
	}

	ifstream file;
	string line;

	int k = 0;
	int n = 0;
	string texts[500];


	file.open(argv[1]);


	if(file.is_open()){
		cout<<endl;
		getline(file,line);

		k = stoi(line);

		while(getline(file,line)){
			//cout << line << " ";
			texts[n] = line; 
			++n;
		}
		cout<<"k: " << k << " n: " << n << endl;
		cout<<"load factor: " << ceil(n/(k/1.0)) << endl;
	}else{
		cerr << "Error opening " << argv[1] << "!" << endl;
		return 2;	
	}

	
	HashSlot* hashTable =  new HashSlot[k];
	int lf = (int)ceil(n/(k/1.0));

	makeSet(hashTable,texts,k,n,lf);

	printSet(hashTable,k,n);

	//cout << "==== Printing the contents of the first 5 slots ====" << endl;

	//cout << "==== Printing the slot lengths ====" << endl;

	//cout << "==== Printing the standard variance =====" << endl;

	return 0;
}
