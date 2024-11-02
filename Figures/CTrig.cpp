#include "CTrig.h"

CTrig::CTrig(Point P1, Point P2,Point P3 , GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	FigType = triangle;
	CalcCenter();
}

CTrig::CTrig()
{
	FigType = triangle;
}

void CTrig::Draw(Output* pOut) const
{
	

	pOut->DrawTriangle(Corner1, Corner2,Corner3, FigGfxInfo, Selected); 

}
void CTrig::CalcCenter()
{
	Center.x = (Corner1.x + Corner2.y + Corner3.y) / 3;
}
bool CTrig::IsPointInside(Point point)
{
	const double EPSILON = 0.00001;
	double totalArea = calculateArea(Corner1, Corner2, Corner3);
	double area1 = calculateArea(point, Corner1, Corner2);
	double area2 = calculateArea(point, Corner2, Corner3);
	double area3 = calculateArea(point, Corner3, Corner1);

	// Check with tolerance
	return abs(totalArea - (area1 + area2 + area3)) < EPSILON;
}
CFigure* CTrig::GetNewFigure()
{
	CTrig* P = new CTrig(Corner1, Corner2, Corner3, FigGfxInfo);
	P->ID = ID;
	P->SetSelected(IsSelected());
	return P;
}

double CTrig::calculateArea(Point p1, Point p2, Point p3) {
	return abs(0.5 * ((p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) -
		(p1.y * p2.x + p2.y * p3.x + p3.y * p1.x)));
}

void CTrig::PrintInfo(Output* pOut)
{
	string info;
	info = "You selected a Triangle with ID: " + to_string(ID) + ", First Corner(" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + ")";
	info += ", Second Corner(" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")"; 
	info += ", Third Corner(" + to_string(Corner3.x) + ", " + to_string(Corner3.y) + ")";
	pOut->PrintMessage(info);
}

