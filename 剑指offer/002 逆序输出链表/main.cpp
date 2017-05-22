#include "public.h"
#include <gtest/gtest.h>

 struct ListNode 
 {
	 int val;
	 struct ListNode *next;
	 ListNode(int x) :
     val(x), next(NULL) 
	 {	
	 }
};

class Solution {
public:
	/************************************************************************/
	/* 输入一个链表，从尾到头打印链表每个节点的值。                                                                     */
	/************************************************************************/
	static vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		if(head == NULL)
			return res;
		res = printListFromTailToHead(head->next);
		res.push_back(head->val);
		return res;
	}
};

/************************************************************************/
/* gtest使用:http://www.cnblogs.com/coderzh/archive/2009/04/06/1426755.html                                                                     */
/************************************************************************/
int Foo(int a, int b)
{
	if (a == 0 || b == 0)
	{
		throw "don't do that";
	}
	int c = a % b;
	if (c == 0)
		return b;
	return Foo(b, c);
}
TEST(FooTest, HandleNoneZeroInput)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(6, Foo(30, 18));
}
int main(int argc, char* argv[])
{
	 struct ListNode  node1(1), node2(2), node3(3);
	 node1.next = &node2;
	 node2.next = &node3;
	 node3.next = NULL;

	 vector<int> res = Solution::printListFromTailToHead(&node1);
	 for (unsigned int i=0; i<res.size(); i++)
	 {
		 cout << res.at(i) << endl;
	 }
	 testing::InitGoogleTest(&argc, argv);
	 return RUN_ALL_TESTS();


	return 0;
}