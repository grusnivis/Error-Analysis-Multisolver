/*
============================================================================
FILE        : operations.h
AUTHORS 	: Allard Liam Bayalas, Vince Andrei Retutal, Kathryn Marie Sigaya
DESCRIPTION : Header file for function prototypes of the operations.
COPYRIGHT   : 11 January 2022
REVISION HISTORY
Date:                By:                Description:
11/01/2022			 Bayalas			Creation of operations.h
============================================================================
*/

#ifndef OPERATIONS_H
#define OPERATIONS_H

/*
================================================================================
Function Prototypes
================================================================================
*/
void AbsRel(double trueVal, double approxVal);
void SigDigApprox(double trueVal, double approxVal);
void propError(double trueValA, double trueValB, double approxValA, double approxValB);
void growthError(double initErr, int nSteps, double kVal);
void truncError(double a,double b, int n);
void roundchopError(float value);
void lossSig(double trueValA, double trueValB);

#endif
