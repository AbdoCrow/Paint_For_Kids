#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 51;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = LIGHTCYAN;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = SOFTCYAN;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2024");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_RECT.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_SQUARE.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_HEXAGON.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_TRIANGLE.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_CIRCLE.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_SELECT.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_YELLOW.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_ORANGE.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_RED.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_GREEN.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_BLUE.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_BLACK.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_FILL.jpg";
	MenuItemImages[ITM_OUTLINE] = "images\\MenuItems\\Menu_OUTLINE.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\Menu_CLEAR.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_DELETE.jpg";
	MenuItemImages[ITM_FRONTBACK] = "images\\MenuItems\\Menu_FRONTBACK.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_CUT.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_COPY.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_PASTE.jpg";
	MenuItemImages[ITM_SAVEDRAW] = "images\\MenuItems\\Menu_SAVEDRAW.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_SAVE.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Menu_PLAY.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];

	MenuItemImages[PICK_TYPE] = "images\\MenuItems\\PICK_TYPE.jpg";
	MenuItemImages[PICK_COLOR] = "images\\MenuItems\\PICK_COLOR.jpg";
	MenuItemImages[PICK_BOTH] = "images\\MenuItems\\PICK_BOTH.jpg";
	MenuItemImages[SWITCH_TO_DRAW] = "images\\MenuItems\\SWITCHTODRAW.jpg";

	//PLAY menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawSquare(Point center, GfxInfo squareGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = squareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	drawstyle style;
	if (squareGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(squareGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}
	int sideLength = 200;
	// Calculate square coordinates
	int topLeftX = center.x - sideLength / 2;
	int topLeftY = center.y - sideLength / 2;
	int bottomRightX = center.x + sideLength / 2;
	int bottomRightY = center.y + sideLength / 2;


	pWind->DrawRectangle(topLeftX, topLeftY, bottomRightX, bottomRightY, style);

	if (topLeftY < UI.ToolBarHeight)
	{
		pWind->SetPen(WHITE, 1);
		pWind->SetBrush(WHITE);
		pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
		CreateDrawToolBar();
	}
}

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo triangleGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = triangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	drawstyle style;
	if (triangleGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(triangleGfxInfo.FillClr);

	}
	else {
		style = FRAME;
	}
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
void Output::DrawCircle(Point center, Point radiuspoint, GfxInfo circleGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = circleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	drawstyle style;
	if (circleGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(circleGfxInfo.FillClr);

	}
	else {
		style = FRAME;
	}
	int radius = sqrt(pow(radiuspoint.x - center.x, 2) + pow(radiuspoint.y - center.y, 2));

	pWind->DrawCircle(center.x, center.y, radius, style);

	//if needed 
	if (center.y - radius < UI.ToolBarHeight) {
		pWind->SetPen(WHITE, 1);
		pWind->SetBrush(WHITE);
		pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
		CreateDrawToolBar();

	}
}
void Output::DrawHexagon(Point center, GfxInfo hexGfxInfo, bool selected) const {

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = hexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (hexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(hexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int Side = 100;
	int Px[6];
	int Py[6];
	Px[0] = center.x + Side * sqrt(3) / 2;
	Px[1] = center.x + Side * sqrt(3) / 2;
	Px[2] = center.x;
	Px[3] = center.x - Side * sqrt(3) / 2;
	Px[4] = center.x - Side * sqrt(3) / 2;
	Px[5] = center.x;
	Py[0] = center.y - Side / 2;
	Py[1] = center.y + Side / 2;
	Py[2] = center.y + Side;
	Py[3] = center.y + Side / 2;
	Py[4] = center.y - Side / 2;
	Py[5] = center.y - Side;
	pWind->DrawPolygon(Px, Py, 6, style);
	if (center.y - Side < UI.ToolBarHeight)
	{
		pWind->SetPen(WHITE, 1);
		pWind->SetBrush(WHITE);
		pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
		CreateDrawToolBar();
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}