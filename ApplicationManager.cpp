#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddTrigAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddExitAction.h"
#include "Actions\SelectAction.h"
#include "Actions\BringtoFront.h"
#include "Actions\ChangeColorAction.h"
#include "Actions\DelAction.h"




//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	

	countrect = 0;
	counttrig = 0;
	countsquare = 0;
	countcirc = 0;
	counthex = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case EXIT:
		///create ExitAction here
		pAct = new AddExitAction(this);
		break;

	case DRAW_HEX:
		pAct = new AddHexAction(this);
		break;

	case DRAW_SQUARE: 
		pAct = new AddSquareAction(this);
		break;

	case DRAW_CIRCLE: 
		pAct = new AddCircleAction(this);
		break;

	case DRAW_TRIANGLE: 
		pAct = new AddTrigAction(this);
		break;

	case SELECT:
		pAct = new SelectAction(this);
		break;

	case SENDTOBACK:
		pAct = new BringtoFront(this);
		break;

	case FILL_SHAPE: //expanding the fill colors menu
		DORF = 2;
		pOut->PrintTempMessge("select drawing color", 2500);
		break; 

	case COLOR_BORDER: //expanding the border colors menu 
		DORF = 1;
		pOut->PrintTempMessge("select drawing color", 2500);
		break;

	case PICK_GREEN: 
		figure = GetSelectedFigureByFlag(selectedIndex, selectedNum);
		pAct = new ChangeColorAction(this,GREEN,DORF,figure);
		break;
	case PICK_RED:
		figure = GetSelectedFigureByFlag(selectedIndex, selectedNum);
		pAct = new ChangeColorAction(this, RED, DORF, figure);
		break;
	case PICK_BLUE:
		figure = GetSelectedFigureByFlag(selectedIndex, selectedNum);
		pAct = new ChangeColorAction(this, BLUE, DORF, figure);
		break;
	case PICK_ORANGE:
		figure = GetSelectedFigureByFlag(selectedIndex, selectedNum);
		pAct = new ChangeColorAction(this, ORANGE, DORF, figure);
		break;
	case PICK_YELLOW:
		figure = GetSelectedFigureByFlag(selectedIndex, selectedNum);
		pAct = new ChangeColorAction(this, YELLOW, DORF, figure);
		break;
	case PICK_BLACK:
		figure = GetSelectedFigureByFlag(selectedIndex, selectedNum);
		pAct = new ChangeColorAction(this, BLACK, DORF, figure);
		break;
	/*
	case CLEAR_ALL:
		pAct = new ClearAllAction(this);
		break;*/

	case DELETE_FIG:
		pAct = new DelAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//


string ApplicationManager::getShapeTypeString(shape shapeType) {
	switch (shapeType) {
	case rectangle: return "Rectangle";
	case triangle: return "Triangle";
	case square: return "Square";
	case circle: return "Circle";
	case hexagon: return "Hexagon";
	default: return "Unknown";
	}
}
//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;

	
}




void ApplicationManager::ClearAll(){

	UI.IsFilled = false;
	UI.DrawColor = BLUE;    //Drawing color
	UI.FillColor = GREEN;    //Filling color
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(Point P1) const
{
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->IsPointInside(P1))
		{
			return FigList[i];
		}
	}
	return NULL;
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}


CFigure* ApplicationManager::GetSelectedFig()const
{
	return SelectedFig;
}

void ApplicationManager::SetSelectedFig(CFigure* F)
{
	SelectedFig = F;
}

 
void ApplicationManager::ClearSelection() {
	
  for (int i = 0;i < FigCount;i++) {
		if (FigList[i]->IsSelected()) {
		FigList[i]->SetSelected(false);

	}
}
}

int ApplicationManager::calculateSelectedCount(int& selectedIndex, int& count) const {
	count = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			selectedIndex = i;
			count++;
		}
	}
	return count;
}

CFigure* ApplicationManager::GetSelectedFigureByFlag(int& selectedIndex, int& selectedNum)     //get one selected figure by checking isSelected prop
{
	selectedNum = 0;
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->IsSelected())
		{
			selectedIndex = i;
			selectedNum++;
		}
	}
	if (selectedNum == 0)
	{
		// if no figure is selected return null
		return NULL;
	}
	else
	{
		return FigList[selectedIndex];
	}
}


void ApplicationManager::printSelectedSummary() {
	string message = "You have selected: ";
	if(countrect>0)
	message += std::to_string( countrect ) + " " + " Rectangle ";
	if (counttrig > 0)
		message += std::to_string( counttrig ) + " " + " Triangle ";
	if (countcirc > 0)
		message += std::to_string( countcirc ) + " " + " Circle ";
	if (counthex > 0)
		message += std::to_string( counthex ) + " " + " Hexagon ";
	if (countsquare > 0)
		message += std::to_string( countsquare ) + " " + " Square ";
	pOut->PrintMessage(message);
	
}

void ApplicationManager::InsertFigure(bool isFront)          //insert figure in front or back of all figuers
{
	int selectedIndex, selectedNum;
	CFigure* temp = GetSelectedFigureByFlag(selectedIndex, selectedNum);
	if (temp == NULL)
	{
		pOut->PrintTempMessge("No selected figure to move!", 1000); //added temp msg to be removed after 1000 ms the code is in output
	}
	else if (selectedNum > 1)
	{
		pOut->PrintTempMessge("Select only one figure to move!", 1000);
	}
	else
	{
		if (isFront)
		{
			for (int i = selectedIndex; i < FigCount; i++)
			{
				FigList[i] = FigList[i + 1];
			}
			FigList[FigCount - 1] = temp;
			pOut->PrintMessage("Figure brought to front!");
		}
		else
		{
			for (int i = selectedIndex; i >= 0; i--)
			{
				FigList[i] = FigList[i - 1];
			}
			FigList[0] = temp;
			pOut->PrintMessage("Figure sent to back!");
		}
	}
}


void ApplicationManager::RearrangingFigList()         //removing null refrences from FigList
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == NULL)
		{
			//shifting all upcoming figures to remove the null refrenece
			for (int j = i; j < FigCount - 1; j++)
			{
				FigList[j] = FigList[j + 1];
			}
		}
	}
}

void ApplicationManager::BringForward(int index) {
	CFigure* temp = FigList[index];
	for (int i = index; i < FigCount - 1; i++) {
		FigList[i] = FigList[i + 1];
	}
	FigList[FigCount - 1] = temp;
}

void ApplicationManager::BringBackward(int index) { 
	CFigure* temp = FigList[index];
	for (int i = index; i > 0; i--) {
		FigList[i] = FigList[i - 1];
	}
	FigList[0] = temp;
}

bool ApplicationManager::CanBringForward(int index) {
	return index < FigCount - 1;
}

bool ApplicationManager::CanBringBackward(int index) {
	return index > 0;
}

int ApplicationManager::getSelectedFigInd() const
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}



void ApplicationManager::DeleteSelectedFigure() {
	int index = 0;

	// Shift elements to remove the deleted figure from the array
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			delete FigList[i];
			FigList[i] = NULL;
			index++;
		}
	}
	RearrangingFigList();
	FigCount -= index;
}


