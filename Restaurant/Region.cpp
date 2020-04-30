#include "Region.h"



Region::Region()
{
	servVmotors = 0;
	servNmotors = 0;
	servFmotors = 0;
	servedFrozen = 0;
	servedNormal = 0;
	servedVIP = 0;
	servedSched = 0;
	totalserving = 0;
	totalwaiting = 0;
}


Region::~Region()
{
	NormalOrders.clear();

}

void Region::setnormal(int normal)
{
	NormalMotoCount = normal;
}
void Region::setfrozen(int frozen)
{
	FrozenMotoCount = frozen;
}
void Region::setVIP(int vip)
{
	VIPMotoCount = vip;
}
int Region::getBusyNmoto()
{
	return servNmotors;
}
int Region::getBusyVmoto()
{
	return servVmotors;
}
int Region::getBusyFmoto()
{
	return servFmotors;
}
Order* Region::getNormal(int pos)
{
	Order* temp;
	bool check = NormalOrders.getEntry(pos, temp);
	if (check)
	{
		return temp;

	}
	else
	{
		return NULL;
	}
}
int Region::GetNrmCount()
{
	return NormalOrders.GetCount();
}
void  Region::SetGui(GUI* ptr)
{
	pGUI = ptr;
}
void Region::addOrder( Order * po, int ts)
{




	if (po->GetType() == TYPE_NRM)
	{
		NormalOrders.insertEnd(po);

	}
	else if (po->GetType() == TYPE_FROZ)
	{
		FrozenOrders.enqueue(po);


	}
	else if (po->GetType() == TYPE_VIP)
	{
		VIPOrders.add(po);

	}

	else if (po->GetType() == TYPE_SCH)
	{
		//cout << po->getexptimestep() << endl;
		
	
		SchedOrders.add(po);
		//cout << po->getexptimestep() << endl;


	}
/*	else if (po->GetType() == TYPE_COMBO)
	{
		ComboOrders.enqueue(po);

	}
*/
}
int Region::ReturnNMotoNo()
{
	return  NormalMotoCount;
}
int Region::ReturnFMotoNo()
{
	return FrozenMotoCount;
}
int Region::ReturnVMotoNo()
{
	return VIPMotoCount;
}
int  Region::ReturnVipO()
{
	return VIPOrders.getCount();
}
int  Region::ReturnNormalO()
{
	return NormalOrders.GetCount();
}
int Region::ReturnFrzO()
{
	return FrozenOrders.GetCount();
}
int Region::returnschO()
{
	return SchedOrders.getCount();
}
int Region::getsevedNormal()
{
	return servedNormal;
}
int Region::getservedFrozen()
{
	return servedFrozen;
}
int Region::getservedVIP()
{
	return servedVIP;
}
int Region::getservedsch()
{
	return servedSched;
}
int Region::getavgnormalspeed()
{
	return avgspeedNormal;
}
int Region::getservedSched()
{
	return servedSched;
}
int Region::getscheduledcount() 
{
	return SchedOrders.getCount();
}
double Region::getavgwaiting()
{
	double n = servedFrozen + servedNormal + servedVIP+servedSched/*+servedCombo*/;
	return totalwaiting/n;
}
double Region::getavgserving()
{
	double n = servedFrozen + servedNormal + servedVIP + servedSched/*+servedCombo*/;
	return totalserving / n;
}
void Region::setavgspeedNormal()
{
	Motorcycle* Moto;
	int sum=0;
	int c = NormalMoto.getCount();
	for (int i = 0; i <c ; i++)
	{
		NormalMoto.getEntry(i, Moto);
		sum+=Moto->getspeed();
	}
	if (c==0)
	{
		avgspeedNormal = 0;
	}
	else
	{
		avgspeedNormal = sum / c;

	}
}
void Region::incwaiting(int x)
{
	totalwaiting += x;
}
/*void Region::setscheduled(Order* pO)
{
	for (int i = 0; i < SchedOrders.GetCount(); i++)
	{
		Order*O;
		SchedOrders.dequeue(O);
		O->setexptimestep(O->GetDistance() / avgspeedNormal);
		SchedOrders.enqueue(O);
	}
	
	
}
*/
void Region::incserving(int x)
{
	totalserving += x;
}
void Region::DeleteOrder(Order* ptr)
{
	Node<Order*>*Temp = NormalOrders.getHead();

	while (Temp)
	{
		if (ptr == Temp->getItem())
		{
			NormalOrders.DeleteNode(ptr);
			return;
		}
		Temp = Temp->getNext();
	}

}

