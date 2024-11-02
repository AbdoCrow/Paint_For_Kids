#pragma once
#ifndef ADD_Trig_ACTION_H
#define ADD_Trig_ACTION_H

#include "Action.h"
class AddTrigAction : public Action
{
private:
	Point P1; //Triangle Corners
	Point P2;
	Point P3;
	GfxInfo TrigGfxInfo;
public:
	AddTrigAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif


