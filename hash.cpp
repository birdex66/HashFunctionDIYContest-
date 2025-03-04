#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash_function(string text) {
    // Implement your own hash function here
    return 1;
}

void makeSet(HashSlot* hashTable,string* str,int k,int n,int lf){
	
	for(int i=0; i<k; ++i){
		
		hashTable[i].value = new Node{"0",nullptr};
		Node* fer = hashTable[i].value;
		
		int len = (i+1)*lf;
		for(int j = i*lf; j<len;){
			fer->data = str[j++];
			fer->next = new Node{"0",nullptr};
			fer = fer->next;		
		}
	}	
	return;	
}	

void printSet(HashSlot* hashTable,int k,int n,int lf){
        for(int i=0; i<k; ++i){

                Node* fer = hashTable[i].value;

                int len = (i+1)*lf;
                for(int j = i*lf; j<len; ++j){
                        cout << fer->data << " ";
                        fer = fer->next;
                }
		cout<<endl;
        }
        return;
}
