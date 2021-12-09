/*  Description: ECE 487 Lab 7 - Memory
    Created 16 April 2021
    Modified 22 April 2021
    by Jacob Mader CWID 11824660
    Instructor: Dr.Kenneth Ricks 
    Teaching Assistant: Max Eastepp
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;


class Table2{
public:
	std::vector<int> cacheBlockNum;
	std::vector<int> dirtyBit;
	std::vector<int> validBit;
	std::vector<std::string> tag;
	std::vector<int> data;
	std::vector<int> accessed;
	std::vector<int> entered;
	int accessCount;
	int enterCount;
};

class Table1{
public:
	std::vector<int> memoryAddress;
	std::vector<int> memoryBlock;
	std::vector<int> cacheSet;
	std::vector<std::string> op;
	std::vector<std::string> cmBlock;
	std::vector<std::string> hitStatus;
	std::vector<int> repeatedMemoryBlocks;
	std::vector<int> uniqueMemoryBlocks;
	
};


class Memory{
public:
	int msize;
	int csize;
	int bsize;
	int asize;
	char policy;
	int addressLinesReq;
	int offsetSize;
	int cacheBlocks;
	int cacheSets;
	int indexSize;
	int tagSize;
	int totalCacheSize;
};


int findMemBlock(int memAddress, int blockSz){
	int memBlock = memAddress/blockSz;
	return memBlock;
}

int findCacheSet(int memBlk, int numOfCacheSets){
	int cacheSet = memBlk%numOfCacheSets;
	return cacheSet;
}

string findCacheBlock(int cacheSet, int associativity){
	int start = cacheSet*associativity;
	stringstream ss;
	ss << start;
	string str = ss.str();
	for (int i = 1; i < associativity; i++) {
		int extraBlock = start + i%associativity;
		stringstream s;
		s << extraBlock;
		string extraBlockStr = s.str();
		str.append(" or ");
		str.append(extraBlockStr);
}
	return str;
}

void findBestPossibleHitRate(Table1 &table){
	table.uniqueMemoryBlocks.push_back(table.memoryBlock[0]);
	int matchCount = 0;
		
		for (int i = 1; i < table.memoryAddress.size(); i++) {
			
			
			for (int j = 0; j < table.uniqueMemoryBlocks.size(); j++) {
				
				
				if (table.memoryBlock[i] == table.uniqueMemoryBlocks[j]){
					matchCount++;
				}
			}
			
			if (matchCount == 0){
				table.uniqueMemoryBlocks.push_back(table.memoryBlock[i]);
				}
				
			else{
				table.repeatedMemoryBlocks.push_back(table.memoryBlock[i]);
			}
			matchCount = 0;
		}
	/*cout << "unique memory blocks detected";
	cout << endl;
	for (int i = 0; i < table.uniqueMemoryBlocks.size(); i++) {
		cout << table.uniqueMemoryBlocks[i];
		cout << endl;
}
cout << "repeated memory blocks detected";
	cout << endl;
	for (int i = 0; i < table.repeatedMemoryBlocks.size(); i++) {
		cout << table.repeatedMemoryBlocks[i];
		cout << endl;
}*/
 int numerator = table.repeatedMemoryBlocks.size();
 int denominator = table.memoryAddress.size();
 
 
 cout << "Best possible hit rate:" << numerator << "/" << denominator;
 cout << endl;
 
}

void findActualHitRate(Table1 &table){
	int numerator = 0;
	int denominator = table.memoryAddress.size();
	for (int i = 0; i < table.memoryAddress.size(); i++) {
		string status = "Hit";
		if (table.hitStatus[i] == status){
			numerator++;
		}
}
 
 
 cout << "Actual hit rate:" << numerator << "/" << denominator;
 cout << endl;
 
}

string findTag(Memory main, Table1 table, int pos ){
	int denominator = 1;
	int numerator = 0;
	string tag = "";
	for (int i = 0; i < main.tagSize; i++){
		denominator = denominator*2;
		numerator = table.memoryAddress[pos];
		int tagNumerator = numerator/denominator;
		int tagFlag = tagNumerator%2;
		if (tagFlag == 1){
			tag.append("1");
		}
		else{
			tag.append("0");
		}
	}
	return tag;
}

/*string findHitStatus(Memory main, Table1 &table, Table2 table2, int pos){
	return "Hit";
}*/

string findHitStatus(Memory main, Table1 &table, Table2 table2, int pos){
	string checkTag = findTag(main, table, pos);
	if (table2.validBit[pos] == 0){
		return "Miss";
	}
	else if(checkTag != table2.tag[pos]){
		return "Miss";
	}
	return "Hit"; // 0 = miss
			  // 1 = hit
}


