#pragma once
#ifndef ADD_Hex_ACTION_H
#define ADD_Hex_ACTION_H

#include "Action.h"
class AddHexAction: public Action
{
private:
	Point P1; //Rectangle Corners
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif


