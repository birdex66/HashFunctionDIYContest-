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
using namespace std;

int main(/*int argc, char** argv*/) {
	


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
	 
	// commented part below is how i did test cases

	/*
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
		int count = 0;
		while(getline(file,line)){
			texts[n] = line;
			++n;
		}
		
		int sum = 0;
		double stdev = 0;
		for(int p=0; p<11; ++p){
			cout << "Number of " << p << ": " << cons[p] << endl;
			sum += cons[p]*p;
		}
		double mean = sum/(n/1.0);
		cout << "mean: " << sum/(n/1.0) << endl; 

		for(int o=0; o<11; ++o){
			stdev += (cons[o])*(pow(o-mean,2));
		}	
		stdev = sqrt(stdev/n);

		cout << "stdev: " << stdev << endl;

		cout << "mean + stdev = " << mean+stdev << endl;	
		cout << "mean - stdev = " << mean-stdev << endl;

		cout << "mean + (3*stdev) = " << mean+(3*stdev) << endl;
		cout << "mean - (3*stdev) = " << mean-(3*stdev) << endl;	
		
		//cout<<"k: " << k << " n: " << n << endl;
		//cout<<"load factor: " << ceil(n/(k/1.0)) << endl;
	}else{
		cerr << "Error opening " << argv[1] << "!" << endl;
		return 2;	
	}
	*/
		HashSlot* hashTable =  new HashSlot[k];
		int lf = (int)ceil(n/(k/1.0));
	
		makeSet(hashTable,texts,k,n,lf);

		//printSet(hashTable,k,n);

	cout << "==== Printing the contents of the first 5 slots ====" << endl;
		printSet(hashTable,k,n);
	cout << "==== Printing the slot lengths ====" << endl;
		getSlotLength(hashTable,k,n);
	cout << "==== Printing the standard variance =====" << endl;
	double mean = 0;
	for(int i=0; i<k; ++i){
		mean += hashTable[i].length;					
	}
	mean /= k;
	double stdev = 0;
	for(int j=0; j<k; ++j){
                stdev += pow(hashTable[j].length-mean,2);
        }
	stdev /= k;
	stdev = sqrt(stdev); 
	cout << stdev << endl;
	return 0;
}


