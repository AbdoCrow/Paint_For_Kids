#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <vector>
#include <map>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 ,MaxUndoCount = 5};	//Max no of figures
	
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure
	CFigure* Selectedfigures[MaxFigCount]; // Array to store figures
	int DORF;
	int selectedIndex; int selectedNum;
	CFigure* figure;

	
	



public:

	int countrect;
	int counttrig;
	int countcirc;
	int counthex;
	int countsquare;



	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void ClearAll(); //Clears all the lists and resets the class
	void SetSelectedFig(CFigure*); //Sets the selectedfig pointer
	CFigure* GetFigure(Point P1) const; //Search for a figure given a point inside the figure
	CFigure* GetSelectedFig()const; //Returns the selectedfig pointer
	CFigure* GetSelectedFigureByFlag(int& selectedIndex, int& selectedNum);

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	void ClearSelection();

	void PrintSummery() const;

	int calculateSelectedCount(int& selectedIndex, int& count) const;

	string getShapeTypeString(shape shapeType);

	void printSelectedSummary();

	void InsertFigure(bool isFront);
	void RearrangingFigList();

	void BringForward(int index);
	void BringBackward(int index);
	bool CanBringForward(int index);
	bool CanBringBackward(int index);
	void DeleteSelectedFigure();

	int getSelectedFigInd() const;

	void DeleteFigure(CFigure* B);
	
	
	
};

#endif