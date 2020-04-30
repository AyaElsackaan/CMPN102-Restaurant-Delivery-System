#pragma once
#include "Events/Event.h"
class CancellationEvent : public Event
{
	
public:
	CancellationEvent(int timestep,int ID);
	~CancellationEvent();
	void Execute(Restaurant *pRest, int ts=0);
};

