#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
#include"../CancellationEvent.h"
#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
#include "Motorcycle.h"
#include"../Region.h"
#include<cstring>
#include<cstringt.h>
#include"..\PromotionEvent.h"
void Restaurant::Save()
{
	ofstream Out("Output.txt");
	ofstream Outputfile1;
	Outputfile1.open("OutPut.txt", ios::app);
	Order* Dummy;
	Outputfile1 << "FT" << " " << "ID" << "  " << "AT" << " " << "WT" << " " << "ST" << "\n";
	while (FinishedOrders.dequeue(Dummy))
	{
		Outputfile1 << Dummy->getfinishTime() << "  " << Dummy->GetID() << "   " << Dummy->getarrivalTime() <<"  "<<Dummy->getwaitingperiod()<<"  "<<Dummy->getservicePeriod()<< "\n";

	}
	Outputfile1 << "###############" << "\n";
	Outputfile1 << "REGION A: " << "\n";
	Outputfile1 << "    " << "Orders: " << rArr[0].getservedFrozen() + rArr[0].getservedVIP() + rArr[0].getsevedNormal() << " " << "[Norm: " << rArr[0].getsevedNormal() << " ,Froz: " << rArr[0].getservedFrozen() << " ,VIP: " << rArr[0].getservedVIP() << " ,Sch: " << rArr[0].getservedsch() <<"]\n";
	Outputfile1 << "    " << "MotorC: "<<rArr[0].ReturnFMotoNo()+rArr[0].ReturnVMotoNo()+rArr[0].ReturnNMotoNo()<<" "<<"[Norm: "<< rArr[0].ReturnNMotoNo() <<" ,Froz: "<< rArr[0].ReturnFMotoNo() <<" ,VIP: "<< rArr[0].ReturnVMotoNo() << "]\n";
	Outputfile1 << "    " <<"Avg Wait = "<<rArr[0].getavgwaiting()<<", Avg Serv ="<<rArr[0].getavgserving()<<"\n";
	Outputfile1 << "###############" << "\n";
	Outputfile1 << "REGION B: " << "\n";
	Outputfile1 << "    " << "Orders: " << rArr[1].getservedFrozen() + rArr[1].getservedVIP() + rArr[1].getsevedNormal() << " " << "[Norm: " << rArr[1].getsevedNormal() << " ,Froz: " << rArr[1].getservedFrozen() << " ,VIP: " << rArr[1].getservedVIP() << " ,Sch: " << rArr[1].getservedsch() << "]\n";
	Outputfile1 << "    " << "MotorC: " << rArr[1].ReturnFMotoNo() + rArr[1].ReturnVMotoNo() + rArr[1].ReturnNMotoNo() << " " << "[Norm: " << rArr[1].ReturnNMotoNo() << " ,Froz: " << rArr[1].ReturnFMotoNo() << " ,VIP: " << rArr[1].ReturnVMotoNo() << "]\n";
	Outputfile1 << "    " << "Avg Wait = " << rArr[1].getavgwaiting() << ", Avg Serv =" << rArr[1].getavgserving() << "\n";
	Outputfile1 << "###############" << "\n";
	Outputfile1 << "REGION C: " << "\n";
	Outputfile1 << "    " << "Orders: " << rArr[2].getservedFrozen() + rArr[2].getservedVIP() + rArr[2].getsevedNormal() << " " << "[Norm: " << rArr[2].getsevedNormal() << " ,Froz: " << rArr[2].getservedFrozen() << " ,VIP: " << rArr[2].getservedVIP() << " ,Sch: " << rArr[2].getservedsch() << "]\n";
	Outputfile1 << "    " << "MotorC: " << rArr[2].ReturnFMotoNo() + rArr[2].ReturnVMotoNo() + rArr[2].ReturnNMotoNo() << " " << "[Norm: " << rArr[2].ReturnNMotoNo() << " ,Froz: " << rArr[2].ReturnFMotoNo() << " ,VIP: " << rArr[2].ReturnVMotoNo() << "]\n";
	Outputfile1 << "    " << "Avg Wait = " << rArr[2].getavgwaiting() << ", Avg Serv =" << rArr[2].getavgserving() << "\n";
	Outputfile1 << "###############" << "\n";
	Outputfile1 << "REGION D: " << "\n";
	Outputfile1 << "    " << "Orders: " << rArr[3].getservedFrozen() + rArr[3].getservedVIP() + rArr[3].getsevedNormal() << " " << "[Norm: " << rArr[3].getsevedNormal() << " ,Froz: " << rArr[3].getservedFrozen() << " ,VIP: " << rArr[3].getservedVIP() << " ,Sch: " << rArr[3].getservedsch() << "]\n";
	Outputfile1 << "    " << "MotorC: " << rArr[3].ReturnFMotoNo() + rArr[3].ReturnVMotoNo() + rArr[3].ReturnNMotoNo() << " " << "[Norm: " << rArr[3].ReturnNMotoNo() << " ,Froz: " << rArr[3].ReturnFMotoNo() << " ,VIP: " << rArr[3].ReturnVMotoNo() << "]\n";
	Outputfile1 << "    " << "Avg Wait = " << rArr[3].getavgwaiting() << ", Avg Serv =" << rArr[3].getavgserving() << "\n";
	Outputfile1.close();
}
bool Restaurant::Read(const string s)
{


	ifstream Out(s + ".txt");
	if (Out.is_open() == false)
		return false;

	string line;

	for (int i = 0; i < 4; i++)//no of moto in region
	{
		getline(Out, line);
		istringstream iss(line);

		
			int number;
			iss >> number;
			rArr[i].setnormal(number);
		//	cout << rArr[i].ReturnNMotoNo();

			iss >> number;
			rArr[i].setfrozen(number);
		//	cout << rArr[i].ReturnFMotoNo();

			iss >> number;
			rArr[i].setVIP(number);
			//cout << rArr[i].ReturnVMotoNo();

	}
	for (int i = 0; i < 4; i++)	//speed 
	{
		//normal
		getline(Out, line);
		istringstream iss(line);
		
		for (int j = 0; j < rArr[i].ReturnNMotoNo(); j++)
		{
			
			int sp;
			iss >> sp;
			Motorcycle* pM;

			pM = new Motorcycle(motoID, TYPE_NRM, REGION(i), sp);
			rArr[i].addMoto(pM);
			motoID++;

			//cout<<pM->getspeed() << endl;
		}
		//frozen
		getline(Out, line);
		istringstream iss2(line);
		
		//cout << rArr[i].ReturnNMotoNo() << endl;
		for (int j = 0; j < rArr[i].ReturnFMotoNo(); j++)
		{
			int sp;
			iss2 >> sp;
			Motorcycle* pM;

			pM = new Motorcycle(motoID, TYPE_FROZ, REGION(i), sp);
			rArr[i].addMoto(pM);
			motoID++;

			//cout<<pM->getspeed() << endl;
		}
		//vip
		getline(Out, line);
		istringstream iss3(line);

		//cout << rArr[i].ReturnNMotoNo() << endl;
		for (int j = 0; j < rArr[i].ReturnVMotoNo(); j++)
		{
			int sp;
			iss3 >> sp;
			Motorcycle* pM;

			pM = new Motorcycle(motoID,TYPE_VIP, REGION(i), sp);
			rArr[i].addMoto(pM);
			motoID++;

			//cout<<pM->getspeed() << endl;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		rArr[i].setavgspeedNormal();
		//cout << rArr[i].getavgnormalspeed() << endl;
	}

	//Limit of promotion
	getline(Out, line);
	istringstream iss2(line);
	iss2 >> Prom;

	//events count
	int eventscount;
	getline(Out, line);
	istringstream iss3(line);
	iss3 >> eventscount;
	int t=0;

	//reading events
	for (int i = 0; i < eventscount; i++)
	{

		getline(Out, line);
		istringstream iss4(line);
		char l1;
		iss4 >> l1;


		if (l1 == 'R')
		{
			ORD_TYPE mytype;
			REGION myReg;
			int arrTime;
			char l3;
			int ID;
			int dist;  //////
			double money;  /////////
			char l7;
			iss4 >> arrTime;
			iss4 >> l3;
			iss4 >> ID;
			iss4 >> dist;
			iss4 >> money;
			iss4 >> l7;
			if (l3 == 'N') mytype = TYPE_NRM;
			else if (l3 == 'V') mytype = TYPE_VIP;
			else if (l3 == 'F') mytype = TYPE_FROZ;
			else if (l3 == 'S') 
			{
				mytype = TYPE_SCH;
				iss4 >> t;
			}
			if (l7 == 'A') myReg = A_REG;
			else if (l7 == 'B') myReg = B_REG;
			else if (l7 == 'C') myReg = C_REG;
			else if (l7 == 'D') myReg = D_REG;

			//add to queue of events
			Event*pEv = new ArrivalEvent(arrTime, ID, dist, money, mytype, myReg,t);
			AddEvent(pEv);

			////////////////////////////////////////////////////////////////////////////////////////////
			//Order*ptr = new Order(ID, mytype, myReg, dist, arrTime, money);


		}
		else if (l1 == 'P')
		{
			int ID;
			int ExMoney;
			int TimeStep;
			iss4 >> TimeStep;
			iss4 >> ID;
			iss4 >> ExMoney;
			Event* PE = new PromotionEvent(TimeStep, ID, ExMoney);
			//add to queue of events
			AddEvent(PE);


		}
		else if (l1 == 'X')
		{
			int CnclT;
			int ID;
			iss4 >> CnclT;
			iss4 >> ID;
			//add to queue of events
			Event*pEv = new CancellationEvent(CnclT, ID);
			AddEvent(pEv);

		}



	}
	
	return true;

}

Restaurant::Restaurant()
{
	motoID = 1;
	pGUI = new GUI;
	rArr = new Region[4];
	for (int i = 0; i < 4; i++) rArr[i].SetGui(pGUI);

}

void Restaurant::RunSimulation()
{

	PROG_MODE	mode = pGUI->getGUIMode();

	switch (mode)	
	{
	case MODE_INTR:
		InteractiveMode();
		break;
	case MODE_STEP:
		StepMode();
		break;
	case MODE_SLNT:
		SilentMode();
		break;
	};

}

void Restaurant::InteractiveMode()
{

	Order* temp;
	pGUI->ClearStatusBar();
	pGUI->PrintMessage(" Enter the file name: ");
	string s = pGUI->GetString();
	while (!Read(s))
	{
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("File Not Found! Re-Enter file name: ");
		s = pGUI->GetString();

	}
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Your File Was Opened Successfully! Click to start simulation:- ");


	int timestep = 1;

	//finish all events
	while (EventsQueue.isEmpty() == false)
	{

		pGUI->UpdateInterface();
		pGUI->waitForClick();
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("Current Timestep: " + to_string(timestep), 10, 5);

		pGUI->ResetDrawingList();
		ExecuteEvents(timestep);
		promotenormal(timestep);
		returnMotorcycles(timestep);
		returnrestingMotorcycles(timestep);

		int c = 30;
		while (!lasttimestep.isEmpty())
		{
			lasttimestep.dequeue(temp);
			pGUI->PrintMessage("" + temp->getMototype() + "" + to_string(temp->getordMotoID()) + "(" + temp->getTypestr() + "" + to_string(temp->GetID()) + ")", 910, c);
			c += 25;
		}
		serve(timestep);

		for (int reg = 0; reg < 4; reg++)
		{
			Order** temp;
			int s;
			temp = rArr[reg].arrVip(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}
			temp = rArr[reg].arrFrz(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}

			temp = rArr[reg].arrNrm(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}
			temp = rArr[reg].arrSch(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}

		}
		int length = temporders.GetCount();
		for (int i = 0; i < length; i++)
		{
			Order* temp;
			temporders.getEntry(i, temp);
			if (temp->getfinishTime() == timestep)
			{
				temporders.remove(i);
				FinishedOrders.enqueue(temp);
			}
		}
		setserved(timestep);
		//pGUI->ClearStatusBar();
		pGUI->PrintMessage("REGION A: Active/Served Orders:[" + to_string(rArr[0].ReturnNormalO()) + "/" + to_string(rArr[0].getsevedNormal()) + "] normal, [" + to_string(rArr[0].ReturnFrzO()) + "/" + to_string(rArr[0].getservedFrozen()) + "] Forzen, [" + to_string(rArr[0].ReturnVipO()) + "/" + to_string(rArr[0].getservedVIP()) + "] VIP, [" + to_string(rArr[0].returnschO()) + "/" + to_string(rArr[0].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[0].ReturnNMotoNo() - rArr[0].getBusyNmoto()) + "] normal, [" + to_string(rArr[0].ReturnFMotoNo() - rArr[0].getBusyFmoto()) + "] frozen, [" + to_string(rArr[0].ReturnVMotoNo() - rArr[0].getBusyVmoto()) + "] VIP. ", 10, 30);
		pGUI->PrintMessage("REGION B: Active/Served Orders:[" + to_string(rArr[1].ReturnNormalO()) + "/" + to_string(rArr[1].getsevedNormal()) + "] normal, [" + to_string(rArr[1].ReturnFrzO()) + "/" + to_string(rArr[1].getservedFrozen()) + "] Forzen, [" + to_string(rArr[1].ReturnVipO()) + "/" + to_string(rArr[1].getservedVIP()) + "] VIP, [" + to_string(rArr[1].returnschO()) + "/" + to_string(rArr[1].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[1].ReturnNMotoNo() - rArr[1].getBusyNmoto()) + "] normal, [" + to_string(rArr[1].ReturnFMotoNo() - rArr[1].getBusyFmoto()) + "] frozen, [" + to_string(rArr[1].ReturnVMotoNo() - rArr[1].getBusyVmoto()) + "] VIP. ", 10, 55);
		pGUI->PrintMessage("REGION C: Active/Served Orders:[" + to_string(rArr[2].ReturnNormalO()) + "/" + to_string(rArr[2].getsevedNormal()) + "] normal, [" + to_string(rArr[2].ReturnFrzO()) + "/" + to_string(rArr[2].getservedFrozen()) + "] Forzen, [" + to_string(rArr[2].ReturnVipO()) + "/" + to_string(rArr[2].getservedVIP()) + "] VIP, [" + to_string(rArr[2].returnschO()) + "/" + to_string(rArr[2].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[2].ReturnNMotoNo() - rArr[2].getBusyNmoto()) + "] normal, [" + to_string(rArr[2].ReturnFMotoNo() - rArr[2].getBusyFmoto()) + "] frozen, [" + to_string(rArr[2].ReturnVMotoNo() - rArr[2].getBusyVmoto()) + "] VIP. ", 10, 80);
		pGUI->PrintMessage("REGION D: Active/Served Orders:[" + to_string(rArr[3].ReturnNormalO()) + "/" + to_string(rArr[3].getsevedNormal()) + "] normal, [" + to_string(rArr[3].ReturnFrzO()) + "/" + to_string(rArr[3].getservedFrozen()) + "] Forzen, [" + to_string(rArr[3].ReturnVipO()) + "/" + to_string(rArr[3].getservedVIP()) + "] VIP, [" + to_string(rArr[3].returnschO()) + "/" + to_string(rArr[3].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[3].ReturnNMotoNo() - rArr[3].getBusyNmoto()) + "] normal, [" + to_string(rArr[3].ReturnFMotoNo() - rArr[3].getBusyFmoto()) + "] frozen, [" + to_string(rArr[3].ReturnVMotoNo() - rArr[3].getBusyVmoto()) + "] VIP. ", 10, 105);

		timestep++;

		pGUI->UpdateInterface();

	}
	bool check = true;
	while (check)
	{
		pGUI->UpdateInterface();
		pGUI->waitForClick();
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("Current Timestep: " + to_string(timestep), 10, 5);
		pGUI->ResetDrawingList();
		promotenormal(timestep);
		returnMotorcycles(timestep);
		returnrestingMotorcycles(timestep);

		int c = 30;
		while (!lasttimestep.isEmpty())
		{
			lasttimestep.dequeue(temp);
			pGUI->PrintMessage("" + temp->getMototype() + "" + to_string(temp->getordMotoID()) + "(" + temp->getTypestr() + "" + to_string(temp->GetID()) + ")", 910, c);
			c += 25;
		}
		serve(timestep);
		for (int reg = 0; reg < 4; reg++)
		{
			Order** temp;
			int s;
			temp = rArr[reg].arrVip(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}
			temp = rArr[reg].arrFrz(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}

			temp = rArr[reg].arrNrm(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}

			temp = rArr[reg].arrSch(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}
		}

		setserved(timestep);

		pGUI->PrintMessage("REGION A: Active/Served Orders:[" + to_string(rArr[0].ReturnNormalO()) + "/" + to_string(rArr[0].getsevedNormal()) + "] normal, [" + to_string(rArr[0].ReturnFrzO()) + "/" + to_string(rArr[0].getservedFrozen()) + "] Forzen, [" + to_string(rArr[0].ReturnVipO()) + "/" + to_string(rArr[0].getservedVIP()) + "] VIP, [" + to_string(rArr[0].returnschO()) + "/" + to_string(rArr[0].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[0].ReturnNMotoNo() - rArr[0].getBusyNmoto()) + "] normal, [" + to_string(rArr[0].ReturnFMotoNo() - rArr[0].getBusyFmoto()) + "] frozen, [" + to_string(rArr[0].ReturnVMotoNo() - rArr[0].getBusyVmoto()) + "] VIP. ", 10, 30);
		pGUI->PrintMessage("REGION B: Active/Served Orders:[" + to_string(rArr[1].ReturnNormalO()) + "/" + to_string(rArr[1].getsevedNormal()) + "] normal, [" + to_string(rArr[1].ReturnFrzO()) + "/" + to_string(rArr[1].getservedFrozen()) + "] Forzen, [" + to_string(rArr[1].ReturnVipO()) + "/" + to_string(rArr[1].getservedVIP()) + "] VIP, [" + to_string(rArr[1].returnschO()) + "/" + to_string(rArr[1].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[1].ReturnNMotoNo() - rArr[1].getBusyNmoto()) + "] normal, [" + to_string(rArr[1].ReturnFMotoNo() - rArr[1].getBusyFmoto()) + "] frozen, [" + to_string(rArr[1].ReturnVMotoNo() - rArr[1].getBusyVmoto()) + "] VIP. ", 10, 55);
		pGUI->PrintMessage("REGION C: Active/Served Orders:[" + to_string(rArr[2].ReturnNormalO()) + "/" + to_string(rArr[2].getsevedNormal()) + "] normal, [" + to_string(rArr[2].ReturnFrzO()) + "/" + to_string(rArr[2].getservedFrozen()) + "] Forzen, [" + to_string(rArr[2].ReturnVipO()) + "/" + to_string(rArr[2].getservedVIP()) + "] VIP, [" + to_string(rArr[2].returnschO()) + "/" + to_string(rArr[2].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[2].ReturnNMotoNo() - rArr[2].getBusyNmoto()) + "] normal, [" + to_string(rArr[2].ReturnFMotoNo() - rArr[2].getBusyFmoto()) + "] frozen, [" + to_string(rArr[2].ReturnVMotoNo() - rArr[2].getBusyVmoto()) + "] VIP. ", 10, 80);
		pGUI->PrintMessage("REGION D: Active/Served Orders:[" + to_string(rArr[3].ReturnNormalO()) + "/" + to_string(rArr[3].getsevedNormal()) + "] normal, [" + to_string(rArr[3].ReturnFrzO()) + "/" + to_string(rArr[3].getservedFrozen()) + "] Forzen, [" + to_string(rArr[3].ReturnVipO()) + "/" + to_string(rArr[3].getservedVIP()) + "] VIP, [" + to_string(rArr[3].returnschO()) + "/" + to_string(rArr[3].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[3].ReturnNMotoNo() - rArr[3].getBusyNmoto()) + "] normal, [" + to_string(rArr[3].ReturnFMotoNo() - rArr[3].getBusyFmoto()) + "] frozen, [" + to_string(rArr[3].ReturnVMotoNo() - rArr[3].getBusyVmoto()) + "] VIP. ", 10, 105);
		pGUI->UpdateInterface();
		int length = temporders.GetCount();
		for (int i = 0; i < length; i++)
		{
			Order* temp;
			temporders.getEntry(i, temp);
			if (temp->getfinishTime() == timestep)
			{
				temporders.remove(i);
				FinishedOrders.enqueue(temp);
			}
		}
		timestep++;

		if (rArr[0].emptyOrders() && rArr[0].FreeMotors() && rArr[1].emptyOrders() && rArr[1].FreeMotors() && rArr[2].emptyOrders() && rArr[2].FreeMotors() && rArr[3].emptyOrders() && rArr[3].FreeMotors())
		{
			check = false;
		}


	}
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("End of Simulation. Click to finish");
	Save();
	pGUI->waitForClick();


	exit(0);

}

void Restaurant::StepMode()
{


	Order* temp;
	pGUI->ClearStatusBar();
	pGUI->PrintMessage(" Enter the file name: ");
	string s = pGUI->GetString();
	while (!Read(s))
	{
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("File Not Found! Re-Enter file name: ");
		s = pGUI->GetString();

	}
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Your File Was Opened Successfully! Click to start simulation:- ");


	int timestep = 1;

	//finish all events
	while (EventsQueue.isEmpty() == false)
	{

		pGUI->UpdateInterface();
		Sleep(1000);
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("Current Timestep: " + to_string(timestep), 10, 5);

		pGUI->ResetDrawingList();
		ExecuteEvents(timestep);
		promotenormal(timestep);
		returnMotorcycles(timestep);
		returnrestingMotorcycles(timestep);

		int c = 30;
		while (!lasttimestep.isEmpty())
		{
			lasttimestep.dequeue(temp);
			pGUI->PrintMessage("" + temp->getMototype() + "" + to_string(temp->getordMotoID()) + "(" + temp->getTypestr() + "" + to_string(temp->GetID()) + ")", 910, c);
			c += 25;
		}
		serve(timestep);

		for (int reg = 0; reg < 4; reg++)
		{
			Order** temp;
			int s;
			temp = rArr[reg].arrVip(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}
			temp = rArr[reg].arrFrz(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}

			temp = rArr[reg].arrNrm(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}

			temp = rArr[reg].arrSch(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}
		}
		int length = temporders.GetCount();
		for (int i = 0; i < length; i++)
		{
			Order* temp;
			temporders.getEntry(i, temp);
			if (temp->getfinishTime() == timestep)
			{
				temporders.remove(i);
				FinishedOrders.enqueue(temp);
			}
		}
		setserved(timestep);

		pGUI->PrintMessage("REGION A: Active/Served Orders:[" + to_string(rArr[0].ReturnNormalO()) + "/" + to_string(rArr[0].getsevedNormal()) + "] normal, [" + to_string(rArr[0].ReturnFrzO()) + "/" + to_string(rArr[0].getservedFrozen()) + "] Forzen, [" + to_string(rArr[0].ReturnVipO()) + "/" + to_string(rArr[0].getservedVIP()) + "] VIP, [" + to_string(rArr[0].returnschO()) + "/" + to_string(rArr[0].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[0].ReturnNMotoNo() - rArr[0].getBusyNmoto()) + "] normal, [" + to_string(rArr[0].ReturnFMotoNo() - rArr[0].getBusyFmoto()) + "] frozen, [" + to_string(rArr[0].ReturnVMotoNo() - rArr[0].getBusyVmoto()) + "] VIP. ", 10, 30);
		pGUI->PrintMessage("REGION B: Active/Served Orders:[" + to_string(rArr[1].ReturnNormalO()) + "/" + to_string(rArr[1].getsevedNormal()) + "] normal, [" + to_string(rArr[1].ReturnFrzO()) + "/" + to_string(rArr[1].getservedFrozen()) + "] Forzen, [" + to_string(rArr[1].ReturnVipO()) + "/" + to_string(rArr[1].getservedVIP()) + "] VIP, [" + to_string(rArr[1].returnschO()) + "/" + to_string(rArr[1].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[1].ReturnNMotoNo() - rArr[1].getBusyNmoto()) + "] normal, [" + to_string(rArr[1].ReturnFMotoNo() - rArr[1].getBusyFmoto()) + "] frozen, [" + to_string(rArr[1].ReturnVMotoNo() - rArr[1].getBusyVmoto()) + "] VIP. ", 10, 55);
		pGUI->PrintMessage("REGION C: Active/Served Orders:[" + to_string(rArr[2].ReturnNormalO()) + "/" + to_string(rArr[2].getsevedNormal()) + "] normal, [" + to_string(rArr[2].ReturnFrzO()) + "/" + to_string(rArr[2].getservedFrozen()) + "] Forzen, [" + to_string(rArr[2].ReturnVipO()) + "/" + to_string(rArr[2].getservedVIP()) + "] VIP, [" + to_string(rArr[2].returnschO()) + "/" + to_string(rArr[2].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[2].ReturnNMotoNo() - rArr[2].getBusyNmoto()) + "] normal, [" + to_string(rArr[2].ReturnFMotoNo() - rArr[2].getBusyFmoto()) + "] frozen, [" + to_string(rArr[2].ReturnVMotoNo() - rArr[2].getBusyVmoto()) + "] VIP. ", 10, 80);
		pGUI->PrintMessage("REGION D: Active/Served Orders:[" + to_string(rArr[3].ReturnNormalO()) + "/" + to_string(rArr[3].getsevedNormal()) + "] normal, [" + to_string(rArr[3].ReturnFrzO()) + "/" + to_string(rArr[3].getservedFrozen()) + "] Forzen, [" + to_string(rArr[3].ReturnVipO()) + "/" + to_string(rArr[3].getservedVIP()) + "] VIP, [" + to_string(rArr[3].returnschO()) + "/" + to_string(rArr[3].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[3].ReturnNMotoNo() - rArr[3].getBusyNmoto()) + "] normal, [" + to_string(rArr[3].ReturnFMotoNo() - rArr[3].getBusyFmoto()) + "] frozen, [" + to_string(rArr[3].ReturnVMotoNo() - rArr[3].getBusyVmoto()) + "] VIP. ", 10, 105);

		timestep++;

		pGUI->UpdateInterface();

	}
	bool check = true;
	while (check)
	{
		pGUI->UpdateInterface();
		Sleep(1000);
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("Current Timestep: " + to_string(timestep), 10, 5);
		pGUI->ResetDrawingList();
		promotenormal(timestep);
		returnMotorcycles(timestep);
		returnrestingMotorcycles(timestep);

		int c = 30;
		while (!lasttimestep.isEmpty())
		{
			lasttimestep.dequeue(temp);
			pGUI->PrintMessage("" + temp->getMototype() + "" + to_string(temp->getordMotoID()) + "(" + temp->getTypestr() + "" + to_string(temp->GetID()) + ")", 910, c);
			c += 25;
		}
		serve(timestep);
		for (int reg = 0; reg < 4; reg++)
		{
			Order** temp;
			int s;
			temp = rArr[reg].arrVip(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}
			temp = rArr[reg].arrFrz(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}

			temp = rArr[reg].arrNrm(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}

			temp = rArr[reg].arrSch(s);
			for (int i = 0; i < s; i++)
			{
				pGUI->AddOrderForDrawing(temp[i]);
				pGUI->UpdateInterface();
			}
		}
		setserved(timestep);

		pGUI->PrintMessage("REGION A: Active/Served Orders:[" + to_string(rArr[0].ReturnNormalO()) + "/" + to_string(rArr[0].getsevedNormal()) + "] normal, [" + to_string(rArr[0].ReturnFrzO()) + "/" + to_string(rArr[0].getservedFrozen()) + "] Forzen, [" + to_string(rArr[0].ReturnVipO()) + "/" + to_string(rArr[0].getservedVIP()) + "] VIP, [" + to_string(rArr[0].returnschO()) + "/" + to_string(rArr[0].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[0].ReturnNMotoNo() - rArr[0].getBusyNmoto()) + "] normal, [" + to_string(rArr[0].ReturnFMotoNo() - rArr[0].getBusyFmoto()) + "] frozen, [" + to_string(rArr[0].ReturnVMotoNo() - rArr[0].getBusyVmoto()) + "] VIP. ", 10, 30);
		pGUI->PrintMessage("REGION B: Active/Served Orders:[" + to_string(rArr[1].ReturnNormalO()) + "/" + to_string(rArr[1].getsevedNormal()) + "] normal, [" + to_string(rArr[1].ReturnFrzO()) + "/" + to_string(rArr[1].getservedFrozen()) + "] Forzen, [" + to_string(rArr[1].ReturnVipO()) + "/" + to_string(rArr[1].getservedVIP()) + "] VIP, [" + to_string(rArr[1].returnschO()) + "/" + to_string(rArr[1].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[1].ReturnNMotoNo() - rArr[1].getBusyNmoto()) + "] normal, [" + to_string(rArr[1].ReturnFMotoNo() - rArr[1].getBusyFmoto()) + "] frozen, [" + to_string(rArr[1].ReturnVMotoNo() - rArr[1].getBusyVmoto()) + "] VIP. ", 10, 55);
		pGUI->PrintMessage("REGION C: Active/Served Orders:[" + to_string(rArr[2].ReturnNormalO()) + "/" + to_string(rArr[2].getsevedNormal()) + "] normal, [" + to_string(rArr[2].ReturnFrzO()) + "/" + to_string(rArr[2].getservedFrozen()) + "] Forzen, [" + to_string(rArr[2].ReturnVipO()) + "/" + to_string(rArr[2].getservedVIP()) + "] VIP, [" + to_string(rArr[2].returnschO()) + "/" + to_string(rArr[2].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[2].ReturnNMotoNo() - rArr[2].getBusyNmoto()) + "] normal, [" + to_string(rArr[2].ReturnFMotoNo() - rArr[2].getBusyFmoto()) + "] frozen, [" + to_string(rArr[2].ReturnVMotoNo() - rArr[2].getBusyVmoto()) + "] VIP. ", 10, 80);
		pGUI->PrintMessage("REGION D: Active/Served Orders:[" + to_string(rArr[3].ReturnNormalO()) + "/" + to_string(rArr[3].getsevedNormal()) + "] normal, [" + to_string(rArr[3].ReturnFrzO()) + "/" + to_string(rArr[3].getservedFrozen()) + "] Forzen, [" + to_string(rArr[3].ReturnVipO()) + "/" + to_string(rArr[3].getservedVIP()) + "] VIP, [" + to_string(rArr[3].returnschO()) + "/" + to_string(rArr[3].getservedsch()) + "] Sched.-- Motorcycles: [" + to_string(rArr[3].ReturnNMotoNo() - rArr[3].getBusyNmoto()) + "] normal, [" + to_string(rArr[3].ReturnFMotoNo() - rArr[3].getBusyFmoto()) + "] frozen, [" + to_string(rArr[3].ReturnVMotoNo() - rArr[3].getBusyVmoto()) + "] VIP. ", 10, 105);
		pGUI->UpdateInterface();
		int length = temporders.GetCount();
		for (int i = 0; i < length; i++)
		{
			Order* temp;
			temporders.getEntry(i, temp);
			if (temp->getfinishTime() == timestep)
			{
				temporders.remove(i);
				FinishedOrders.enqueue(temp);
			}
		}
		timestep++;

		if (rArr[0].emptyOrders() && rArr[0].FreeMotors() && rArr[1].emptyOrders() && rArr[1].FreeMotors() && rArr[2].emptyOrders() && rArr[2].FreeMotors() && rArr[3].emptyOrders() && rArr[3].FreeMotors())
		{
			check = false;
		}


	}
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("End of Simulation. Click to finish");
	Save();
	pGUI->waitForClick();


	exit(0);



}

void Restaurant::SilentMode()
{

	Order* temp;
	pGUI->ClearStatusBar();
	pGUI->PrintMessage(" Enter the file name: ");

	string s = pGUI->GetString();
	while (!Read(s))
	{
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("File Not Found! Re-Enter file name: ");
		s = pGUI->GetString();

	}
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Your File Was Opened Successfully! Click to start simulation:- ");


	int timestep = 1;

	//finish all events
	while (EventsQueue.isEmpty() == false)
	{
		pGUI->ResetDrawingList();
		ExecuteEvents(timestep);
		promotenormal(timestep);
		returnMotorcycles(timestep);
		returnrestingMotorcycles(timestep);

		int c = 30;
		while (!lasttimestep.isEmpty())
		{
			lasttimestep.dequeue(temp);
			pGUI->PrintMessage("" + temp->getMototype() + "" + to_string(temp->getordMotoID()) + "(" + temp->getTypestr() + "" + to_string(temp->GetID()) + ")", 810, c);
			c += 25;
		}
		serve(timestep);

		int length = temporders.GetCount();
		for (int i = 0; i < length; i++)
		{
			Order* temp;
			temporders.getEntry(i, temp);
			if (temp->getfinishTime() == timestep)
			{
				temporders.remove(i);
				FinishedOrders.enqueue(temp);
			}
		}
		setserved(timestep);

		timestep++;

	}
	bool check = true;
	while (check)
	{
		pGUI->UpdateInterface();
		pGUI->ResetDrawingList();
		promotenormal(timestep);
		returnMotorcycles(timestep);
		returnrestingMotorcycles(timestep);

		int c = 30;
		while (!lasttimestep.isEmpty())
		{
			lasttimestep.dequeue(temp);
			pGUI->PrintMessage("" + temp->getMototype() + "" + to_string(temp->getordMotoID()) + "(" + temp->getTypestr() + "" + to_string(temp->GetID()) + ")", 810, c);
			c += 25;
		}
		serve(timestep);

		int length = temporders.GetCount();
		for (int i = 0; i < length; i++)
		{
			Order* temp;
			temporders.getEntry(i, temp);
			if (temp->getfinishTime() == timestep)
			{
				temporders.remove(i);
				FinishedOrders.enqueue(temp);
			}
		}
		setserved(timestep);

		timestep++;

		if (rArr[0].emptyOrders() && rArr[0].FreeMotors() && rArr[1].emptyOrders() && rArr[1].FreeMotors() && rArr[2].emptyOrders() && rArr[2].FreeMotors() && rArr[3].emptyOrders() && rArr[3].FreeMotors())
		{
			check = false;
		}


	}
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("End of Simulation. Click to finish");
	Save();
	pGUI->waitForClick();


	exit(0);





}

void Restaurant::AddtoOrders(Order * po, int ts)
{
	if(po->GetType()==TYPE_SCH)
		setscheduled(po);
	//cout << po->getexptimestep();
	rArr[po->RegionInd()].addOrder(po,ts);
	



}

void Restaurant::CancelEvent(int id)
{
	for (int i = 0; i < 4; i++)
	{
		Order*del = rArr[i].GetOrder(id);
		if (del != NULL)
		{
			rArr[i].DeleteOrder(del);
			return;
		}

	}

}

bool Restaurant::endOfOrders() const
{
	for (int reg = 0; reg < 4; reg++)
	{
		if (rArr[reg].emptyOrders() == false)
			return false;
	}
	return true;
}

void Restaurant::PromoteEvent(int Time, int ID, double ExtraMoney)
{
	REGION myreg;
	double Money;
	int Dist;

	for (int i = 0; i < 4; i++)
	{
		Order* del = NULL;
		del = rArr[i].GetOrder(ID);

		if (del != NULL)
		{
			Dist = del->GetDistance();
			Money = del->GetMoney();
			myreg = del->GetRegion();
			Order* Promoted = new Order(ID, TYPE_VIP, myreg, Dist, Time, Money + ExtraMoney);
			rArr[i].addOrder(Promoted);
			rArr[i].DeleteOrder(del);
			return;
		}

	}

}

void Restaurant::serve(int timestep)
{
	for (int reg = 0; reg < 4; reg++)
	{
		Order* O;
		Motorcycle*M;
		int tempserving;
		bool checkN = true;
		bool checkF = true;
		bool checkV = true;
		bool checkS = true;

		while (checkV)
		{
			if (rArr[reg].serveVIP(O, M, checkV, timestep))
			{
				tempserving = O->GetDistance() / M->getspeed();
				O->setservTime(timestep);
				O->setfinishTime(timestep + tempserving);
				O->setwaitingperiod(timestep - O->getarrivalTime());
				O->setserviceperiod(tempserving);
				temporders.insertEnd(O);
				M->setReturnTimestep(O->getfinishTime() + O->getservicePeriod());
				rArr[reg].incserving(tempserving);
				rArr[reg].incwaiting(timestep - O->getarrivalTime());
				lasttimestep.enqueue(O);
				rArr[reg].addserving(O);
			}
		}
		while (checkF)
		{
			if (rArr[reg].serveFrozen(O, M, checkF, timestep))
			{
				tempserving = O->GetDistance() / M->getspeed();
				O->setservTime(timestep);
				O->setfinishTime(timestep + tempserving);
				O->setwaitingperiod(timestep - O->getarrivalTime());
				O->setserviceperiod(tempserving);
				temporders.insertEnd(O);
				M->setReturnTimestep(O->getfinishTime() + O->getservicePeriod());
				rArr[reg].incserving(tempserving);
				rArr[reg].incwaiting(timestep - O->getarrivalTime());
				lasttimestep.enqueue(O);
				rArr[reg].addserving(O);

			}
		}


		while (checkN)
		{
			if (rArr[reg].serveNormal(O, M, checkN, timestep))
			{
				tempserving = O->GetDistance() / M->getspeed();
				O->setservTime(timestep);
				O->setfinishTime(timestep + tempserving);
				O->setwaitingperiod(timestep - O->getarrivalTime());
				O->setserviceperiod(tempserving);
				temporders.insertEnd(O);
				M->setReturnTimestep(O->getfinishTime() + O->getservicePeriod());
				rArr[reg].incserving(tempserving);
				rArr[reg].incwaiting(timestep - O->getarrivalTime());
				lasttimestep.enqueue(O);
				rArr[reg].addserving(O);

			}
		}
		while (checkS)
		{
			if (rArr[reg].serveScheduled(O, M, checkS, timestep))
			{
				tempserving = O->GetDistance() / M->getspeed();
				O->setservTime(timestep);
				O->setfinishTime(timestep + tempserving);
				O->setwaitingperiod(timestep - O->getarrivalTime());
				O->setserviceperiod(tempserving);
				temporders.insertEnd(O);
				M->setReturnTimestep(O->getfinishTime() + O->getservicePeriod());
				rArr[reg].incserving(tempserving);
				rArr[reg].incwaiting(timestep - O->getarrivalTime());
				lasttimestep.enqueue(O);
				rArr[reg].addserving(O);

			}
		}



	}
}

void Restaurant::returnMotorcycles(int timestep)
{
	for (int i = 0; i < 4; i++)
	{
		rArr[i].returnMoto(timestep);
	}
}





//////////////////////////////////  Event handling functions   /////////////////////////////
void Restaurant::AddEvent(Event* pE)	//adds a new event to the queue of events
{
	EventsQueue.enqueue(pE);
}

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while (EventsQueue.peekFront(pE))	//as long as there are more events
	{
		if (pE->getEventTime() > CurrentTimeStep)	//no more events at current time
			return;


		pE->Execute(this, CurrentTimeStep);

		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;		//deallocate event object from memory
	}

}


