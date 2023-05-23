/*
============================================================================
FILE        : operations.c
AUTHORS 	: Allard Liam Bayalas, Vince Andrei Retutal, Kathryn Marie Sigaya
DESCRIPTION : Functions/modules for the error analysis calculations.
COPYRIGHT   : 13 December 2021
REVISION HISTORY
Date:                By:                Description:
13/12/21			 Bayalas			Creation of operations.c
16/12/21			 Sigaya				Implemented roundchopError and lossSig modules
09/01/22			 Bayalas			Implemented specific operations modules
					 Retutal, Sigaya	Testing and improvements to modules
11/01/22			 Bayalas			Finalized program
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
#include <math.h>
#define EULER 2.718281828

/*
================================================================================
FUNCTION    : absRel
DESCRIPTION : Performs the Absolute and Relative Error calculations.
ARGUMENTS   : double trueVal 	- True Value
			  double approxVal	- Approximated Value
RETURNS     : void
================================================================================
*/
void AbsRel(double trueVal, double approxVal){
	double absErr, relErr;
	
	absErr = trueVal - approxVal;
	absErr = fabs(absErr); //returns the absolute value of its floating-point argument
	relErr = absErr / trueVal;
	relErr = fabs(relErr); //if x > 0 then x. if x < 0 then -x
	
	printf("\nAbsolute Error: %.10f\nRelative Error: %.10f\n\n",absErr, relErr);	
	
}

/*
================================================================================
FUNCTION    : SigDigApprox
DESCRIPTION : Performs the Significant Digits of Approximation calculations.
ARGUMENTS   : double trueVal	- True Value
			  double approxVal	- Approximated Value
RETURNS     : void
================================================================================
*/
void SigDigApprox(double trueVal, double approxVal){
	int q=0;
	double d, relErr;
	relErr = (trueVal - approxVal) / trueVal;
	relErr = fabs(relErr);
	printf("\nRelative Error: %.9f\n", relErr);
	printf("\nSignificant Digit\tRelative Error \t\t");	
	
do{
	d = (pow(10,(1-q)))/2;
	if (relErr < d){
	printf("\n\t%d \t\t%.9f \t\t%.9lf\t --> TRUE",q, relErr, d);	
	q++;				
	}
	
	else{	
	printf("\n\t%d \t\t%.9f \t\t%.9lf\t --> FALSE",q, relErr, d);	
	q = q-1;	
	}
}while(relErr < d);		

	printf("\nDigits of Approximate value is %d.\n\n",q);	
			
}

/*
================================================================================
FUNCTION    : propError
DESCRIPTION : Performs the Propagation of Error calculations.
ARGUMENTS   : double trueValA	- True Value A
			  double trueValB	- True Value B
			  double approxValA - Approximated value A
			  double approxValB	- Approximated value B
RETURNS     : void
================================================================================
*/
void propError(double trueValA, double trueValB, double approxValA, double approxValB){
	
	double absErrA, absErrB, relErrA, relErrB, relAB, tValAB, sumAB, aValAB;
	
	printf("There will be two errors (Errors A and B) which are computed through addition & multiplication operations.\n");
	printf("Each errors (A  and B) will be computed by their Absolute & Relative Errors first before proceeding to\nthe addition & multiplcation operations.\n\n");
	
	absErrA = trueValA - approxValA;
	absErrA = fabs(absErrA);
	relErrA = absErrA / trueValA;
	relErrA = fabs(relErrA);

	absErrB = trueValB - approxValB;
	absErrB = fabs(absErrB);
	relErrB = absErrB / trueValB;
	relErrB = fabs(relErrB);
	
	system("cls");
	
	printf("=====================================================\n");	
	printf("|\t   Error Propagation Results                |\n");
	printf("=====================================================\n");	
	printf("\nError A\nTrue Value: %.10lf\nApproximate Value: %.10lf\n\nAbsolute Error: %.10lf\nRelative Error: %.10lf", trueValA,approxValA,absErrA,relErrA);
	printf("\nError B\nTrue Value: %.10lf\nApproximate Value: %.10lf\n\nAbsolute Error: %.10lf\nRelative Error: %.10lf", trueValB,approxValB,absErrB,relErrB);
	
//-----------------------------addition operation------------------------
	//sum of true values = (sum of approx. values) + (sum of absolute errors)
	
	tValAB = trueValA + trueValB;
	tValAB = fabs(tValAB);
	aValAB = approxValA + approxValB;
	aValAB = fabs(aValAB);
	sumAB = aValAB + (absErrA + absErrB);
	sumAB = fabs(sumAB);
	
	if(tValAB == sumAB){
		printf("\n\nThe sum of true values A & B:\t\t\t     %.10lf \nFinal sum of approximate values and absolute errors: %.10lf are equal.\n\n",tValAB,sumAB);
	}
	else{
		printf("Calculation error!");
	}
//-----------------------multiplication operation------------------------
	relAB = relErrA + relErrB;
	relAB = fabs(relAB);
	
	printf("\nThe sum of relative errors A & B is %.10lf\n\n",relAB);

}