void Region::removeOrder(Order * po)
{
	pGUI->Removedrawing(po);
	pGUI->UpdateInterface();

	if (po->GetType() == TYPE_NRM)
	{
		NormalOrders.removeBeg();

	}
	else if (po->GetType() == TYPE_FROZ)
	{
		FrozenOrders.dequeue(po);

	}
	else if (po->GetType() == TYPE_VIP)
	{
		VIPOrders.remove(po);
	}

	pGUI->UpdateInterface();
}
Order* Region::GetOrder(int ID)
{
	Node<Order*>*Temp = NormalOrders.getHead();
	while (Temp)
	{
		if (Temp->getItem()->GetID() == ID) return Temp->getItem();
		Temp = Temp->getNext();
	}
	return NULL;
}
Motorcycle * Region::GetMotor(int ID)
{
	Node<Motorcycle*>*Temp = NormalMoto.getHead();
	while (Temp)
	{
		if (Temp->getItem()->GetID() == ID) return Temp->getItem();
		Temp = Temp->getNext();
	}
	Temp = VIPMoto.getHead();
	while (Temp)
	{
		if (Temp->getItem()->GetID() == ID) return Temp->getItem();
		Temp = Temp->getNext();
	}
	Temp = FrozenMoto.getHead();
	while (Temp)
	{
		if (Temp->getItem()->GetID() == ID) return Temp->getItem();
		Temp = Temp->getNext();
	}
	return nullptr;
}
void Region::addMoto(Motorcycle * pM)
{
	switch (pM->getType())
	{
	case(TYPE_FROZ):
		FrozenMoto.insertSorted(pM);
		break;

	case(TYPE_NRM):
		NormalMoto.insertSorted(pM);
		break;

	case(TYPE_VIP):
		VIPMoto.insertSorted(pM);
		break;

	default:
		break;
	}
}

void Region::testremoveNorm()

{
	if (!NormalOrders.isEmpty())
	{
		Order* test = NormalOrders.removeBeg();
		if (test != nullptr)
		{
			pGUI->Removedrawing(test);
			pGUI->UpdateInterface();
		}
	}
}

void Region::testremoveFrz()
{
	if (!FrozenOrders.isEmpty())
	{
		Order*test;
		bool check = FrozenOrders.dequeue(test);
		if (test != nullptr)
		{
			pGUI->Removedrawing(test);
			pGUI->UpdateInterface();
		}
	}
}

void Region::testremoveVip()
{
	if (!VIPOrders.isEmpty())
	{
		Order*test;
		bool check = VIPOrders.remove(test);
		if (test != nullptr)
		{
			pGUI->Removedrawing(test);
			pGUI->UpdateInterface();
		}
	}
}

Order** Region::arrFrz(int&n)
{
	n = FrozenOrders.GetCount();
	Order** temp;
	temp = FrozenOrders.toArray();
	return temp;
}

Order** Region::arrNrm(int&n)
{
	n = NormalOrders.GetCount();
	Order** temp;
	temp = NormalOrders.toArray();
	return temp;
}

Order**Region::arrVip(int&n)
{
	n = VIPOrders.getCount();
	Order** temp;
	temp = VIPOrders.toArray();
	return temp;
}

Order ** Region::arrSch(int & n)
{
	n = SchedOrders.getCount();
	Order** temp;
	temp =SchedOrders.toArray();
	return temp;
}

