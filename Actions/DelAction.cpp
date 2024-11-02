#include "DelAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>

DelAction::DelAction(ApplicationManager* pApp) :Action(pApp) {}

void DelAction::ReadActionParameters()
{}

void DelAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelectedFig() == 0)
	{
		pOut->PrintMessage("Please select a figure first");

	}
	else
		pManager->DeleteSelectedFigure();
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	pOut->PrintMessage("The figure is deleted");

}
