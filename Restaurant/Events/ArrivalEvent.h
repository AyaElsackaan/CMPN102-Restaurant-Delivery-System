#ifndef __ARRIVAL_EVENT_H_
#define __ARRIVAL_EVENT_H_

#include "Event.h"


//class for the arrival event
class ArrivalEvent: public Event
{
	//info about the order ralted to arrival event
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, Frozen, VIP
	REGION OrdRegion;  //Region of this order	                
	double OrdMoney;	//Total order money
	int finishtime;
public:
	ArrivalEvent(int eTime, int oID,int OD ,double OrderMoney,ORD_TYPE oType, REGION reg,int);
	//Add more constructors if needed
	
	virtual void Execute(Restaurant *pRest, int ts);	//override execute function

};

#endif