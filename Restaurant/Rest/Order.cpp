#include "Order.h"

Order::Order(int id, ORD_TYPE r_Type, REGION r_region,int Dis,int Arrte,double mon, int t)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	Distance = Dis;
	ArrTime = Arrte;
	type = r_Type;
	OrdRegion = r_region;
	totalMoney = mon;
	priority = 0;
	if (type == TYPE_VIP)
	{
		priority = Distance + totalMoney - ArrTime;
	}
	if (type == TYPE_SCH)
	{
		FinishTime= t;
		
	}
	switch (r_Type)
	{
	case TYPE_VIP:
		ordert = "V";
		break;
	case TYPE_FROZ:
		ordert = "F";
		break;
	case TYPE_NRM:
		ordert = "N";
		break;
	case TYPE_SCH:
	{
		ordert = "S";
		break;
	}
	default:
		return;
	};
	
}
Order::Order()
{

}
Order::~Order()
{
}
bool Order :: operator==(Order O) const
{
	if (type == TYPE_SCH)
	{
		return(getexptimestep()==O.getexptimestep());
}

	if ((priority == O.priority) && (ID == O.ID) && (totalMoney == O.totalMoney))
return true;
return false;
		
}
void Order::operator=(Order O)
{
	Distance = O.GetDistance();
	totalMoney = O.totalMoney;
	ArrTime=O.ArrTime;
	OrdRegion=O.OrdRegion;
	ID=O.ID;
	type=O.type;
}
bool Order ::operator >(Order O) const
{
	if (type == TYPE_SCH)
	{
		return(getexptimestep() < O.getexptimestep());
	}

	if (priority > O.priority) return true;
	else if(O.priority>priority)
	{
		return false;
	}
	if (ArrTime < O.ArrTime) return true;
	return false;

}
bool Order ::operator <(Order O) const
{
	if (type == TYPE_SCH)
	{
		return(getexptimestep() > O.getexptimestep());
}
	if (priority > O.priority) return false;
	
	return true;
}

int Order::RegionInd()
{
	switch (OrdRegion)
	{case A_REG:
		return 0;
	case B_REG:
		return 1;
	case C_REG:
		return 2;
	case D_REG:
		return 3;
	default:
		return -100;
	};
}
char Order::GetStr()
{

	switch (OrdRegion)
	{
	case A_REG:
		return 'A';
	case B_REG:
		return 'B';
	case C_REG:
		return 'C';
	case D_REG:
		return 'D';
	default:
		return 'l';
	}
}
void Order::setservTime(int st)
{
	ServTime = st;
}
int Order::getservTime() const
{
	return ServTime;
}
void Order::setfinishTime(int ft)
{
	FinishTime = ft;
}
int Order::getfinishTime() const
{
	return FinishTime;
}
int Order::getarrivalTime() const
{
	return ArrTime;
}
int Order::getwaitingperiod() const
{
	return waitingPeroid ;
}
void Order::setwaitingperiod(int w)
{
	waitingPeroid = w;
}
void Order::setexptimestep(int s)
{
	exptimestep = s;
}
void Order::setserviceperiod(int s)
{
	servicePeriod = s;
}
int Order::getservicePeriod() const
{
	return servicePeriod;
}
int Order::getexptimestep() const
{
	return exptimestep;
}
int Order::GetID()
{
	return ID;
}


ORD_TYPE Order::GetType() const
{
	return type;
}

REGION Order::GetRegion() const
{
	return OrdRegion;
}

double Order::GetMoney() const
{
	return totalMoney;
}

void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}
void Order::setordMotoID(int x)
{
	if (x > 0)
		motoID = x;
}
int Order::getordMotoID() const
{
	return motoID;
}
void Order::setMototype(string x)
{
	mototype = x;
}
string Order::getMototype() const
{
	return mototype;
}
string Order::getTypestr()const
{
	return ordert;
}
