#pragma once
#include<iostream>
#include<string>

using namespace std;

double _computeResult(double num1, double num2, char op); // 接口声明

//抽象产品类 往往是其他子产品的父类，一般均为虚实现（抽象类）
class Operation
{

public:
	double getA()
	{
		return numberA_;
	}

	double getB()
	{
		return numberB_;
	}

	void setA(double number)
	{
		numberA_ = number;
	}

	void setB(double number)
	{
		numberB_ = number;
	}

	virtual double GetResult() const = 0; // 虚实现，具体实现由各个子类完成

protected:
	double numberA_;
	double numberB_;

};

//加减乘除类,具体的产品类，继承父类，
class OperationAdd :public Operation
{
public:
	virtual double GetResult() const
	{
		double result = 0;
		result = numberA_ + numberB_;
		return result;
	}

};

class OperationSub :public Operation
{
public:
	virtual double GetResult() const
	{
		double result = 0;
		result = numberA_ - numberB_;
		return result;
	}
};

class OperationMul :public Operation
{
public:
	virtual double GetResult() const
	{
		double result = 0;
		result = numberA_ * numberB_;
		return result;
	}
};

class OperationDiv :public Operation
{
public:
	virtual double GetResult() const
	{
		double result = 0;
		if (numberB_ != 0)
			result = numberA_ / numberB_;
		return result;
	}
};

//工厂类：createOperation 方法声明父类指针，通过switch结构指向各自的具体子类，注意采用了new，需要手动释放
class OperationFactory
{
public:
	// 通过传入指定type name，由OperationFactory解析对应的类声明
	Operation* createOperation(char type)
	{
		Operation * oper = nullptr; // 定义父类指针
		switch (type)
		{
		case '+':
			oper = new OperationAdd();
			if (!isValid(oper))
			{
				cout << "Not enough heap memory" << endl;
				return nullptr;
			}
			break;
		case '-':
			oper = new OperationSub();
			if (!isValid(oper))
			{
				cout << "Not enough heap memory" << endl;
				return nullptr;
			}
			break;
		case '*':
			oper = new OperationMul();
			if (!isValid(oper))
			{
				cout << "Not enough heap memory" << endl;
				return nullptr;
			}
			break;
		case '/':
			oper = new OperationDiv();
			if (!isValid(oper))
			{
				cout << "Not enough heap memory" << endl;
				return nullptr;
			}
			break;
		}
		return oper;
	}

	bool isValid(Operation* op)
	{
		if (op == nullptr)
			return false;
		else
			return true;
	}
};

// 接口
double _computeResult(double num1, double num2, char op)
{
	Operation* Oper = nullptr;
	OperationFactory solve;
	Oper = solve.createOperation(op);
	Oper->setA(num1);
	Oper->setB(num2);
	double result = Oper->GetResult();

	if (Oper != nullptr)
	{
		delete Oper;
		Oper = nullptr;
	}

	return result;
}
