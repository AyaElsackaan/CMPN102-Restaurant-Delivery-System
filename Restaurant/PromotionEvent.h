#pragma once
#include"Events/Event.h"
class PromotionEvent : public Event
{

	double Money;
public:
	PromotionEvent(int Time,int Id, double Exmoney);
	~PromotionEvent();
	virtual void Execute(Restaurant* pRest, int ts=0);
};

