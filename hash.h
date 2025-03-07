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

int findConsonants(string str);
double getMean(const int* cons,const int n);
double getStdev(const int* cons,const double mean,const int n);
int hash_functionLessThirty(HashSlot* hashTable,const string text,const int k,const int lf);
int hash_function(const int strIndex,const int* textCons,const int q1,const int q3);
void makeSet(HashSlot* hashTable,const string* str,const int k,const int n,const int lf);
void getSlotLength(HashSlot* hashTable,int k,int n);
void printSet(HashSlot* hashTable,int k,int n);
/*
int printConsonants(string str);
int printVowels(string str);
int hash_function(string text, int k, int ranges[], int lf);
void makeSet(HashSlot* hashTable,string* str,int k,int n,int lf);
void printSet(HashSlot* hashTable,int k,int n);
*/
#endif
