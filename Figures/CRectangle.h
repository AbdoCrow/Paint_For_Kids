#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Center;
	int Length, Width;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(Point P);
	virtual CFigure* GetNewFigure();
	void CalcCenter();
	void Calc_Length_Width();
	virtual void PrintInfo(Output* pOut);
	void ChngClr();
	
};




#endif