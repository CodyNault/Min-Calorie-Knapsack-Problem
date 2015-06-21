#include <chipotle.h>
#include <iostream>
#include <limits.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

static int menuCount = 0;
static int targetW = 0;
static ItemList *item = NULL;
static MemoList *memo = NULL;
static int *itemCount = NULL;

/*
 * Recursive/Memoized version of mCal, 
 * returns optimal calorie value and updates itemCount array
 */
int mCal(int w)
{
	int curVal = 0;
	int minItem = 0;
	if ( w < 0 ) {
		return INT_MAX;
	}
	if ( w == 0 ) {
		return 0;
	}
	if (memo[w].minCal != -1){
		return memo[w].minCal;
	}
	int minVal = INT_MAX;
	for ( int i = 1; i <= menuCount; i++ ){
		curVal = mCal(w - item[i].costV) + item[i].caloriesC;
		if(curVal < minVal && curVal >= 0){
			minVal = curVal;
			minItem = i;
		}
	}
	memo[w].minCal = minVal;
	memo[w].itemChoice = minItem;
	return minVal;
}

/*
 * Iterative version of mCal, 
 * returns optimal calorie value and updates itemCount array
 */
int mCalIterative(int w)
{
	int minVal = INT_MAX;
	int minItem = -1;
	int curItem = -1;
	int curVal = -1;
	memo[0].minCal = 0;
	for(int i = 1; i <= targetW; i++){
		for (int j = 1; j <= menuCount; j++){
			if (i - item[j].costV < 0 ){
				curVal = -1;
			}
			else if (memo[i - item[j].costV].minCal < 0 ){
				curVal = -1;
			}else{
				curVal = item[j].caloriesC + memo[i - item[j].costV ].minCal;
				curItem = j;
			}
			if(curVal < minVal && curVal > 0){
				minVal = curVal;
				minItem = curItem;
			}
			curVal = -1;
			curItem = -1;
		}
		if(minVal == INT_MAX){
			memo[i].minCal = -1;
		}else{
			memo[i].minCal = minVal;
		}
		memo[i].itemChoice = minItem;
		minVal = INT_MAX;
		minItem = -1;
	}
	return memo[targetW].minCal;
}

/**
 * This updates the ItemCount array, to be called after algorithm has run but before
 * details are to be displayed
 */
void updateItemCount()
{
	int w = targetW;
	if(memo[w].itemChoice == -1){
		cout << "Update Item count failed" << endl;
		return;
	}
	while( w > 0){//Assumes that this was a possible scenario
		itemCount[memo[w].itemChoice]++;
		w = w - item[memo[w].itemChoice].costV;
	}
}

/**
 * This performs initial array setup for memo and itemCount
 */
void initialize()
{
	for(int i = 0; i <= targetW; i++){
		memo[i].minCal = -1;
		memo[i].itemChoice = -1;
	}
	for(int i = 0; i <= menuCount; i++){ //For each menu iterm, 
		itemCount[i] = 0;
	}
}

/**
 * This will run the call the bottom up iteration and perform all output functionality for 
 * additional details
 */
void runIterativeSection()
{
	int minCal = INT_MAX;
	minCal = mCalIterative(targetW);
	cout << "Iterative:" << endl;
	if ( minCal < INT_MAX && minCal != -1){
		cout << "Possible to spend exactly: " << targetW << endl;
		cout << "Minimum calories: " << minCal << endl;
		updateItemCount();
		for(int i = 1; i <= menuCount; i++){//Display included count
			if (itemCount[i] > 0){
				cout << item[i].nameS << " " << itemCount[i] << endl; 
			}
		}
	}
	else{
		cout << "Not possible to spend exactly: " << targetW << endl;
	}
}

/**
 * This will run the call the memoized recursion and perform all output functionality for 
 * additional details
 */
void runMemoizedSection()
{
	int minCal = INT_MAX;
	minCal = mCal(targetW);
	cout << "Memoized:" << endl;
	if ( minCal < INT_MAX){
		cout << "Possible to spend exactly: " << targetW << endl;
		cout << "Minimum calories: " << minCal << endl;
		updateItemCount();
		for(int i = 1; i <= menuCount; i++){//Display included count
			if (itemCount[i] > 0){
				cout << item[i].nameS << " " << itemCount[i] << endl; 
			}
		}
	}
	else{
		cout << "Not possible to spend exactly: " << targetW << endl;
	}
}

/**
 * Main gets the Menu details and taget value, performs setup and calls
 * methods to run algorithms
 */
int main()
{
	//Get setup details from input
	cin >> menuCount >> targetW; 
	//Setup
	item = new ItemList[menuCount + 1];
	itemCount = new int[menuCount + 1];
	memo = new MemoList[targetW + 1];
	initialize();
 	//For each menu item get deatils from input
	for(int i = 1; i <= menuCount; i++){
		cin >> item[i].costV >> item[i].caloriesC >> item[i].nameS;
	}
	//Perform Algorithms
	runIterativeSection();
	initialize();//Reset arrays in preperation for Iterative section
	cout << endl;//break between displays
	runMemoizedSection();
	//Cleanup
	delete[] item;
	delete[] itemCount;
	delete[] memo;
}
