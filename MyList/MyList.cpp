#include "CNode.h"
#include "MyList.h"

void sort(CNode** pFirst) {	
	if ((*pFirst) == NULL)
		throw std::exception("can't sort empty list");
	if ((*pFirst)->next == NULL)
		return;
	if ((*pFirst)->next->next == NULL) {
		if ((*pFirst)->val > (*pFirst)->next->val) {
			CNode *tmp = (*pFirst)->next;
			(*pFirst)->next->next = (*pFirst);
			(*pFirst)->next = NULL;
			(*pFirst) = tmp;
		}
		return;
	}
	CNode *tmp;
	int f = 0;
	while (f == 0) {
		f = 1;
		tmp = (*pFirst);
		if (tmp->val > tmp->next->val) {
			f = 0;
			CNode *tmp2 = (*pFirst)->next;
			CNode *tmp3 = (*pFirst)->next->next;
			(*pFirst)->next->next = (*pFirst);
			(*pFirst)->next = tmp3;
			(*pFirst) = tmp2;
		}
		while (tmp->next->next != NULL) {
			if (tmp->next->val > tmp->next->next->val) {
				CNode *tmp1, *tmp2, *tmp3;
				f = 0;
				tmp1 = tmp->next;
				tmp2 = tmp->next->next;
				tmp3 = tmp->next->next->next;
				tmp2->next = tmp1;
				tmp1->next = tmp3;
				tmp->next = tmp2;
			}
			tmp = tmp->next;
		}
	}
}

bool myCompare(CNode* pFirst, CNode* pFirst1) {
	while ((pFirst->next != NULL) && (pFirst1->next != NULL)) {
		if (pFirst->val != pFirst1->val) 
			return false;
		pFirst = pFirst->next;
		pFirst1 = pFirst1->next;			
	}
	return true;
}

CNode* CreateList(int count, const int* vals) {
  if (count <= 0) return 0;
  CNode *head = new CNode;
  head->val = vals[0];
  CNode *prev = head;
  for (int i = 1; i < count; ++i) {
    CNode *node = new CNode;
    node->val = vals[i];
    prev->next = node;
    prev = node;
  }
  prev->next = 0;
  return head;
}

void merge(CNode** pFirst, CNode* pFirst1, int j) {
	if (j < 0)
		throw std::exception("wrong index");
	if (*pFirst == NULL) {
		*pFirst = pFirst1;
		return;
	}
	if (pFirst1 == NULL) 
		return;
	CNode *tmp1 = *pFirst;
	int k = 0;
	while (tmp1 != NULL) {
		if (k == j) {
			CNode* tmp;
			tmp = tmp1->next;
			tmp1->next = pFirst1;
			while (pFirst1->next != NULL) {
				pFirst1 = pFirst1->next;
			}
			pFirst1->next = tmp;
			return;
		} 
		k++;
		tmp1 = tmp1->next;
    }
if (j > k)
	throw std::exception("wrong index");
}
