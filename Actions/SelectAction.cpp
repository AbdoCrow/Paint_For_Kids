#include "SelectAction.h"
#include "..\ApplicationManager.h"
#include <vector>
#include <iostream>

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
   
    pOut->PrintMessage("Select : Click on any figure");
    pIn->GetPointClicked(P.x, P.y);
    pOut->ClearStatusBar();
}

//Execute action (code depends on action type)
void SelectAction::Execute()
{
    ReadActionParameters();



    Output* pOut = pManager->GetOutput();

    CFigure* FigPtr = pManager->GetFigure(P);
   
    CFigure* SelectedFig = pManager->GetSelectedFig();

    
   
   

    if (FigPtr)
    {
        shape shapeType = FigPtr->GetFigType();

        bool wasSelected = FigPtr->IsSelected(); // Store previous selection state
        FigPtr->SetSelected(!wasSelected);  // Toggle selection

        string shapeTypeString = pManager->getShapeTypeString(shapeType);
        if (wasSelected && !FigPtr->IsSelected()) { // Check if it became deselected
            if (shapeTypeString == "Rectangle")
                pManager->countrect--;
            if (shapeTypeString == "Triangle")
                pManager->counttrig--;
            if (shapeTypeString == "Square")
                pManager->countsquare--;
            if (shapeTypeString == "Circle")
                pManager->countcirc--;
            if (shapeTypeString == "Hexagon")
                pManager->counthex--;

        }
        else if (!wasSelected && FigPtr->IsSelected()) { // Check if it became selected
            if (shapeTypeString == "Rectangle")
                pManager->countrect++;
            if (shapeTypeString == "Triangle")
                pManager->counttrig++;
            if (shapeTypeString == "Square")
                pManager->countsquare++;
            if (shapeTypeString == "Circle")
                pManager->countcirc++;
            if (shapeTypeString == "Hexagon")
                pManager->counthex++;

        }
        int count, index;
        // Count Selected Figures and Print Updates
        int selectedCount = pManager->calculateSelectedCount(count, index);


        if (selectedCount == 1) {
            // Directly call PrintInfo of the most recently selected figure
            FigPtr->PrintInfo(pOut);
        }
        else if (selectedCount > 1) {
            pManager->printSelectedSummary();
        }
       

    }
    
    else{
          // Click on empty space 
             pManager->ClearSelection();  // Deselect all figures
             pOut->PrintMessage("All Figures Deselected");
             pManager->counthex=0;
             pManager->countcirc=0;
             pManager->counttrig=0;
             pManager->countrect=0;
             pManager->countsquare=0; 
    
    }

}
