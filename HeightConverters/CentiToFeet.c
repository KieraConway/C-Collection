/*****************************************************
 *
 *	Centimeter to Feet Converter
 *  Kiera Conway
 *
 *	Program requests user's height in centimeters
 *	until a nonpositive value is entered.
 *	Program returns height in centimeters and feet.
 *
******************************************************/
#include <stdio.h>
#include <string.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////


/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/

int main(int argc, char *argv[]) 
{
	float centi;																		//declare centimeter variable
	int feet;																			//declare feet variable
	float inches;																		//declare inches variable
	float remainingInches;																//declare inches remaining after centi % inches

	
    printf("\nConvert your height from centimeters to feet and inches!\n");				//introduction header
	printf("--------------------------------------------------------\n\n");
	
	printf("Enter a height in centimeters (<=0 to quit): ");							//prompt user for input
	scanf("%f", &centi);																//scan input, assign to variable 'centi'
	
	while (centi > 0)																	//while input is greater than 0...
	{
		inches = centi * 0.3937;														//... set inches = input * 0.3937
		feet = inches / 12;																//... set feet = inches / 12
		remainingInches = (inches - (feet * 12));										//... calculate remaining inches
		
		printf("%0.1f cm = %d feet, %0.1f inches\n\n", centi, feet, remainingInches);	//...print solved values
		
			
		printf("Enter another height in centimeters (<=0 to quit): ");					//... prompt user for input again
		scanf("%f", &centi);															//scan input, assign to variable 'centi'
	
	}																					//if input > 0, repeat loop
																						//otherwise, exit
	printf("bye\n\n");																	//print bye
	
	return 0;
}
