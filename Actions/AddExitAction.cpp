#include "AddExitAction.h"

AddExitAction::AddExitAction(ApplicationManager* pApp) :Action(pApp)
{

}
//Reads parameters required for action to execute (code depends on action type)
void AddExitAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
}

//Execute action (code depends on action type)
void AddExitAction::Execute()
{

	pManager->ClearAll();
}