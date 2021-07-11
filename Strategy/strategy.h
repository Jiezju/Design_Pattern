#pragma once

#include <iostream>
#include <map>
using namespace std;

// �㷨���࣬�����㷨������ʹ�ýӿ�
class CCashBase
{
public:
	virtual double ReturnMoney(double money) = 0;
protected:
private:
};

// �㷨�࣬����ʵ���㷨����, ʵ�ֹ��нӿ�
class CCashNomal : public CCashBase
{
public:
	double ReturnMoney(double money)
	{
		return money;
	}
protected:
private:
};


class CCRebate : public CCashBase
{
public:
	CCRebate(double rebate) :m_dMoneyRebate(rebate) {}
	double ReturnMoney(double money)
	{
		return money * m_dMoneyRebate;
	}
protected:
private:
	double m_dMoneyRebate;
};

class CCashReturn : public CCashBase
{
public:
	CCashReturn(double mcondition, double mReturn): m_moneyCondition(mcondition), m_moneyReturn(mReturn) {}
	double ReturnMoney(double money)
	{
		double result = money;
		if (money >= m_moneyCondition)
			result = money - int(money / m_moneyCondition) * m_moneyReturn;
		return result;
	}
private:
	double m_moneyCondition;
	double m_moneyReturn;
};


// Context�࣬���ڽ����û����ã�ѡ����ʵ��㷨������������ϼ򵥹���ģʽ��
class CCashContext
{
public:
	CCashContext(string strategy): m_strategy(strategy)
	{
		m_funcmap = { {"normal", 1}, {"return", 2}, {"rebate", 3} };
		if (m_funcmap.count(strategy) == 0)
		{
			cout << "no this func" << endl;
		}
	}

	double getResult(double money)
	{
		CCashBase* m_pCB = nullptr;
		
		switch (m_funcmap[m_strategy])
		{
		case 1:
			m_pCB = new CCashNomal();
			break;
		case 2:
			m_pCB = new CCashReturn(300, 100);
			break;
		case 3:
			m_pCB = new CCRebate(0.8);
			break;
		default:
			m_pCB = new CCashNomal();
		}
		return m_pCB->ReturnMoney(money);
	}
private:
	string m_strategy;
	map<string, int> m_funcmap;
};

