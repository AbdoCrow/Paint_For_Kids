#pragma once
#ifndef CRECT_H
#define CRECT_H
#include "CFigure.h"

class CSquare : public CFigure
{
	private:
		Point Center;
		int Side;
	public:
		CSquare(Point, GfxInfo FigureGfxInfo);
		CSquare();
		virtual void Draw(Output * pOut) const;
		virtual bool IsPointInside(Point P);
		virtual CFigure* GetNewFigure();
		virtual void PrintInfo(Output* pOut);
		
};

#endif