void findTable1(Memory main, Table1 &table, Table2 table2){
	//cout << "test3";
	//cout << endl;
	for (int i = 0; i < table.memoryAddress.size(); i++) {
	//	cout << "test3." << i;
	//	cout << endl;
		table.memoryBlock.push_back(findMemBlock(table.memoryAddress[i],main.bsize));
		table.cacheSet.push_back(findCacheSet(table.memoryBlock[i],main.cacheSets));
		table.cmBlock.push_back(findCacheBlock(table.cacheSet[i], main.asize));
		table.hitStatus.push_back(findHitStatus(main,table,table2, i ));
}
//cout << "test4";
//cout << endl;
}


void printTable1(Table1 table){
	using std::setw;
	std::cout << std::left;
	std::cout <<
    	setw(20) << "main memory address" << setw(20) << "mm blk# " << setw(20)
			<< "cm set# " << setw(20) << "cm blk# "<< setw(20) << "hit/miss"<< '\n';
		for (int i = 0; i < table.memoryAddress.size(); i++) {
			cout << setw(20) << table.memoryAddress[i] 
			<< setw(20) << table.memoryBlock[i]
			<< setw(20) << table.cacheSet[i]
			<< setw(20) << table.cmBlock[i]
			<< setw(20) << table.hitStatus[i] << '\n';
		}
}

void fillTable2(Memory main, Table2 &table){
	//cout << "test1";
	//cout << endl;
	for (int i = 0; i < main.cacheBlocks; i++) {
		table.cacheBlockNum.push_back(i);
		table.dirtyBit.push_back(0);
		table.validBit.push_back(0);
		table.accessed.push_back(-1);
		table.entered.push_back(-1);\
		table.accessCount = 0;
		table.enterCount = 0;
		string str = "";
		for (int i = 0; i < main.tagSize; i++){
			str.append("X"); 
		}
		table.tag.push_back(str);
		
		table.data.push_back(0);
}
	
}

int findDirtyBit(Table1 table, int pos){
	if (table.op[pos] == "W"){
		return 1;
	}
	return 0;
}

void fillCacheBlock(Memory main, Table2 &table2, Table1 &table1, int pos){
	int i = 0;
	int control = 0;
	while(i < main.asize && control == 0 ){
	if (table2.validBit[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] == 1){
				i++;
				if (table2.tag[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] == findTag(main, table1, pos)){
					string status = "Hit";
					table1.hitStatus[pos] = status;
					cout << "we got a hit!";
					cout << endl;
					cout << "at access " << pos << " we have a " << table1.hitStatus[pos];
					cout << endl;
					
					return;
				}
			}
	else if (table2.validBit[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] == 0){
		table2.dirtyBit[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] = findDirtyBit(table1, pos );
		table2.validBit[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] = 1;
		table2.tag[(table1.memoryBlock[pos] % main.cacheSets*main.asize) + i] = findTag(main, table1, pos);
		table2.data[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] = table1.memoryBlock[pos];
		table2.accessed[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] = table2.accessCount;
		table2.accessCount++;
		control = 1;
		}
}
	if (i == main.asize){
		/*cout << "replacement needed";
		cout << endl;
		cout << "replacement policy used: " << main.policy;
		cout << endl;*/
		if (main.policy = 'L'){
			int accessTime1 = table2.accessed[0];
			int accessTimePos = 0;
			for (int j = 0; j < main.asize; j++) {
				int accessTime2 = table2.accessed[j];
				if(accessTime2 < accessTime1 ){
					accessTime1 = accessTime2;
					accessTimePos = j;
				}
		}
		table2.dirtyBit[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + accessTimePos] = findDirtyBit(table1, pos );
		table2.validBit[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + accessTimePos] = 1;
		table2.tag[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + accessTimePos] = findTag(main, table1,pos);
		table2.data[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + accessTimePos] = table1.memoryBlock[pos];
		table2.accessed[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] = table2.accessCount;
		table2.entered[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] = table2.enterCount;
		table2.accessCount++;
		table2.enterCount++;
		control = 1;
	}
		if (main.policy = 'F'){
			int enterTime1 = table2.entered[0];
			int enterTimePos = 0;
			for (int j = 0; j < main.asize; j++) {
				int enterTime2 = table2.entered[j];
				if(enterTime2 < enterTime1 ){
					enterTime1 = enterTime2;
					enterTimePos = j;
				}
		}
		table2.dirtyBit[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + enterTimePos] = findDirtyBit(table1, pos );
		table2.validBit[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + enterTimePos] = 1;
		table2.tag[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + enterTimePos] = findTag(main, table1, pos);
		table2.data[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + enterTimePos] = table1.memoryBlock[pos];
		table2.accessed[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] = table2.accessCount;
		table2.entered[(table1.memoryBlock[pos] % main.cacheSets)*main.asize + i] = table2.enterCount;
		table2.accessCount++;
		table2.enterCount++;
		control = 1;
	}
}
}

