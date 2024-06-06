#include <stdio.h>

double deduct_tax_on_salary(double*);
double *deduct_medication_insurance(double*);
// double deduct_maternity_leave(int*);
// double deduct_social_security(int*);

double gross_salary = 100000;
double * pgs = &gross_salary;

void main()
{
	double net_salary = 0;
	double * pns = &net_salary;

	*pns = deduct_tax_on_salary(pgs);
	pns = deduct_medication_insurance(pns);

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
	double insurance = 0.05;

	*pns = *pns * (1 - insurance);
	return pns;
}
// double deduct_maternity_leave(int*);
// double deduct_social_security(int*);
