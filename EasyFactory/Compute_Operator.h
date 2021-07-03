#pragma once
#include<iostream>
#include<string>

using namespace std;

double _computeResult(double num1, double num2, char op); // �ӿ�����

//�����Ʒ�� �����������Ӳ�Ʒ�ĸ��࣬һ���Ϊ��ʵ�֣������ࣩ
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

	virtual double GetResult() const = 0; // ��ʵ�֣�����ʵ���ɸ����������

protected:
	double numberA_;
	double numberB_;

};

//�Ӽ��˳���,����Ĳ�Ʒ�࣬�̳и��࣬
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

//�����ࣺcreateOperation ������������ָ�룬ͨ��switch�ṹָ����Եľ������࣬ע�������new����Ҫ�ֶ��ͷ�
class OperationFactory
{
public:
	// ͨ������ָ��type name����OperationFactory������Ӧ��������
	Operation* createOperation(char type)
	{
		Operation * oper = nullptr; // ���常��ָ��
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

// �ӿ�
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
