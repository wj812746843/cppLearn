#include "public.h"
#include <gtest/gtest.h>

 //Definition for binary tree
 struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	/************************************************************************/
	/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
	假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。                                                                      */
	/************************************************************************/
	
    static TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		TreeNode* head = NULL;
		vector<int> pre_left, pre_right, vin_left, vin_right;
		if (pre.size() > 0)
		{
			head = new TreeNode(pre[0]);
			int i=0;
			for (i=0; i<vin.size()-1; i++)
			{
				if (vin[i] == pre[0])
				{
					break;
				}
			}
			if (i == 0)
			{
				head->left = NULL;
			}
			else if (i>0)
			{
				for (int j=1; j<=i; j++ )
				{
					pre_left.push_back(pre.at(j));
					vin_left.push_back(vin.at(j-1));
				}
				head->left = reConstructBinaryTree(pre_left, vin_left);
			}

			if (i == vin.size()-1)
			{
				head->right = NULL;
			}
			else if (i<vin.size()-1)
			{
				for (int j=i+1; j<=vin.size()-1; j++ )
				{
					pre_right.push_back(pre.at(j));
					vin_right.push_back(vin.at(j));
				}
				head->right = reConstructBinaryTree(pre_right, vin_right);
			}
		}
		return head;
    }
};

/************************************************************************/
/* gtest使用:http://www.cnblogs.com/coderzh/archive/2009/04/06/1426755.html                                                                     */
/************************************************************************/
void printTree(TreeNode* head)
{
	if (head == NULL)
	{
		return;
	}
	if (head->left != NULL)
	{
		printTree(head->left);
	} 
	if(head->right != NULL)
	{
		printTree(head->right);
	}
	printf(" %d\n", head->val);
}

TEST(FooTest, HandleNoneZeroInput)
{
	int arrPre[] = {1,2,4,7,3,5,6,8};
	int arrMid[] = {4,7,2,1,5,3,8,6};
	vector<int> pre, mid;
	for(int i=0; i<sizeof(arrPre)/sizeof(int); i++)
	{
		pre.push_back(arrPre[i]);
	}
	for(int i=0; i<sizeof(arrMid)/sizeof(int); i++)
	{
		mid.push_back(arrMid[i]);
	}
	TreeNode* head = Solution::reConstructBinaryTree(pre, mid);
	printTree(head);

}
int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}