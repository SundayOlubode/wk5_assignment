#include <stdio.h>

double deduct_tax_on_salary(double*);
double *deduct_medication_insurance(double*);
double *deduct_maternity_leave(double*);
double *deduct_social_security(double*);

double gross_salary = 100000;
double * pgs = &gross_salary;

void main()
{
	double net_salary = 0;
	double * pns = &net_salary;

	*pns = deduct_tax_on_salary(pgs);
	printf("After Tax: %f\n", *pns); 
	pns = deduct_medication_insurance(pns);
	pns = deduct_maternity_leave(pns);
	pns = deduct_social_security(pns);

	printf("Net Salary is: %.2f\n", *pns);
}

double deduct_tax_on_salary(double *pgs)
{
	double tax = 0;
	double * ptax = &tax;

	if( *pgs >= 100 && *pgs <= 300)
	{
		*ptax = 0.20;
	}
	else if ( *pgs > 300)
	{
		*ptax = 0.28;
	}
	
	double niat = *pgs * (1 - *ptax);
	
	return niat;
}

double *deduct_medication_insurance(double *pns)
{
	double insurance = (5 / 100.0);

	*pns = *pns * (1 - insurance);
	printf("After Insurance: %f\n", *pns); 
	return pns;
}

double *deduct_maternity_leave(double *pns)
{
	double maternity_leave = (0.03 / 100.0);

	*pns = *pns * (1 - maternity_leave);
	printf("After Maternity: %f\n", *pns); 
	return pns;
}

double *deduct_social_security(double *pns)
{
	double social_security = (3 / 100.0);

	*pns = *pns * (1 - social_security);
	printf("After Social: %f\n", *pns); 
	return pns;
}