void findTable2(Memory main, Table2 &table2, Table1 &table1){
	for (int a = 0; a < table1.memoryBlock.size(); a++){
		fillCacheBlock(main, table2, table1, a);
}
	
	
	
	
	/*int cacheSetFillCount = 0;
	int cacheSetOffset = 0;
	int loopFlag = 0;
	int loopcounter = 0;
	for (int i = 0; i < table1.memoryBlock.size(); i++) {
		while (loopcounter < main.asize && loopFlag == 0) {
			
			if (table2.validBit[(table1.memoryBlock[i] % main.cacheSets) + loopcounter] == 1){
				cacheSetFillCount++;
			}
			else{
				cacheSetOffset = loopcounter;
				loopFlag = 1;
			}
			loopcounter++;
		}
		if (cacheSetFillCount == main.asize){
			int accessTime1 = table2.accessed[(table1.memoryBlock[i] % main.cacheSets)];
			int pos = 0;
			for (int j = 0; j < main.asize; j++){
				int accessTime2 = table2.accessed[(table1.memoryBlock[i] % main.cacheSets) + j];
				if ( accessTime2 < table2.accessed[(table1.memoryBlock[i] % main.cacheSets) + pos]){
					pos = j;
				}
				cacheSetOffset = pos;
			}
		}
		
		table2.dirtyBit[(table1.memoryBlock[i] % main.cacheSets) + cacheSetOffset] = findDirtyBit(table1, i );
		table2.validBit[(table1.memoryBlock[i] % main.cacheSets) + cacheSetOffset] = 1;
		
		table2.tag[(table1.memoryBlock[i] % main.cacheSets) + cacheSetOffset] = findTag(main, table1, i);
		
		table2.data[(table1.memoryBlock[i] % main.cacheSets) + cacheSetOffset] = table1.memoryBlock[i];
		table2.entered[(table1.memoryBlock[i] % main.cacheSets) + cacheSetOffset] = i;
		table2.accessed[(table1.memoryBlock[i] % main.cacheSets) + cacheSetOffset] = i;
}*/
	
}

void printTable2(Table2 table){
	using std::setw;
	std::cout << std::left;
	std::cout <<
    	setw(20) << "Cache Block #" << setw(20) << "Valid Bit" << setw(20) << "Dirty Bit" << setw(20)
			<< "Tag" << setw(20) << "Data"<< '\n';
		for (int i = 0; i < table.cacheBlockNum.size(); i++) {
			cout << setw(20) << table.cacheBlockNum[i] 
			<< setw(20) << table.validBit[i]
			<< setw(20) << table.dirtyBit[i]
			<< setw(20) << table.tag[i]
			<< setw(20) << table.data[i] << '\n';
		}
}


