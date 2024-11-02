#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	EXIT,			//Exit
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,
    DRAW_HEX,
	DRAW_TRIANGLE,
	DRAW_CIRCLE,
	SELECT,
	PICK_YELLOW,
	PICK_ORANGE,
	PICK_RED,
	PICK_GREEN,
	PICK_BLUE,
	PICK_BLACK,
	FILL_SHAPE,
	COLOR_BORDER,
	CLEAR_ALL,
	DELETE_FIG,
	SENDTOBACK,
	CUT,
	COPY,
	PASTE,
	SAVE,
	LOAD,

	TO_PLAY,		//Switch interface to Play mode
	PICKTYPE,
	PICKCOLOR,
	PICKBOTH,
	TO_DRAW,		//Switch interface to Draw mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif