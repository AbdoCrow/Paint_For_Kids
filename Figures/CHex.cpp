#include "CHex.h"
#define M_PI 3.14159265358979323846  

CHex::CHex(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
    Side = 100;
    CalcCorners(Corners);
    FigType = hexagon;
}
CHex::CHex()
{
    FigType = hexagon;
    Side = 100;
}

void CHex::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}
bool CHex::IsPointInside(Point P) {

    for (int i = 0; i < 6; i++) {
        bool initialSign = false; // To track the sign of the first cross product

        for (int i = 0; i < 6; i++) {
            int nextIndex = (i + 1) % 6;

            // Vectors from point to corners
            double v1x = Corners[i].x - P.x;
            double v1y = Corners[i].y - P.y;
            double v2x = Corners[nextIndex].x - P.x;
            double v2y = Corners[nextIndex].y - P.y;

            // 2D Cross Product (z-component)
            double crossProduct = v1x * v2y - v1y * v2x;

            // Set initial sign on first iteration
            if (i == 0) {
                initialSign = (crossProduct > 0);
            }
            else if (crossProduct * initialSign <= 0) {
                //  Different sign or zero -> outside
                return false;
            }
        }

        return true; // If all cross products have the same sign
    }
}

CFigure* CHex::GetNewFigure()
{
    CHex* P = new CHex(Center, FigGfxInfo);
    P->ID = ID;
    P->SetSelected(IsSelected());
    P->Side = Side;
    return P;
}
void CHex::CalcCorners(Point* Corners) {

    Corners[0].x = Center.x - Side * sqrt(3) / 2, Corners[1].x = Center.x, Corners[2].x = Center.x + Side * sqrt(3) / 2,
        Corners[3].x = Center.x + Side * sqrt(3) / 2, Corners[4].x = Center.x, Corners[5].x = Center.x - Side * sqrt(3) / 2;
    Corners[0].y = Center.y - Side / 2, Corners[1].y = Center.y - Side, Corners[2].y = Center.y - Side / 2,
        Corners[3].y = Center.y + Side / 2, Corners[4].y = Center.y + Side, Corners[5].y = Center.y + Side / 2;
}

bool CHex::IsCorner(Point P)
{
    for (int i = 0; i < 6; i++)
    {
        if (abs(Corners[i].x - P.x) <= 10 && abs(Corners[i].y - P.y) <= 10)
        {
            Index = i;
            return true;
        }
    }
    return false;
}

void CHex::PrintInfo(Output* pOut)
{
    string info;
    info = "You selected a Hexagon with ID: " + to_string(ID) + ", Center Coordinates(" + to_string(Center.x) + ", " + to_string(Center.y) + ")";
    info += ", Side Length = " + to_string(Side);
    pOut->PrintMessage(info);
}

void CHex::ChngClr()
{
    UI.DrawColor = FigGfxInfo.DrawClr;
    UI.IsFilled = FigGfxInfo.isFilled;
    UI.FillColor = FigGfxInfo.FillClr;

}