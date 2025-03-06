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
	int length;
	int key;
	Node* value;
};

/*
class LinkedList{
	public:
		LinkedList(int length,Node* head);
		int getLength(){return length;}
	private:
		int length;
                Node* head;

};
*/
int hash_function(string text,int k,HashSlot* hashTable,int ranges[],int lf);
void makeSet(HashSlot* hashTable,string* str,int k,int n,int lf);
void printSet(HashSlot* hashTable,int k,int n);
#endif
