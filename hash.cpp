#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int findConsonants(string str){
	int sum=0,i=0,j=0;
	while(i<str.length()) str[i] = ((int)str[i] > 90) ? str[i] - 32 : str[i], i++;
	while(j<str.length()) sum += !(str[j] == 'A' ||  str[j] == 'E' ||  str[j] == 'I' ||  str[j] == 'O' ||  str[j] == 'U') ? 1:0,j++;
	//	cout << str << " cons: " << sum << endl;
	return sum;
}

double getMean(const int* cons,const int n){
	int sum = 0;

	for(int i=0; i<11; ++i){
		//cout << "Number of " << i << ": " << cons[i] << endl;
		sum += cons[i]*i;
	}

	double mean = sum/(n/1.0);
	//cout << "mean: " << sum/(n/1.0f) << endl;
	return mean;
}
double getStdev(const int* cons,const double mean,const int n){
	double stdev = 0;
	for(int i=0; i<11; ++i){

		stdev += (cons[i])*(float)(pow(i-mean,2));
	}
	stdev = (float)sqrt(stdev/n);
	//cout << "stdev: " << stdev << endl;
	return stdev;
}


int hash_functionLessThirty(const string text,const int k){ // if n<30(not eligible to be a normal distribution) go here
	int sum=0,i=0;	
	while(i<2) sum += (int)text[i],++i; //allows some level of variance without bias for longer words
	return sum%k;
}

int hash_function(const int strIndex,const int* textCons,const int q1,const int q3){
	int fer = textCons[strIndex];

	if(fer >= q1 && fer <= q3) return 2;
	else{
		if(fer < q1) return 1;
		else return 3;
	}	

}

void makeSet(HashSlot* hashTable,const string* str,const int k,const int n,const int lf){
	int cons[11] = {0};                                                                                                                                                                                                                          int textCons[500];	
//	if(n>=30){
		for(int i=0; i<n; ++i){
			int res = findConsonants(str[i]); 
			textCons[i] = res;
			cons[res] = cons[res] + 1;	
		}
		double mean =  getMean(cons,n);
		double stdev = getStdev(cons,mean,n);

		int q3 = (int)(mean+stdev);
		int q1 = (int)ceil(mean-stdev);


		double middleSlot = 0.68/((100.0/k)*0.01);
		int outliers = (int)((k-middleSlot)/2);
		//cout << "middleSlot: " << middleSlot << "\n (int)((0.6827 * n)/middleSlot) = " << (int)((0.6827 * n)/middleSlot) <<  endl;
		//cout << "outliers: " << outliers << "\n (int)((0.3146 * n)/outliers) = " << (int)(0.3146 * n)/outliers <<   endl;


		//cout << "Slots reserved between q1 and q3: " <<  outliers << " - " <<  middleSlot+outliers-1 << endl;
		//cout  << "Slots reserved before q1: 0 - " << outliers-1 << endl;
		//cout << "Slots reserved after q3: " << middleSlot+outliers << " - " <<  k-1 <<endl;

		int countOne=0,countTwo=0,countThree=0,elementcount=0;
		for(int j=0; j<n; ++j){
			int pos = hash_function(j,textCons,q1,q3);	
			int slot=0,availLen=0;
			switch(pos){
				case 2:
					slot=outliers;
					availLen = (int)(middleSlot)+outliers;
					++countTwo;
					break;
				case 1: 
					slot=0;
					availLen = outliers-1;
					++countOne;
					break;
				case 3:
					slot = (int)(middleSlot+outliers);
					availLen = k-1;
					++countThree;
					break;
			}
			  // cout << "j: " << str[j] << ", slot: " << slot << ", availLen: " << availLen << endl;
			//cout << "Count Ones: " << countOne << "\nCount Twos: " << countTwo << "\nCount Threes: " << countThree << "\nTotal Elements: " << elementcount <<  endl;
			if( (countTwo > (int)(0.6827*n)) || ((countOne*1.0) > (int)(0.15865*n)) || ((countThree*1.0) > (int)(0.15865*n)) ){ //if quartiles are full, will add over entire list and will still be inorder
				slot = 0;
			}	availLen = k-1;

			for(; slot <= availLen; ++slot){
				if(hashTable[slot].length >= lf /*|| hashTable[slot].length >= targetdistribution*/){
					continue;
				}else if(hashTable[slot].value == NULL){
					hashTable[slot].value = new Node{str[j],nullptr};
					//cout << hashTable[slot].value->data << endl;
					hashTable[slot].length = 1;
					++elementcount;
					break;
				}else{
					Node* fer = hashTable[slot].value;
					while(fer->next != nullptr) fer = fer->next;
					(hashTable[slot].length)++;
					fer->next = new Node{str[j],nullptr};
					++elementcount;
					//cout << fer->next->data << endl;
					break;
				}
			}
		}
		//cout << "Count Ones: " << countOne << "\nCount Twos: " << countTwo << "\nCount Threes: " << countThree << "\nTotal Elements: " << elementcount <<  endl; 
		//cout << stdev << " stdev" << endl;
}	

void getSlotLength(HashSlot* hashTable,int k,int n){
	int sum = 0;
        for(int i=0; i<k; ++i){
                cout << "Slot " << i << ": " << hashTable[i].length << endl;
        }
} 

void printSet(HashSlot* hashTable,int k,int n){
	//int sum = 0;
	for(int i=0; i<k; ++i){
		cout << "Slot " << i << ": ";
		Node* fer = hashTable[i].value;
		while(fer != nullptr){
			//cout << "clean" << endl;
			cout << fer->data << " ";
			fer = fer->next;
		}
		cout<<endl;
		//cout<< " (" << hashTable[i].length << ")" << endl;
		//sum += hashTable[i].length;
	}
//	cout << "total elements: " << sum << endl;
}

/*
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
//int slot = hash_function(str[i],k,hashTable,ranges,lf);
int slot = hash_function(str[i],k,ranges,lf);
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
int hash_function(string text,int k,HashSlot* hashTable,int lf) {

int slot=0,i=0;
//cout << "functionhere0" << endl;
while(i<text.length()) text[i] = ((int)text[i] > 90) ? text[i] - 32 : text[i], i++; // converts all letters to uppercase
int pos = (int)text[0] - 65;
int hash = 0;

//cout << "functionhere1" << endl;
for(char c : text){
hash = (hash+(c-'A'+1)
}


for(int j=0; j<k; ++j){
if(pos < ranges[j]){
if(pos < ranges[j]) return j;
//cout << "functionhere2" << endl;
}
}


//cout << "functionhere3" << endl;
return -1;
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
*/
