#include "public.h"
#include <gtest/gtest.h>

/************************************************************************/
/* 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。                                                                     */
/************************************************************************/
class Solution
{
public:
	void push(int node) {
		stack1.push(node);

	}

	int pop() {
		int result = -1;
		if (stack2.empty())
		{
			if (stack1.empty())
			{
				return result;
			} 
			else
			{
				while(!stack1.empty())
				{
					stack2.push(stack1.top());
					stack1.pop();
				}
			}
		} 
		
		result = stack2.top();
		stack2.pop();
		return result;

	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

TEST(FooTest, HandleNoneZeroInput)
{
	int arrPre[] = {1,2,4,7,3,5,6,8};
	Solution test;
	for(int i=0; i<sizeof(arrPre)/sizeof(int); i++)
	{
		test.push(arrPre[i]);
	}
	for(int i=0; i<sizeof(arrPre)/sizeof(int); i++)
	{
		cout << test.pop() << endl;
	}

	

}
int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
	return 0;
}