Restaurant::~Restaurant()
{
	delete pGUI;
	delete[]rArr;
}

void Restaurant::promotenormal(int ts)
{
	Order* temp = NULL;
	int s;

	for (int reg = 0; reg < 4; reg++)
	{
		s = rArr[reg].GetNrmCount();
		for (int j = 0; j < s; j++)

		{
			temp = rArr[reg].getNormal(j);
			if (temp != NULL)
			{
				int waitingTime = ts - temp->getarrivalTime();
				if (waitingTime == Prom)
				{
					Event* MyEvent = new PromotionEvent(ts, temp->GetID(), 0);
					MyEvent->Execute(this);
					j--;
				}
			}
		}
	}
}

void Restaurant::setscheduled(Order * pO)
{
	switch (pO->GetRegion())
	{
	case(A_REG):
		if (rArr[A_REG].getavgnormalspeed()==0)
		{
			pO->setexptimestep(0);
			return;
		}
		pO->setexptimestep(pO->getfinishTime()- pO->GetDistance() / rArr[A_REG].getavgnormalspeed());
	
		return;

	case(B_REG):
		if (rArr[B_REG].getavgnormalspeed() == 0)
		{
			pO->setexptimestep(0);
			return;
		}
		pO->setexptimestep(pO->getfinishTime() - pO->GetDistance() / rArr[B_REG].getavgnormalspeed());
		return;

	case(C_REG):
		if (rArr[C_REG].getavgnormalspeed() == 0)
		{
			pO->setexptimestep(0);
			return;
		}
		pO->setexptimestep(pO->getfinishTime() - pO->GetDistance() / rArr[C_REG].getavgnormalspeed());
		return;

	case(D_REG):
		if (rArr[D_REG].getavgnormalspeed() == 0)
		{
			pO->setexptimestep(0);
			return;
		}
		pO->setexptimestep(pO->getfinishTime() - pO->GetDistance() / rArr[D_REG].getavgnormalspeed());
		return;

	default:
		return;
	}
}

void Restaurant::returnrestingMotorcycles(int timestep)
{
	for (int i = 0; i < 4; i++)
	{
		rArr[i].returnRest(timestep);
	}
}

void Restaurant::setserved(int timestep)
{
	for (int i = 0; i < 4; i++)
	{
		rArr[i].tellserved(timestep);
	}

}

