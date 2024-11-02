#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	radius = P2;
	CalcRadius();
	FigType = circle;
}
CCircle::CCircle()
{
	FigType = circle;
}

void CCircle::Draw(Output* pOut) const
{
	
	pOut->DrawCircle(center, radius, FigGfxInfo, Selected);
}
void CCircle::CalcRadius()
{
	r = (int)sqrt(pow((radius.x - center.x), 2) + pow((radius.y - center.y), 2));
}
bool CCircle::IsPointInside(Point P)
{
	int distance = (int)sqrt(pow((P.x - center.x), 2) + pow((P.y - center.y), 2));
	if (distance <= r) return true;
	return false;
}
CFigure* CCircle::GetNewFigure()
{
	CCircle* P = new CCircle(center, radius, FigGfxInfo);
	P->ID = ID;
	P->SetSelected(IsSelected()); //This will set the selection status of the new circle to match the current circle's selection status.
	return P;
}
void CCircle::PrintInfo(Output* pOut)
{
	string info;
	info = "You selected a Circle with ID: " + to_string(ID) + ", Center Coordinates(" + to_string(center.x) + ", " + to_string(center.y) + ")";
	info += ", Point on Radius Coordinates(" + to_string(radius.x) + ", " + to_string(radius.y) + ")";
	info += ", Radius Length = " + to_string(r); 
	pOut->PrintMessage(info);
}

void CCircle::ChngClr()
{
	UI.DrawColor = FigGfxInfo.DrawClr;
	UI.IsFilled = FigGfxInfo.isFilled;
	UI.FillColor = FigGfxInfo.FillClr;
}
