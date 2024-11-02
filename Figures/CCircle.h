#pragma once
#ifndef CCricle_H
#define CCircle_H

#include "CFigure.h"
class CCircle : public CFigure
{
private:
	Point center;
	Point radius;
	int r;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(Point P);
	void CalcRadius();
	virtual CFigure* GetNewFigure();
	virtual void PrintInfo(Output* pOut);
	void ChngClr();

};
#endif
