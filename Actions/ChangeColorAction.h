#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ChangeColorAction :public Action
{
	color colour;
	int drawfill;
	CFigure* fig;
public:
	ChangeColorAction(ApplicationManager* pApp, color c, int draworfill, CFigure* figure);
	virtual void ReadActionParameters();
	virtual void Execute();
};