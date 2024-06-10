#include <stdio.h>

double deduct_tax_on_salary(double*);
double *deduct_medication_insurance(double*);
double *deduct_maternity_leave(double*);
double *deduct_social_security(double*);

/**
 * clear_input_buffer - Function to clear the input buffer
 *
 * Return: void
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard characters until end of line or end of file
    }
}


/**
 * main - Main
 *
 * Return: void
 */
void main()
{

	double gross_salary;
	int result;
	
	while (1) {
		printf("Enter your Gross Salary: ");
		result = scanf("%lf", &gross_salary);

		if (result == 1){
			break;
		} else {
			printf("Invalid input. Please enter a valid Gross Salary!\n");
			clear_input_buffer();
		}
	}

	double * pgs = &gross_salary;
	
	printf("Gross Salary: %.2f\n", *pgs);
	
	double net_salary = 0;
	double * pns = &net_salary;

	*pns = deduct_tax_on_salary(pgs);
	pns = deduct_medication_insurance(pns);
	pns = deduct_maternity_leave(pns);
	pns = deduct_social_security(pns);

	printf("Net Salary: %.2f\n", *pns);
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
	return pns;
}

double *deduct_maternity_leave(double *pns)
{
	double maternity_leave = (0.03 / 100.0);

	*pns = *pns * (1 - maternity_leave);
	return pns;
}

double *deduct_social_security(double *pns)
{
	double social_security = (3 / 100.0);

	*pns = *pns * (1 - social_security);
	return pns;
}
