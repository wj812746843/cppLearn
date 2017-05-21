#include "public.h"
class Solution {
public:
	/*
	题目描述
	在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
	请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
	*/
    bool static Find(int target, vector<vector<int> > array) {
		if(array.size() < 1)
			return false;
		int row = 0, col = array[0].size()-1;
		while(row < array.size() &&
			  col >= 0)
		{
			if(target > array[row][col])
			{
				row++;
			}
			else if (target < array[row][col])
			{
				col--;
			}
			else
			{
				return true;
			}
		}
		return false;
    }
};
int main()
{
	cout << "hello world" << endl;
	vector<int> a, b;
	a.push_back(1);
	a.push_back(2);
	b.push_back(3);
	b.push_back(4);
	vector<vector<int> > array;
	array.push_back(a);
	array.push_back(b);

	cout << "result: " << Solution::Find(3, array) << endl;
	return 0;
}