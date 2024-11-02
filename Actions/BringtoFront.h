#pragma once
#include "Action.h"


class BringtoFront : public Action
{
	Point P;
	
public:
	BringtoFront(ApplicationManager* pApp);
	
	virtual void ReadActionParameters();
	virtual void Execute();
};




