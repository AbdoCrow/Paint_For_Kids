#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Side = 200;
	FigType = square;
}

CSquare::CSquare()
{
	Side = 200;
	FigType = square;
}
void CSquare::Draw(Output* pOut) const 
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSquare(Center , FigGfxInfo, Selected);
}
CFigure* CSquare::GetNewFigure()
{
	CSquare* P = new CSquare(Center, FigGfxInfo);
	P->ID = ID;
	P->SetSelected(IsSelected());
	P->Side = Side;
	return P;
}
bool CSquare::IsPointInside(Point P)
{
	int right = Center.x + Side / 2;
	int left = Center.x - Side / 2;
	int up = Center.y + Side / 2;
	int down = Center.y - Side / 2;
	if (P.x <= right && P.x >= left && P.y <= up && P.y >= down)
		return true;
	return false;
}

void CSquare::PrintInfo(Output* pOut)
{
	string info;
	info = "You selected a Square with ID: " + to_string(ID) + ", Center Coordinates(" + to_string(Center.x) + ", " + to_string(Center.y) + ")" + ", Side Length = " + to_string(Side);
	pOut->PrintMessage(info);
}

