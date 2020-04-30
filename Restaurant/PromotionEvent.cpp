#include "PromotionEvent.h"
#include "Rest/Restaurant.h"


PromotionEvent::PromotionEvent(int Time,int ID,double money) : Event(Time,ID)
{
	Money = money;
}

void PromotionEvent::Execute(Restaurant* pRest, int ts)
{
	pRest->PromoteEvent(EventTime,OrderID,Money);
}
PromotionEvent::~PromotionEvent()
{
}
