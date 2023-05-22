/*
============================================================================
FILE        : main.c
AUTHORS 	: Allard Liam Bayalas, Vince Andrei Retutal, Kathryn Marie Sigaya
DESCRIPTION : A program that does the error analysis methods chosen by the user. The user
			  will choose from the list of methods and the program will do the said method
			  accordingly.
COPYRIGHT   : 13 December 2021
REVISION HISTORY
Date:                By:                Description:
13/12/21			 Bayalas			Creation of main.c
16/12/21			 Sigaya				Implemented roundchopError and lossSig modules
09/01/22			 Bayalas			Implemented specific operations modules
10/01/22			 Retutal, Sigaya	Tested and implemented improvements to program
11/01/22			 Bayalas			Modularized program
					 Sigaya				Documentation
============================================================================
*/

/*
================================================================================
Header Files
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "modules.h"

/*
================================================================================
FUNCTION    : main
DESCRIPTION : Displays the menu, and does the error analysis methods.
ARGUMENTS   : int argc - argument count
			  int argv - argument vector
RETURNS     : int - exit program
================================================================================
*/
int main(int argc, char *argv[]) {
	
	int exit=0, flag = 0;
		
	do{
	exit = choices(flag);	
	}while(exit == 0);

	return 0;
}
