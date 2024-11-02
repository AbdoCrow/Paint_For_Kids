#pragma once
#pragma once
#ifndef CHex_H
#define CHex_H
#include "CFigure.h"

class CHex : public CFigure
{
private:
	Point Center;
	int Side;
	Point Corners[6];
	int Index;
public:
	CHex(Point, GfxInfo FigureGfxInfo);
	CHex();
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(Point P);
	void CalcCorners(Point* Corners);
	virtual CFigure* GetNewFigure();
	virtual bool IsCorner(Point P);
	virtual void PrintInfo(Output* pOut);
	void ChngClr();
};
#endif