bool Region::emptyfrozen() const
{
	return FrozenOrders.isEmpty();
}

bool Region::emptynormal() const
{
	return NormalOrders.isEmpty();
}

bool Region::emptyVip() const
{
	return VIPOrders.isEmpty();
}

bool Region::emptysch() const
{
	return SchedOrders.isEmpty();

}

bool Region::emptyOrders() const
{
	return emptyfrozen() && emptynormal() && emptyVip()&&emptysch();
}

bool Region::serveVIP(Order*&servedOrd, Motorcycle*&servingMoto, bool &check, int ts)
{
	if (!VIPOrders.isEmpty())
	{
		Motorcycle* freemoto;
		Order* temp = NULL;
		Order* served = NULL;
		bool isfreeVIP = getFirstVIPMoto(freemoto);
		if (isfreeVIP)
		{
			if (freemoto->getstatus()==RESTING)
			{
				freemoto->damage();
			}
			VIPOrders.remove(served);
			VIPOrders.Peek(temp);				//served->setservingtime
			freemoto->setStatus(SERV);
			servedOrd = served;
			servingMoto = freemoto;
			servedOrd->setordMotoID(freemoto->GetID());
			servedOrd->setMototype("V");
			servVmotors++;
			if (temp != NULL)
			{
				if (temp->getarrivalTime() != ts)
					check = false;
			}
//			servedVIP++;
			servingMoto->setOrdtype(TYPE_VIP);
			return true;
		}
		bool isfreeNormal = getFirstNormalMoto(freemoto);
		if (isfreeNormal)
		{
			if (freemoto->getstatus() == RESTING)
			{
				freemoto->damage();
			}
			VIPOrders.remove(served);
			VIPOrders.Peek(temp);				//served->setservingtime
			freemoto->setStatus(SERV);

			servedOrd = served;
			servingMoto = freemoto;
			servedOrd->setordMotoID(freemoto->GetID());
			servedOrd->setMototype("N");
    		servNmotors++;

			if (temp != NULL)
			{
				if (temp->getarrivalTime() != ts)
					check = false;
			}
//			servedVIP++;
			servingMoto->setOrdtype(TYPE_VIP);
			return true;
		}
		bool isfreeFrozen = getFirstFrozenMoto(freemoto);
		if (isfreeFrozen)
		{
			if (freemoto->getstatus() == RESTING)
			{
				freemoto->damage();
			}
			VIPOrders.remove(served);
			VIPOrders.Peek(temp);				//served->setservingtime
			freemoto->setStatus(SERV);

			servedOrd = served;
			servingMoto = freemoto;
			servedOrd->setordMotoID(freemoto->GetID());
			servedOrd->setMototype("F");
			servFmotors++;
			if (temp != NULL)
			{
				if (temp->getarrivalTime() != ts)
					check = false;
			}
	//		servedVIP++;
			servingMoto->setOrdtype(TYPE_VIP);
			return true;
		}



	}
	check = false;
	return false;
}

bool Region::getFirstVIPMoto(Motorcycle *&free)
{
	int size = VIPMoto.getLength();
	Motorcycle* M;
	for (int i = 0; i < size; i++)
	{
		VIPMoto.getEntry(i, M);
		if (M->getstatus() == IDLE|| M->getstatus() == RESTING)
		{
			free = M;
			return true;
		}
	}
	free = NULL;
	return false;
}

