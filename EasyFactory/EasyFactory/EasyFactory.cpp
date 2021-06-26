// EasyFactory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*简单工厂方法总结： 
 *	1. 代码复用：将运算符类型抽象为抽象类，具体的运算符继承抽象类，只要实现各自的特殊方法
 *	2. 解耦合：将接口与实现解耦，将外部暴露接口与内部逻辑实现解耦，运算符之间各自实现，相互解耦合
 *	3. 封装，采用面向对象对内部逻辑实现封装
 *  4. 父类指针实例化子类对象
 */
// 接口
#include "Compute_Operator.h"

// 客户端
int main()
{
	double num1, num2;
	char op;
	cout << "Please enter num1:" << endl;
	cin >> num1;
	cout << "Please enter op:" << endl;
	cin >> op;
	cout << "Please enter num2:" << endl;
	cin >> num2;

	double result = _computeResult(num1, num2, op);

	cout << "Result is " << result << endl;

	return 0;
}

