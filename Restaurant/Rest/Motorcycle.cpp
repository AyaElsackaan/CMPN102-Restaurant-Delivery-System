#include "Motorcycle.h"


Motorcycle::Motorcycle()
{
	status = IDLE;
//	health = 100;
}

Motorcycle::Motorcycle(int id, ORD_TYPE otype, REGION r, int sp)
{
	status = IDLE;
	ID = (id > 0 && id < 1000) ? id : 0;
	type = otype;
	region = r;
	speed = sp;
	health = 100;

}

void Motorcycle::setStatus(STATUS s)
{
	status = s;
}

REGION Motorcycle::getRegion() const
{
	return region;
}

ORD_TYPE Motorcycle::getType() const
{
	return type;
}


STATUS Motorcycle::getstatus() const
{
	return status;
}

int Motorcycle::GetID() const
{
	return ID;
}

int Motorcycle::getspeed() const
{
	return speed;
}

int Motorcycle::getReturnTimestep() const
{
	return returnTimestep;
}

void Motorcycle::setReturnTimestep(int r)
{
	returnTimestep = r;
}

bool Motorcycle::isResting() const
{
	if (status==RESTING)
	{
		return true;
	}
	return false;
}

bool Motorcycle::isDamaged() const
{
	if (status==DAMAGED)
		return true;
	return false;
}

void Motorcycle::setrest(int ts)
{
	resttimestep = ts;
}

int Motorcycle::getrest() const
{
	return resttimestep;
}

int Motorcycle::gethealth() const
{
	return health;
}

void Motorcycle::damage()
{
	health = health-20;
}

void Motorcycle::setOrdtype(ORD_TYPE temp)
{
	assignedorder = temp;
}

ORD_TYPE Motorcycle::getOrdtype() const
{
	return assignedorder;
}

Motorcycle::~Motorcycle()
{
}

bool Motorcycle :: operator==(Motorcycle M) const
{
	return(this->speed == M.speed);
}
bool Motorcycle ::operator >(Motorcycle M) const
{
	return(this->speed > M.speed);

}
bool Motorcycle ::operator <(Motorcycle M) const
{
	return(this->speed < M.speed);
}

