#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

struct Node{
	string data;
	Node* next;
};

struct HashSlot{
	int key;
	Node* value;
};


int hash_function(string text);
void makeSet(HashSlot* hashTable,string* str,int k,int n,int lf);
void printSet(HashSlot* hashTable,int k,int n,int lf);
#endif
