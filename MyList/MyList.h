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
#endif  // GTEST_MYLIST_MYLIST_H
