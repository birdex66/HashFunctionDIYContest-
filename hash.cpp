#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash_function(string text,int k) {

	int slot  = (text.length()-1) % k;
	cout << text << ": " << slot << endl;
	return slot;
}

void makeSet(HashSlot* hashTable,string* str,int k,int n,int lf){

	/*
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
	   */

	for(int i=0; i<n; ++i){
		int slot = hash_function(str[i],k);
			//cout << "slot:" << slot << " " <<  str[i] << endl;

		if(hashTable[slot].value == NULL){
			hashTable[slot].value = new Node{str[i],nullptr};
		}else{
			Node* fer = hashTable[slot].value;
			//int len = (slot+1)*lf;
			while(fer->next != nullptr) fer = fer->next;
			fer->next = new Node{str[i],nullptr};
		}
	}
}	

void printSet(HashSlot* hashTable,int k,int n,int lf){
	cout<<endl;
	for(int i=0; i<k; ++i){
		cout << "Slot " << i << ": ";
		Node* fer = hashTable[i].value;
		
		/*
		int len = (i+1)*lf;
		for(int j = i*lf; j<len; ++j){
			if(fer == NULL) break;
			cout << fer->data << " ";
			fer = fer->next;
		}
		cout<<endl;
		*/

		while(fer != nullptr){
			//cout << "clean" << endl;
			cout << fer->data << " ";
			fer = fer->next;
		}	
		cout<<endl;
	}
	return;
}
