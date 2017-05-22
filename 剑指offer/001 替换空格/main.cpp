#include "public.h"
class Solution {
public:
	/*
	请实现一个函数，将一个字符串中的空格替换成“%20”。
	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
	*/

	/*
	不开辟新空间
	1、先找字符串里有多少个空格
	2、从后往前搜索、替换
	*/
	void static  replaceSpace(char *str,int length) 
	{
		if(str == NULL || length <1 || strlen(str) >= length)
			return;

		int blankNum = 0;
		int i=0, j=0;
		while(	(i < length) &&
				(str[i] != '\0'))
		{
			if (str[i] == ' ')
			{
				blankNum++;
			}
			i++;
		}

		int newLength = strlen(str)+2*blankNum;
		if (newLength >= length)
		{
			cout << "space not enough~" << endl;
			return;
		}

		str[newLength] = '\0';
		for (i = strlen(str)-1, j= newLength-1; i>=0; i--)
		{
			if (str[i] == ' ')
			{
				str[j--] = '0';
				str[j--] = '2';
				str[j--] = '%';
			} 
			else
			{
				str[j--] = str[i];
			}
		}
	}
	/************************************************************************/
	/* 从前往后搜索，需要开辟新空间                                                                     */
	/************************************************************************/
    void static  replaceSpace_version2(char *str,int length) {
		if(str == NULL || length <1)
			return;

		char* tmp = new char[length];
		int i=0, j=0;
		while(str[i] != '\0' && i < length)
		{
			if(str[i] == ' ')
			{
				tmp[j++] = '%';
				tmp[j++] = '2';
				tmp[j++] = '0';
			}
			else
			{
				tmp[j++] = str[i];
			}
			i++;
			
		}
		tmp[j++] = '\0';
		strncpy(str, tmp, length);
		delete[] tmp;
    }
};
int main()
{
	char input[100] = "We Are Happy";
	Solution::replaceSpace(input, 100);
	cout << input << endl;

	return 0;
}