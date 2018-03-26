#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//剑指offer面试题31:栈的压入/弹出序列

bool IsPopOrder(vector<int>& pPush, vector<int>& pPop){
	if (pPush.size() != pPop.size())
		return;

	stack<int> tmp;
	int popIndex = 0;
	for (int i = 0; i < pPush.size(); ++i)
	{
		tmp.push(pPush[i]);
		while(tmp.size() > 0 && tmp.top() == pPop[popIndex]){
			tmp.pop();
			++popIndex;
		}
	}
	return tmp.size() > 0 ? false : true;
}


int main()
{
	vector<int> pPush;
	vector<int> pPop;
	pPush.push_back(1);
	pPush.push_back(2);
	pPush.push_back(3);
	pPush.push_back(4);
	pPush.push_back(5);

	pPop.push_back(4);
	pPop.push_back(5);
	pPop.push_back(3);
	pPop.push_back(2);
	pPop.push_back(1);

	bool ret= IsPopOrder(pPush, pPop);
	cout<<ret<<endl;
	return 0;
}
