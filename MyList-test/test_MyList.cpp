#include "MyList.h"
#include "MyList.cpp"
#include <gtest.h>

TEST(testList, CreateEmptyList) {
  CNode *head = CreateList(0, 0);
  CNode *expected_head = 0;
  EXPECT_EQ(expected_head, head);
}

TEST(testList, CreateList) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);

  int k = 0;
  while (head != 0) {
    EXPECT_EQ(vals[k], head->val);
    head = head->next;
    ++k;
  }
  EXPECT_EQ(kListSize, k);
}

TEST(testList, mergetest) {
	const int kListSize1 = 5;
	int vals1[kListSize1];
	for (int i = 0; i < kListSize1; i++)
		vals1[i] = i + 5;
	CNode *Head = CreateList(kListSize1, vals1);
	const int kListSize2 =10;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i + 5;
	CNode *Head1 = CreateList(kListSize2, vals2);
	int j = 2;
	ASSERT_NO_THROW(merge(&Head,Head1,j));
}

TEST(testList, mergetest_wrong_index) {
	const int kListSize1 = 5;
	int vals1[kListSize1];
	for (int i = 0; i < kListSize1; i++)
		vals1[i] = i + 5;
	CNode *Head = CreateList(kListSize1, vals1);
	const int kListSize2 =10;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i + 5;
	CNode *Head1 = CreateList(kListSize2, vals2);
	int j = 20;
	ASSERT_ANY_THROW(merge(&Head,Head1,j));
}

TEST(testList, can_merge) {
	const int kListSize1 = 5;
	int vals1[kListSize1];
	for (int i = 0; i < kListSize1; i++)
		vals1[i] = i + 1;
	CNode *Head = CreateList(kListSize1, vals1);
	const int kListSize2 = 10;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i + 10;
	CNode *Head1 = CreateList(kListSize2, vals2);
	int j = 2;

	const int kListSize3 = kListSize1 + kListSize2;
	int vals3[kListSize3];
	for (int i = 0; i < 3; i++)
		vals3[i] = i + 1;
	for (int i = 3; i < 3 + kListSize2; i++)
		vals3[i] = i + 10 - 3;
	for (int i = 3 + kListSize2; i < kListSize3; i++)
		vals3[i] = i + 1 - kListSize2;
	CNode *Head3 = CreateList(kListSize3, vals3);
	print(Head3);
	std::cout<<std::endl;
	merge(&Head, Head1, j);
	print(Head);
	EXPECT_EQ(true, myCompare(Head, Head3));
}

TEST(testList, can_merge_with_emptyList) {
	const int kListSize1 = 5;
	int vals1[kListSize1];
	for (int i = 0; i < kListSize1; i++)
		vals1[i] = i + 1;
	CNode *Head = CreateList(kListSize1, vals1);
	int j = 2;
	CNode* Head1 = NULL;
	const int kListSize2 = 5;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i + 1;
	CNode *Head2 = CreateList(kListSize2, vals2);
	merge(&Head,Head1,j);
	EXPECT_EQ(true, myCompare(Head, Head2));
}

TEST(testList, can_merge_empty_list) {
	
	CNode *Head = NULL;
	const int kListSize2 = 10;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i + 10;
	CNode *Head1 = CreateList(kListSize2, vals2);
	int j = 2;

	const int kListSize3 = kListSize2;
	int vals3[kListSize3];
	for (int i = 0; i < kListSize2; i++)
		vals3[i] = i + 10;
	CNode *Head3 = CreateList(kListSize3, vals3);
	print(Head3);
	std::cout<<std::endl;
	merge(&Head, Head1, j);
	print(Head);
	EXPECT_EQ(true, myCompare(Head, Head3));
}

TEST(testList, sort_List) {
	const int kListSize1 = 5;
	int vals1[kListSize1] = {1, 3, 0, 2, 4};
	CNode *Head1 = CreateList(kListSize1, vals1);
	sort(&Head1);
	print(Head1);
	const int kListSize2 = 5;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i;
	CNode *Head2 = CreateList(kListSize2, vals2);
	print(Head2);
	EXPECT_EQ(true, myCompare(Head1, Head2));
}

TEST(testList, sort_empty_List) {
	CNode *Head1 = NULL;
	ASSERT_ANY_THROW(sort(&Head1));
}

TEST(testList, sort_List_of1) {
	const int kListSize1 = 1;
	int vals1[kListSize1] = {-1};
	CNode *Head1 = CreateList(kListSize1, vals1);
	sort(&Head1);
	print(Head1);
	const int kListSize2 = 1;
	int vals2[kListSize2] = {-1};
	CNode *Head2 = CreateList(kListSize2, vals2);
	print(Head2);
	EXPECT_EQ(true, myCompare(Head1, Head2));
}

TEST(testList, sort_List_of2) {
	const int kListSize1 = 2;
	int vals1[kListSize1] = {5, -1};
	CNode *Head1 = CreateList(kListSize1, vals1);
	sort(&Head1);
	print(Head1);
	const int kListSize2 = 2;
	int vals2[kListSize2] = {-1, 5};
	CNode *Head2 = CreateList(kListSize2, vals2);
	print(Head2);
	EXPECT_EQ(true, myCompare(Head1, Head2));
}

TEST(testList, sort_List_of3) {
	const int kListSize1 = 3;
	int vals1[kListSize1] = {0, 5, -1};
	CNode *Head1 = CreateList(kListSize1, vals1);
	sort(&Head1);
	print(Head1);
	const int kListSize2 = 3;
	int vals2[kListSize2] = {-1, 0, 5};
	CNode *Head2 = CreateList(kListSize2, vals2);
	print(Head2);
	EXPECT_EQ(true, myCompare(Head1, Head2));
}

TEST(testList, sort_List_of100) {
	const int kListSize1 = 100;
	int vals1[kListSize1];
	for (int i = 0; i < kListSize1; i++)
		vals1[i] = 99 - i;
	CNode *Head1 = CreateList(kListSize1, vals1);
	sort(&Head1);
	//print(Head1);
	const int kListSize2 = 100;
	int vals2[kListSize2];
	for (int i = 0; i < kListSize2; i++)
		vals2[i] = i;
	CNode *Head2 = CreateList(kListSize2, vals2);
	//print(Head2);
	EXPECT_EQ(true, myCompare(Head1, Head2));
}