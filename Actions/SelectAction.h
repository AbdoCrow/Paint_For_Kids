#pragma once
#include "Action.h"
class SelectAction :public Action
{
private:
	Point P;
public:
	SelectAction(ApplicationManager* pApp);
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};

