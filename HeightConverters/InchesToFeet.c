/*****************************************************
 *
 *	Inches to Feet Converter
 *  Kiera Conway
 *
 *	Program requests user's name and height in inches,
 *	then returns a sentence with the height in feet
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
/*************************
*  TrimRight
*  trims excess characters on the right 
*************************/
char* TrimRight(char* str, const char* trimChars);

/*************************
*  inches_to_feet()
*  converts inches to feet 
*************************/
float inches_to_feet(float inches)
{
	return inches / 12;
}

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
	char name[100];
	float height = 0;
	
	printf("\n Please enter your name > ");										//prompt user for name
	scanf("%[^\n]s", name);														//scan input, assign to variable 'name'
																				// "%[^\n]s" scans until newline is reached
	
	printf("\n Hi %s, please enter your height in inches > ", name);			//promt user for name
	scanf("%f", &height);														//scan input, assign to variable 'height'
	
	printf("\n\n %s, you are %f feet tall\n\n", name, inches_to_feet(height));	//print 'name' and 'height' (in feet)

	return 0;
}


/******************************************************************************
 *
 * TrimRight()
 *
 * Removes characters from the end of a string, defaults to whitespace
 * characters is trimChars is null.
 *
 *****************************************************************************/
char* TrimRight(char* str, const char* trimChars)
{
	int i;

	if (trimChars == NULL)
	{
		trimChars = "\t\n\v\f\r ";
	}

	i = strlen(str) - 1;
	while (i >= 0 && strchr(trimChars, str[i]) != NULL)
	{
		str[i] = '\0';
		i--;
	}

	return str;
}