/*
================================================================================
FUNCTION    : growthError
DESCRIPTION : Performs the Growth of Error calculations.
ARGUMENTS   : double initErr - initial error epsilon (E)
			  int nSteps	 - number of steps
			  double kVal	 - Value of K
RETURNS     : void
================================================================================
*/
void growthError(double initErr, int nSteps, double kVal){
	double linearGrowth, expGrowth;
				
	linearGrowth = initErr * nSteps;
	linearGrowth = fabs(linearGrowth);
	printf("\nLinear Growth |E(n)| in %d steps: %.10lf",nSteps,linearGrowth);
		
	expGrowth = pow(kVal,nSteps) * initErr;
	expGrowth = fabs(expGrowth);
	printf("\nExponential Growth Error |E(n)| in %d steps: %.10lf\n\n",nSteps,expGrowth);
}

/*
================================================================================
FUNCTION    : truncError
DESCRIPTION : Performs the Truncation of Error calculations.
ARGUMENTS   : double a - lower limit of the integral
			  double b - upper limit of the integral
			  int n	   - number of terms
RETURNS     : void
================================================================================
*/
void truncError(double a,double b, int n){
	int i=1, j=1, factA = 1, factB = 1;
	double sumA = 0, sumB = 0, trueVal = 0, approxVal = 0, absErr = 0, relErr = 0;
	//---------------------------------	solve for True Value using Definite Integral --------------------------------------------	
		if(n >= 1 && n <= 10){
			
		trueVal = pow((double)EULER,b) - pow((double)EULER,a);
		trueVal = fabs(trueVal);
		
		printf("\nTrue Value : %.10lf\n", trueVal);
	
//-------------	solve for Approximate Value using the Taylor Series equivalent of 'e^x' ----------

//---------------------------------	solve for lower limit A ----------------------------------------------------------
		for(i=1;i<n;i++){
			factA = factA*i;
			sumA = sumA + (pow(a,i)/factA);	
			}
		sumA = sumA + 1;
//--------------------------------- solve for upper limit B ----------------------------------------------------------
		for(j=1;j<n;j++){
			factB = factB*j;
			sumB = sumB + (pow(b,j)/factB);	
			}
		sumB = sumB + 1;
		approxVal = sumB - sumA;	
//evaluate A and B	
		printf("Approximation value: %.10lf\n\n", approxVal);
//solve for Absolute & Relative Error
		absErr = trueVal - approxVal;
		absErr = fabs(absErr);

		relErr = absErr / trueVal;
		relErr = fabs(relErr);

		printf("Absolute Error: %.11lf\n", absErr);
		printf("Relative Error: %.11lf\n\n", relErr);			
		}
	
		else{
			printf("\n\nInvalid input! \n\n");			
		}
}

/*
================================================================================
FUNCTION    : roundChopError
DESCRIPTION : Performs the Round-off and Chop-off Error calculations.
ARGUMENTS   : float value - the value to be evaluated
RETURNS     : void
================================================================================
*/
void roundchopError(float value){
		printf("\n\nRound-off value: %0.3f", value);	
		//chop-off for 3 decimal places
		value = floor(1000*value)/1000;
		printf("\nChop-off value: %0.3f\n\n", value);
}

/*
================================================================================
FUNCTION    : lossSig
DESCRIPTION : Performs the Loss of Significance calculations.
ARGUMENTS   : double trueValA - True Value A
			  double trueValB - True Value B
RETURNS     : void
================================================================================
*/
void lossSig(double trueValA, double trueValB){
	double value;
	value = trueValA - trueValB;	
	printf("Difference: %.10lf\n\n", value);
}
