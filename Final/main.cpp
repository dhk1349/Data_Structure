/**
*	@mainpage
*	@date	2019/03/26
*	@author	 ÇÑµ¿ÈÆ
*/
#define col GetStdHandle (STD_OUTPUT_HANDLE)
#define SetColor_Blue SetConsoleTextAttribute (col,  0x0001 | 0x0008 );
#include "Application.h"

/**
*	program main function for data structures course.
*/
int main()
{

	SetColor_Blue;
	Application app;	// Program application
	app.Run2();			// run program

	return 0;
}