void Region::returnMoto(int timestep)
{
	Motorcycle* M;

	for (int i = 0; i < VIPMoto.getLength(); i++)
	{
		VIPMoto.getEntry(i, M);
		if (M->getReturnTimestep() == timestep)
		{
			if (M->gethealth() < 0)
			{
				M->setStatus(DAMAGED);
				VIPMoto.remove(i);
				decVmoto();
				pGUI->PrintMessage("Vip Damaged!!!",1000,55);
			}
			else
			{
				M->setStatus(RESTING);
				M->setrest(timestep + 3);
			}
			servVmotors--;

		}
	}
	for (int i = 0; i < FrozenMoto.getLength(); i++)
	{
		FrozenMoto.getEntry(i, M);
		if (M->getReturnTimestep() == timestep)
		{
			if (M->gethealth() < 0)
			{
				M->setStatus(DAMAGED);
				FrozenMoto.remove(i);
				decFmoto();
				pGUI->PrintMessage("Frozen Damaged!!!", 1000, 55);

			}
			else
			{
				M->setStatus(RESTING);
				M->setrest(timestep + 3);
			}
			servFmotors--;

		}
	}
	for (int i = 0; i < NormalMoto.getLength(); i++)
	{
		NormalMoto.getEntry(i, M);
		if (M->getReturnTimestep() == timestep)
		{
			if (M->gethealth() < 0)
			{
				M->setStatus(DAMAGED);
				NormalMoto.remove(i);
				decNmoto();
				pGUI->PrintMessage("Normal Damaged!!!", 1000, 55);

			}
			else
			{
				M->setStatus(RESTING);
				M->setrest(timestep + 3);
			}
			servNmotors--;

		}

	}
}

void Region::returnRest(int timestep)
{
	Motorcycle* M;

	for (int i = 0; i < VIPMoto.getLength(); i++)
	{
		VIPMoto.getEntry(i, M);
		if (M->getrest()==timestep&&M->getstatus() == RESTING)
		{
			if (M->getstatus()!=SERV)
			{
				M->setStatus(IDLE);

			}

		}
	}
	for (int i = 0; i < FrozenMoto.getLength(); i++)
	{
		FrozenMoto.getEntry(i, M);
		if (M->getrest() == timestep && M->getstatus() == RESTING)
		{
			M->setStatus(IDLE);

		}
	}
	for (int i = 0; i < NormalMoto.getLength(); i++)
	{
		NormalMoto.getEntry(i, M);
		if (M->getrest() == timestep && M->getstatus() == RESTING)
		{
			M->setStatus(IDLE);
		}
	}
}

bool Region::getFirstNormalMoto(Motorcycle *&free)
{
	int size = NormalMoto.getLength();
	Motorcycle* M;
	for (int i = 0; i < size; i++)
	{
		NormalMoto.getEntry(i, M);
		if (M->getstatus() == IDLE || M->getstatus() == RESTING)
		{
			free = M;
			return true;
		}
	}
	free = NULL;
	return false;
}

bool Region::getFirstFrozenMoto(Motorcycle *&free)
{
	int size = FrozenMoto.getLength();
	Motorcycle* M;
	for (int i = 0; i < size; i++)
	{
		FrozenMoto.getEntry(i, M);
		if (M->getstatus() == IDLE || M->getstatus() == RESTING)
		{
			free = M;
			return true;
		}
	}
	free = NULL;
	return false;
}
bool Region::FreeMotors()
{
	if (servNmotors == 0 && servVmotors == 0 && servFmotors == 0)
		return true;
	return false;
}
void Region::decNmoto()
{
	NormalMotoCount--;
}
void Region::decFmoto()
{
	FrozenMotoCount--;
}
void Region::decVmoto()
{
	VIPMotoCount--;
}
void Region::addserving(Order * temp)
{
	if(temp!=NULL)
	Serving.insertEnd(temp);
}
void Region::tellserved(int ts)
{
	int length = Serving.GetCount();
	Order* temp;
	for (int i = 0; i < length; i++)
	{
		Serving.getEntry(i,temp);
		if (temp->getfinishTime()==ts)
		{
			if (temp->GetType()==TYPE_NRM)
			{
				servedNormal++;
			}
			else if(temp->GetType() == TYPE_VIP)
			{
				servedVIP++;
			}
			else if(temp->GetType() == TYPE_FROZ)
			{
				servedFrozen++;
			}
			else if(temp->GetType() == TYPE_SCH)
			{
				servedSched++;
			}
		}
	}
}
bool Region::serveFrozen(Order*&servedOrd, Motorcycle*&servingMoto, bool &check, int ts)
{
	if (!FrozenOrders.isEmpty())
	{
		Motorcycle* freemoto;
		Order* temp = NULL;
		Order* served = NULL;
		bool isfreeFrozen = getFirstFrozenMoto(freemoto);
		if (isfreeFrozen)
		{
			if (freemoto->getstatus() == RESTING)
			{
				freemoto->damage();
			}
			FrozenOrders.dequeue(served);
			FrozenOrders.peekFront(temp);
			freemoto->setStatus(SERV);
			servedOrd = served;
			servingMoto = freemoto;
			servedOrd->setordMotoID(freemoto->GetID());
			servedOrd->setMototype("F");
			servFmotors++;
			if (temp != NULL)
			{
				if (temp->getarrivalTime() != ts)
					check = false;
			}
//			servedFrozen++;
			servingMoto->setOrdtype(TYPE_FROZ);
			return true;
		}

	}
	check = false;
	return false;
}

