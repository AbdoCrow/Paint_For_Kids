#include "BringtoFront.h"

#include "..\ApplicationManager.h"





BringtoFront::BringtoFront(ApplicationManager* pApp) : Action(pApp)
{
   
}
void BringtoFront::ReadActionParameters()
{
    
}

//Execute the action
void BringtoFront::Execute()
{
    Output* pOut = pManager->GetOutput();
    int selectedIndex, selectedNum;
    CFigure* selectedFig = pManager->GetSelectedFigureByFlag(selectedIndex, selectedNum);

    // Check if valid
    if (selectedFig == nullptr) {
        pOut->PrintMessage("No selected figure to move.");
    }
    else if (selectedNum != 1) {
        pOut->PrintMessage("Please select only one figure.");
    }
    else {
        // Consolidated logic for bring forward/backward
        if (pManager->CanBringBackward(selectedIndex)) {
            pManager->BringBackward(selectedIndex);
            pOut->PrintMessage("Figure sent backward");
        }
        else if (pManager->CanBringForward(selectedIndex)) {
            pManager->BringForward(selectedIndex);
            pOut->PrintMessage("Figure brought forward");
        }
        else {
            // Figure is already at front or back 
            pOut->PrintMessage("Figure is already at the front or back.");
        }
    }
}