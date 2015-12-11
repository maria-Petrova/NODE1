#ifndef GTEST_MYLIST_MYLIST_H
#define GTEST_MYLIST_MYLIST_H

#include "CNode.h"
#include <iostream> 
CNode* CreateList(int count, const int* vals);
void merge(CNode** pFirst, CNode* pFirst1, int j, int n);
bool myCompare(CNode* pFirst, CNode* pFirst1);
void print (CNode* pFirst) {
    while(pFirst != NULL) {
        std::cout << pFirst->val << std::endl;
        pFirst = pFirst->next;
    }
}
void sort(CNode* pFirst);

class List {
private:
   void DelFreeNode(int i);
   void AddNewNode(int i, int j);
public:
	double *data;
	int *index;
	int prev;
	int current;
	List(int n);
	~List();
	void Movenext();
	void print();
	void Add(double l);
	void Del();
	void Merge(List list, int j);
};

#endif  // GTEST_MYLIST_MYLIST_H
