#include "CNode.h"
#include "MyList.h"

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

void merge(CNode** pFirst, CNode* pFirst1, int j, int n) {
	if ((j < 0) || (j > n))
		throw std::exception("wrong index");
	if (*pFirst == NULL) {
		*pFirst = pFirst1;
		return;
	}
	if (pFirst1 == NULL) 
		throw std::exception("empty List");
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
			exit;
		} 
		k++;
		tmp1 = tmp1->next;
    }
}
