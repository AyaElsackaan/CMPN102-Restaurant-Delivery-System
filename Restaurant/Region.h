#pragma once
#include"Rest/Order.h"
#include "ListLinkedList.h"
#include"PriorityQueue.h"
#include"Generic_DS/Queue.h"
#include"Rest/Motorcycle.h"
#include "SortedListLinkedList.h"
#include "GUI/GUI.h"
class Region
{
	int servNmotors, servVmotors, servFmotors, VIPMotoCount, FrozenMotoCount, NormalMotoCount,servedNormal,servedSched,/*servedCombo,*/servedFrozen,servedVIP,totalwaiting,totalserving;

	int avgspeedNormal;
	ListLinkedList<Order*> NormalOrders;
	PriorityQueue<Order*> VIPOrders;
	Queue<Order*> FrozenOrders;
	PriorityQueue<Order*> SchedOrders;
		//Queue<Order*> ComboOrders;


	SortedListLinkedList<Motorcycle*> NormalMoto;
	SortedListLinkedList<Motorcycle*> FrozenMoto;
	SortedListLinkedList<Motorcycle*> VIPMoto;
	GUI* pGUI;
	ListLinkedList<Order*> Serving;

public:

	Region();
	// Getters
	Order* getNormal(int);
	Order*GetOrder(int ID);
	Motorcycle* GetMotor(int ID);
	int getBusyNmoto();
	int getBusyVmoto();
	int getBusyFmoto();
	int GetNrmCount();
	int ReturnVMotoNo();
	int ReturnFMotoNo();
	int ReturnNMotoNo();
	int ReturnVipO();
	int ReturnNormalO();
	int ReturnFrzO();
	int returnschO();
	int getsevedNormal();
	int getservedFrozen();
	int getservedVIP();
	int getservedsch();
	int getavgnormalspeed();

	//int getservedCombo();
	int getservedSched();
	int getscheduledcount();
	//int getCombocount();

	double getavgwaiting();
	double getavgserving();
	//Setters
	void setavgspeedNormal();
	void incwaiting(int);
//	void setscheduled(Order*pO);
	void incserving(int);
	void SetGui(GUI* ptr);
	void setnormal(int normal); //no of normal motorcycles
	void setfrozen(int frozen); //no of frozen motorcycles
	void setVIP(int vip);  //no of VIP motorcycles
	
	void DeleteOrder(Order* ptr);
	void addOrder( Order* po, int ts=0); //add an order to the suitable list
	void removeOrder(Order*po); //remove a given pointer 

	void addMoto(Motorcycle* pM); //fill motorcycles lists
	void testremoveNorm();
	void testremoveFrz();
	void testremoveVip();
	Order**arrFrz(int&n);
	Order**arrNrm(int&);
	Order** arrVip(int&);
	Order**arrSch(int&n);

	bool emptyfrozen()const;
	bool emptynormal()const;
	bool emptyVip()const;
	bool emptysch()const;

	bool emptyOrders()const;

	bool serveVIP(Order*&servedOrd, Motorcycle*&servingMoto, bool&, int);
	bool serveNormal(Order*&servedOrd, Motorcycle*&servingMoto, bool &check, int);
	bool serveFrozen(Order*&servedOrd, Motorcycle*&servingMoto, bool&check, int ts);
	bool serveScheduled(Order*&servedOrd, Motorcycle*&servingMoto, bool&check, int ts);

	void returnMoto(int timestep);
	void returnRest(int) ;
	bool getFirstVIPMoto(Motorcycle*&);
	bool getFirstNormalMoto(Motorcycle*&);
	bool getFirstFrozenMoto(Motorcycle*&);
	bool FreeMotors();
	void decNmoto();
	void decFmoto();
	void decVmoto();
	void addserving(Order*);
	void tellserved(int);
	~Region();

};

