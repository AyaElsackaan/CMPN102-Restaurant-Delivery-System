#pragma once
#ifndef __ORDER_H_
#define __ORDER_H_
#include<iostream>
#include "..\Defs.h"
using namespace std;

class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, Frozen, VIP
	REGION OrdRegion;  //Region of this order
	int Distance;	//The distance (in meters) between the order location and the resturant 
	double priority;
	double totalMoney;	//Total order money

	
	int ArrTime, ServTime, FinishTime;	//arrival, service start, and finish times		//timesteps*****
	int waitingPeroid, servicePeriod;			//periods of time*****
	string mototype, ordert;
	int motoID;

	//
	// TODO: Add More Data Members As Needed
	//
	int exptimestep, expfinish;	//for scheduled only

public:
	Order(int ID, ORD_TYPE r_Type, REGION r_region,int Dis,int Arrti,double mon, int t=0);
	Order();
	virtual ~Order();

	int GetID();

	ORD_TYPE GetType() const;
	REGION GetRegion() const;
	double GetMoney()const;
	void SetDistance(int d);
	int GetDistance() const;
	bool operator >(Order O)const;
	bool operator <(Order O)const;
	bool operator==(Order O)const;
	void operator=(Order O);
	//
	// TODO: Add More Member Functions As Needed
	//
	int RegionInd();
	char GetStr();

	void setservTime(int st);
	int getservTime()const;

	void setfinishTime(int ft);
	int getfinishTime()const;

	int getarrivalTime()const;

	int getwaitingperiod()const;
	void setwaitingperiod(int w);
	void setexptimestep(int s);
	void setserviceperiod(int s);
	int getservicePeriod()const;
	int getexptimestep()const;
	void setordMotoID(int);
	int getordMotoID()const;
	void setMototype(string);
	string getMototype() const;
	string getTypestr() const;

};

#endif