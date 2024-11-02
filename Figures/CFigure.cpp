#include "CFigure.h"
#include <iostream>


int CFigure::ID_Num = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo) : FigType(noshape)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = ++ID_Num;
	
}


int CFigure::GetID()const
{
	return ID;
}

void CFigure::SetID(int id)
{
	ID_Num--;
	ID = id;
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}


void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
CFigure::CFigure()
{
	FigGfxInfo.isFilled = false;
	Selected = false;
}

shape CFigure::GetFigType() const
{
	
	
	return FigType;
}

