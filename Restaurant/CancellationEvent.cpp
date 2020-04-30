#include "CancellationEvent.h"
#include "Rest/Restaurant.h"

CancellationEvent::CancellationEvent(int timestep, int id):Event(timestep, id)
{
	
}


CancellationEvent::~CancellationEvent()
{
}

void CancellationEvent::Execute(Restaurant*pRest, int ts)
{
	pRest->CancelEvent(this->getOrderID());
}
