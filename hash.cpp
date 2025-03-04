#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash_function(string text) {
    // Implement your own hash function here
    return 1;
}

void makeSet(HashSlot* hashTable,int k,int n){
	hashTable = new HashSlot[k];

	for(int i=0; i<k;++i){
		hashTable[i].key = i;
	       cout << "index " <<  hashTable[i].key << endl;	
	}
}	
