#pragma once
#ifndef CTrig_H
#define CTrig_H

#include "CFigure.h"
class CTrig : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	Point Center;
	int Index;
public:
	CTrig(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTrig();
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(Point P);
	virtual CFigure* GetNewFigure();
	virtual void PrintInfo(Output* pOut);
	void CalcCenter();
	double calculateArea(Point p1, Point p2, Point p3);
	
	
};
#endif
