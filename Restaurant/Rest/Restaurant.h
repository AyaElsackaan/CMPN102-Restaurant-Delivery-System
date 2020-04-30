#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "../Defs.h"
#include "../CMUgraphicsLib/CMUgraphics.h"
#include "../GUI/GUI.h"
#include "../Generic_DS/Queue.h"
#include "../Events/Event.h"
#include"../Events/PromotionEvent.h"
#include "Motorcycle.h"
#include<fstream>
#include<sstream>
#include<string>
#include "Order.h"
#include "../ListLinkedList.h"
#include"..\PriorityQueue.h"
#include "../Region.h"
class Restaurant
{

	GUI *pGUI;
	//
	// TODO: Add More Data Members As Needed
	//
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file
	Region* rArr;
	Queue<Order*> FinishedOrders; //Queue of all finished orders 
	ListLinkedList<Order*> temporders;
	int Prom;   //promotion limit for normal orders
	int motoID ;
	Queue<Order*> lasttimestep;


public:
	void Save();
	bool Read(const string s);
	Restaurant();
	~Restaurant();
	void AddEvent(Event* pE);	//adds a new event to the queue of events
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();

	/// ==> 

	//
	// TODO: Add More Member Functions As Needed
	//
	void InteractiveMode();
	void StepMode();
	void SilentMode();
	void AddtoOrders(Order* po, int ts);
	void CancelEvent(int id);
	bool endOfOrders()const;
	void PromoteEvent(int Time, int ID, double Mon);
	void serve(int timestep);
	void returnMotorcycles(int timestep);
	void promotenormal(int);
	void setscheduled(Order*pO);
	void returnrestingMotorcycles(int);
	void setserved(int );

};

#endif
