/*
============================================================================
FILE        : modules.c
AUTHORS 	: Allard Liam Bayalas, Vince Andrei Retutal, Kathryn Marie Sigaya
DESCRIPTION : Functions/modules for the main menu.
COPYRIGHT   : 13 December 2021
REVISION HISTORY
Date:                By:                Description:
13/12/21			 Bayalas			Creation of modules.c
16/12/21		 	 Sigaya				Creation of menu and choices functions
10/01/22			 Bayalas			Modified the choices function's looping
11/01/22			 Sigaya				Documentation
============================================================================
*/

/*
================================================================================
Header Files
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operations.h"

/*
================================================================================
Function Prototypes
================================================================================
*/
void menu();
int choices(int choices);

/*
================================================================================
FUNCTION    : choices
DESCRIPTION : Displays the menu, and prompts the user to enter their method of choice.
ARGUMENTS   : int choices - corresponds to the method of choice by the user.
RETURNS     : int - exit value indicator
================================================================================
*/
int choices(int choices){
	
	int flag = 0, nSteps = 0, n = 0;
	char choice = 0, reset = 0;
	double trueVal = 0, approxVal = 0;
	double trueValA = 0, trueValB = 0, approxValA = 0, approxValB = 0;
	double initErr = 0 , kVal = 0;
	double linearGrowth = 0, expGrowth = 0;
	double a = 0,b = 0;
	float value = 0;
	
	do{
		system("cls");
		menu();
		printf("Input Your Choice: ");
		choice = getch();
		system("cls");
		printf("Just a sec.");
		Sleep(500);
		system("cls");

	switch(choice){
		
		case '1':
			printf("You have chosen 'Absolute & Relative Error'.\n\n");
			
			printf("True Value: ");
			scanf("%lf", &trueVal); //use lf for storing double values on using scanf
			
			printf("Approximate Value: ");
			scanf("%lf", &approxVal);
			
			AbsRel(trueVal,approxVal); 

		break;

		case '2':
			printf("You have chosen 'Significant Digits of Approximation'.\n\n");
			printf("True Value: ");
			scanf("%lf", &trueVal);
			printf("Approximate Value: ");
			scanf("%lf", &approxVal);
			
			SigDigApprox(trueVal,approxVal);
			
		break;
    
		case '3':
			printf("\nYou have chosen 'Propagation of Error'.\n\n");
			printf("There will be two errors (Errors A and B) which are computed through addition & multiplication operations.\n");
			printf("Each errors (A  and B) will be computed by their Absolute & Relative Errors first before proceeding to\nthe addition & multiplcation operations.\n\n");
	
			printf("Error A\n");
			printf("Enter true value: ");
			scanf("%lf",&trueValA);
			printf("\nEnter approximate value: ");
			scanf("%lf",&approxValA);
			
			printf("\n\nError B\n");
			printf("Enter true value: ");
			scanf("%lf",&trueValB);
			printf("\nEnter approximate value: ");
			scanf("%lf",&approxValB);
			
			propError(trueValA, trueValB, approxValA, approxValB);		

		break;

		case '4':
			printf("\nYou have chosen 'Growth of Error'.\n\n");
			printf("\nThere are two operations for Growth of Error namely: Linear & Exponential.\n");
			printf("\nIn exponential growth error, the value of K will determine whether the resultant error |E(n)| \nwill exponentially grow (K > 1) or expeonentially decay (0 < K < 1).\n");
			printf("\nEnter initial error E: ");
			scanf("%lf", &initErr);
			printf("\nNo. of 'n' steps: ");
			scanf("%d",&nSteps);
			printf("\nChoose a value of 'K': ");
			scanf("%lf",&kVal);
			
			growthError(initErr,nSteps,kVal);
		break;
	
		case '5':
			printf("\nYou have chosen 'Truncation of Error'.\n\n");
			printf("\nTaylor Series will be used for this operation. \nThe expression 'e^x' will be used to compute for the true value.\n\n");
			printf("Actual expression to be used: 'definite integral a to b (e^x)'.\n");	
		
			printf("\nLower limit 'a': ");
			scanf("%lf", &a);	
			printf("Upper limit 'b': ");
			scanf("%lf", &b);
			printf("\nNumber of terms 'n': ");
			scanf("%d", &n);
			
			truncError(a,b,n);		
		break;

		case '6':
			printf("\nYou have chosen 'Round-off and Chop-off Error'.\n\n");		
			printf("Note: The round/chop-off value is only limited to 3 decimal places due to floating-point data type limitations.\n");
			printf("\nEnter the value you want to round/chop: ");
			scanf("%f", &value);
			
			roundchopError(value);		
		break;

		case '7':
			printf("\nYou have chosen 'Loss of Significance'.\n\n");		
			
			printf("Enter first value: ");
			scanf("%lf", &trueValA);
			printf("Enter second value: ");
			scanf("%lf", &trueValB);
			
			lossSig(trueValA, trueValB);
			break;
				
		default:
			printf("Invalid choice! \n");
			
}

	Sleep(500);
	 printf("Go back to Main Selection? [Y / N]: ");
	 reset = getch();
	 
	 system("cls");
	 
	 printf("Please Wait");
			Sleep(200);
			printf(".");

//main program end
	}while(reset=='y' || reset=='Y');
	printf("\nProgram Terminated\n\n");
	return 1;
}

/*
================================================================================
FUNCTION    : menu
DESCRIPTION : Displays the Error Analysis Multi-solver menu.
RETURNS     : void
================================================================================
*/
void menu(){
	system("cls");
	printf("=====================================================\n");	
	printf("|\t   Error Analysis Multi-solver              |\n");
	printf("=====================================================\n");
	printf("|                                                   |\n");
	printf("|    1 for Absolute & Relative Error                |\n");
	printf("|    2 for Significant Digits of Approximation      |\n");
	printf("|    3 for Propagation of Error                     |\n");
	printf("|    4 for Growth of Error                          |\n");
	printf("|    5 for Truncation of Error                      |\n");	
	printf("|    6 for Round-off & Chop-off Error               |\n");					
	printf("|    7 for Loss of Significance                     |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
}
