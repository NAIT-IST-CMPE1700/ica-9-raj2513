#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main()
{
	Individual* firstSet = Group(10);

	char SelectedOption = 'N';		

	while (SelectedOption != '5')
	{
		SelectedOption = 'N';

		Options();
		printf("\n");

		scanf_s("%c", &SelectedOption, sizeof(char));
		printf("\n");

		switch (SelectedOption)
		{

		case '1':

			PrintOrderId(firstSet);
			PrintResult(firstSet, NULL, 0);

			printf("\n");

			break;

		case '2':

			PrintOrderMarks(firstSet);
			PrintResult(firstSet, NULL, 0);

			printf("\n");

			break;

		case '3':

			PrintResult(firstSet, NULL, 0);
			printf("\n");

			break;

		case '4':

			PrintResult(firstSet, NULL, 50);
			printf("\n");

			break;

		case '5':

			break;

		default:

			printf("\nSelection is Invalid.\n");

			break;
		}
		getchar();
	}
	exit(EXIT_SUCCESS);
}