bool Region::serveScheduled(Order *& servedOrd, Motorcycle *& servingMoto, bool & check, int ts)
{
	
	if (!SchedOrders.isEmpty())
	{
		Motorcycle* freemoto;
		Order* temp = NULL;
		Order* served = NULL;
		SchedOrders.Peek(served);
		if (served->getexptimestep() > ts)
		{
			check = false;
			return false;
		}
		bool isfreeSched = getFirstNormalMoto(freemoto);
		if (isfreeSched)
		{
			if (freemoto->getstatus() == RESTING)
			{
				freemoto->damage();
			}
			SchedOrders.remove(served);
			SchedOrders.Peek(temp);
			//if (served->getexptimestep() > ts)
				//return false;
			freemoto->setStatus(SERV);
			servedOrd = served;
			servingMoto = freemoto;
			servedOrd->setordMotoID(freemoto->GetID());
			servedOrd->setMototype("N");
			servNmotors++;
			if (temp != NULL)
			{
				if (temp->getarrivalTime() != ts)
					check = false;
			}
			//servedSched++;
			servingMoto->setOrdtype(TYPE_SCH);
			return true;
		}

	}
	check = false;
	return false;
}


bool Region::serveNormal(Order*&servedOrd, Motorcycle*&servingMoto, bool &check, int ts)
{
	if (!NormalOrders.isEmpty())
	{
		Motorcycle*freemoto;
		Order* temp = NULL;
		Order* served = NULL;
		bool isfreeNormal = getFirstNormalMoto(freemoto);
		if (isfreeNormal)
		{
			if (freemoto->getstatus() == RESTING)
			{
				freemoto->damage();
			}
			served = NormalOrders.removeBeg();
			NormalOrders.getEntry(0, temp);
			freemoto->setStatus(SERV);
			servedOrd = served;
			servingMoto = freemoto;
			servedOrd->setordMotoID(freemoto->GetID());
			servedOrd->setMototype("N");
			servNmotors++;
			if (temp != NULL)
			{
				if (temp->getarrivalTime() != ts)
					check = false;
			}
//			servedNormal++;
			servingMoto->setOrdtype(TYPE_NRM);
			return true;
		}
		bool isfreevip = getFirstVIPMoto(freemoto);
		if (isfreevip)
		{
			if (freemoto->getstatus() == RESTING)
			{
				freemoto->damage();
			}
			served = NormalOrders.removeBeg();
			NormalOrders.getEntry(0, temp);
			freemoto->setStatus(SERV);
			servedOrd = served;
			servingMoto = freemoto;
			servedOrd->setordMotoID(freemoto->GetID());
			servedOrd->setMototype("V");
			servVmotors++;
			if (temp != NULL)
			{
				if (temp->getarrivalTime() != ts)
					check = false;
			}
//			servedNormal++;
			servingMoto->setOrdtype(TYPE_NRM);
			return true;
		}

	}
	check = false;
	return false;
}
