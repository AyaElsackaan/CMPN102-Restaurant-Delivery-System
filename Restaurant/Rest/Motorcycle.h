#ifndef __MOTORCYCLE_H_
#define __MOTORCYCLE_H_


#include "..\Defs.h"

#pragma once
class Motorcycle	
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding motorcycle type 
	int speed;		//meters it can move in one clock tick (in one timestep)
	REGION	region;	//region of the motorcycle
	STATUS	status;	//idle or in-service
	int health;
	/////
	int returnTimestep;
	int resttimestep;
	ORD_TYPE assignedorder;
public:
	Motorcycle();
	Motorcycle(int id, ORD_TYPE otype, REGION r, int sp);
	void setStatus(STATUS s);
	REGION getRegion()const;
	ORD_TYPE getType()const;
	bool operator >(Motorcycle M)const;
	bool operator <(Motorcycle M)const;
	bool operator==(Motorcycle M)const;

	STATUS getstatus()const;
	int GetID()const;
	int getspeed()const;
	int getReturnTimestep()const;
	void setReturnTimestep(int r);
	bool isResting()const;
	bool isDamaged()const;
	void setrest(int);
	int getrest()const;
	int gethealth()const;
	void damage();
	void setOrdtype(ORD_TYPE);
	ORD_TYPE getOrdtype()const;
	virtual ~Motorcycle();

};

#endif