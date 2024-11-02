#pragma once
#ifndef ADD_Square_ACTION_H
#define ADD_Square_ACTION_H

#include "Action.h"

class AddSquareAction: public Action
{
private:
    Point P1; // Two points defining the square 
    GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};

#endif