int main(){
	
	using namespace std;
	
	// create memory object
	Memory mainm;
	
	// create table1 object
	Table1 table;
	
	// create table2/cache memory object
	Table2 table2;
	
	cout << "This is my memory simulator";
	cout << endl;
	cout << "It implements a two-level hierachy and set-associative cache mapping.";
	cout << endl;
	cout << "In order to support various set assosciativities, that characteristics is held in a string called associativityType";
	cout << endl;
	cout << "In order to support various  replacement policies that characteristics is held in a string called replacementPolicy";
	cout << endl;
	cout << "options include LRU, FIFO, and Random";
	cout << endl;
	cout << "In order to support various  write policies that characteristic is held in a string called writePolicy";
	cout << endl;
	cout << "parameters are prompted from the user and read from a file supplied by the user";
	cout << endl;
	cout << "system computations include the number of address lines required";
	cout << "the size of the offset field of memory addresses,";
	cout << endl;
	cout << "the size of the index field of memory addresses,";
	cout << endl;
	cout << "the size of the tag field of memory addresses,";
	cout << endl;
	cout << "the total size of the cache memory,";
	cout << endl;
	
	cout << "a table showing the important values";
	cout << endl;
	//to do
	
	cout << "the highest possible hit rate for a given sequence of references"	;
	cout << endl;
	int bestPossibleHitRate = -1;
	
	cout << "the actual hit rate for the same sequence of references";
	cout << endl;
	int actualHitRate= -1;
	cout << "and a table showing the final status of the cache memory";
	cout << endl;
	cout << "users should be prompted about whether to continue with analysis of memory or exit after runs";
	cout << endl;
	cout << "Enter the size of main memory in bytes:";
	cin >> mainm.msize;
	cout << endl;
	cout << "Entered value read as:"<< mainm.msize;
	cout << endl;
	cout << "Enter the size of the cache in bytes:";
	cin >> mainm.csize;
	cout << endl;
	cout << "Entered value read as: "<< mainm.csize;
	cout << endl;
	cout << "Enter the cache block/line size:";
	cin >> mainm.bsize;
	cout << endl;
	cout << "Entered value read as:  "<< mainm.bsize;
	cout << endl;
	
	
	
	cout << "Enter degree of set-assosciativity (input n for a n-way set associative mapping):";
	cin >> mainm.asize;
	cout << endl;
	cout << "Entered value read as:  "<< mainm.asize;
	cout << endl;

	cout << "Enter the replacement policy (L = LRU, F = FIFO):";
	cin >> mainm.policy;
	cout << endl;
	cout << "Entered value read as:  "<< mainm.policy;
	cout << endl;
	
	string fileName = "dummy.txt";
	cout << "Enter the name of the input file containing the list of memory references generated by the CPU:";
	cin	>> fileName;
	cout << endl;
	cout << "Entered value read as:  "<< fileName;
	cout << endl;
	
	//calculate total addresslines needed
	
	mainm.addressLinesReq = log2(mainm.msize);
	cout << "Total address lines required = "<< mainm.addressLinesReq;
	cout << endl;
	
	//calculate offset bits needed
	
	mainm.offsetSize = log2(mainm.bsize);
	cout << "Number of bits for offset = "<<mainm.offsetSize;
	cout << endl;
	
	//calculate index bits needed

	mainm.cacheBlocks = mainm.csize/mainm.bsize;
	mainm.cacheSets = mainm.cacheBlocks/mainm.asize;
	mainm.indexSize= log2(mainm.cacheSets);
	cout << "Number of bits for index = " << mainm.indexSize;
	cout << endl;
	
	//calculate tag bits needed
	
	mainm.tagSize= mainm.addressLinesReq-mainm.offsetSize-mainm.indexSize;
	cout << "Number of bits for tag = " << mainm.tagSize;
	cout << endl;
	
	//calculate total cache size required (valid bit*preCacheSetSz + dirtybit*preCacheSetSz+tagbits*preCacheSetSz+preCacheSetSz*CacheSize
	mainm.totalCacheSize = ((2 + mainm.tagSize)*mainm.cacheBlocks)/8 + mainm.csize;
	cout << "Total cache size required = " << mainm.totalCacheSize << " bytes";
	cout << endl;
	
	
	
	
	
	ifstream  inFile;
	inFile.open(fileName.c_str());
	int memAccesses;
	inFile >> memAccesses;
	int memoryAddresses[memAccesses];
	string readWriteOp[memAccesses];
	string carriage;
	inFile >> carriage;
	for (int i = 0; i < memAccesses; i++) {
	inFile >> readWriteOp[i];
	inFile >> memoryAddresses[i];
}
	inFile.close();
	
	//cout << "test2";
	//cout << endl;

	for (int i = 0; i < memAccesses; i++) {
		int memAddress;
		string opchar;
		memAddress = memoryAddresses[i];
		opchar = readWriteOp[i];
		table.memoryAddress.push_back(memAddress);
		table.op.push_back(opchar);
		cout << table.memoryAddress[i];
		cout << table.op[i];
		cout << endl;
		
	}
	//cout << "test1";
	//cout << endl;
	
	fillTable2(mainm, table2);
	
	findTable1(mainm, table, table2);
	//cout << "Test test";
	findTable2(mainm, table2, table);
	
	printTable1(table);
	
	findBestPossibleHitRate(table);
	findActualHitRate(table);
	
	cout << endl;
	//fillTable2(mainm, table2);
	
	//findTable2(mainm, table2, table);
	
	//printTable1(table);
	printTable2(table2);
	
char conttype = 'x';	
	cout << "Continue? (y = yes, n = no):";
	cin >> conttype;
	cout << endl;
	
	if (conttype == 'y'){
		int x = main();
	}
	else{
		return 0;
	}
	
	
	system("pause");
	
	return 0;













}
	
	
	
	
	
	
	
	
	
	
	
