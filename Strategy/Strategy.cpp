// Strategy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "strategy.h"

int main()
{
	cout << "Start discount：" << endl;
	string strategy = "rebate";
	CCashContext* pct = new CCashContext(strategy);
	cout << pct->getResult(500) << endl;

	delete pct;
	
	return 0;
}
