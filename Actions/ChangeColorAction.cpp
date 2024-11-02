#include "ChangeColorAction.h"

ChangeColorAction::ChangeColorAction(ApplicationManager* pApp,color c,int draworfill,CFigure* figure) : Action(pApp),colour(c),drawfill(draworfill),fig(figure) {}

void ChangeColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Color : Please select a figure to color");
	
	pOut->ClearStatusBar();
}

void ChangeColorAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	if (drawfill==1) {
		if (fig != NULL)
			fig->ChngDrawClr(colour);
		else
			UI.DrawColor = colour;
		pManager->UpdateInterface();
	}
	else
		if (drawfill == 2) {
			if(fig != NULL)
				fig->ChngFillClr(colour);
			else {
				UI.FillColor = colour;
			}
			pManager->UpdateInterface();
		}
}