#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle

	///Make similar functions for drawing all other figure types.
	// -- Figures Drawing functions
	void DrawSquare(Point center, GfxInfo squareGfxInfo, bool selected) const;  //Draw a square
	void DrawTriangle(Point p1, Point p2, Point p3, GfxInfo triangleGfxInfo, bool selected) const;  //Draw a triangle
	void DrawCircle(Point center, Point radius, GfxInfo circleGfxInfo, bool selected) const;  //Draw a circle
	void DrawHexagon(Point center, GfxInfo squareGfxInfo, bool selected) const;  //Draw a hexagon

	void PrintMessage(string msg) const;	//Print a message on Status bar
	void PrintTempMessge(string msg, int ms) const;

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif