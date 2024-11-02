#include "AddTrigAction.h"
#include "..\Figures\CTrig.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTrigAction::AddTrigAction(ApplicationManager* pApp) :Action(pApp)
{}
void AddTrigAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at the first point");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at the second point");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at the third point");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P3.x, P3.y);


	TrigGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TrigGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TrigGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
void AddTrigAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CTrig* H = new CTrig(P1,P2,P3, TrigGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(H);
}


