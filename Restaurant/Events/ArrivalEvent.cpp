#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, int oID, int OD, double OrderMoney, ORD_TYPE oType, REGION reg,int x):Event(eTime, oID)
{
	OrdType = oType;
	OrdRegion = reg;
	OrdDistance = OD;
	OrdMoney = OrderMoney;
	finishtime = x;
}

void ArrivalEvent::Execute(Restaurant* pRest, int ts)
{
	//This function should create an order and  fill its data 
	// Then add it to normal, frozen, or VIP order lists that you will create in phase1

	Order* pOrd = new Order(getOrderID(), OrdType, OrdRegion, OrdDistance,getEventTime() , OrdMoney,finishtime);
	pRest->AddtoOrders(pOrd, ts);
	
	///For the sake of demo, this function will just create an order and add it to DemoQueue
	///Remove the next code lines in phase 1&2
	/*
	Order* pOrd = new Order(OrderID,OrdType,OrdRegion);
	pRest->AddtoDemoQueue(pOrd);
	*/
}
