#ifndef CHIPOTLE_H
#define CHIPOTLE_H
#include <string>
typedef struct MemoList{
	int minCal;
	int itemChoice;
}MemoList;

typedef struct ItemList{
        int costV;
        int caloriesC;
        std::string nameS;
}ItemList;
#endif
