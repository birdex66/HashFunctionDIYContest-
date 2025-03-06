#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash_function(string text,int k,HashSlot* hashTable,int ranges[],int lf) {
	
	int slot=0,i=0;
	//cout << "functionhere0" << endl;
	while(i<text.length()) text[i] = ((int)text[i] > 90) ? text[i] - 32 : text[i], i++; // converts all letters to uppercase 
	int pos = (int)text[0] - 65; 	
	
	//cout << "functionhere1" << endl;

	for(int j=0; j<k; ++j){
		if(pos < ranges[j]){
		   
			if(hashTable[i].length >= lf){
				return -1;
			}else{
				return j;
			}
		
			//cout << "functionhere2" << endl;
			//return j;
		}
	}	
	
	//cout << "functionhere3" << endl;
	return -1;
}

void makeSet(HashSlot* hashTable,string* str,int k,int n,int lf){
	
	int alphasplit = 26/k;
        int alphasplitLast = ceil(26/(k/1.0));

	if(alphasplit <= 0){
                ++alphasplit;
                ++alphasplitLast;
        }

	int ranges[k];

	int alphacpy = alphasplit;
	for(int i=0; i<k-1; ++i){
		ranges[i] = alphacpy;
		alphacpy += alphasplit;
	}
	//cout << "functionhere3" << endl;
	ranges[k] = alphasplitLast+alphacpy;

	for(int i=0; i<n; ++i){
		int slot = hash_function(str[i],k,hashTable,ranges,lf);
		//cout << "functionhere4" << endl;
		if(slot == -1){
			cout << "error finding pref position" << endl;
			continue;
		}
		(hashTable[slot].length)++;

		if(hashTable[slot].value == NULL){
			hashTable[slot].value = new Node{str[i],nullptr};
		}else{
			Node* fer = hashTable[slot].value;
			while(fer->next != nullptr) fer = fer->next;
			fer->next = new Node{str[i],nullptr};
		}
	}
}	

void printSet(HashSlot* hashTable,int k,int n){
	cout<<endl;
	for(int i=0; i<k; ++i){
		cout << "Slot " << i << ": ";
		Node* fer = hashTable[i].value;

		while(fer != nullptr){
			//cout << "clean" << endl;
			cout << fer->data << " ";
			fer = fer->next;
		}	
		cout<<endl;
	}
	return;
}

