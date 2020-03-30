#include <stdio.h>
#include <stdlib.h>
#include "person.h"

Individual* OnePerson(char* name, int id, int marks) 
{
	Individual* newPerson = (Individual*)malloc(sizeof(Individual));

	newPerson->Name = name;
	newPerson->IdNum = id;
	newPerson->marks = marks;
	newPerson->next = NULL;

	return newPerson;
}

Individual* Group(int groupSize)
{
	srand(time(NULL));

	int randMarks = rand() % 100 + 1;
	int randId = rand() % 1000 + 1;

	Individual* first = OnePerson(AllNames[0], randId, randMarks);
	Individual* temp = first;

	for (int i = 1; i < groupSize; i++)
	{
		randMarks = rand() % 100 + 1;
		randId = rand() % 1000 + 1;
		temp->next = OnePerson(AllNames[i],randId,randMarks);

		temp = temp->next;
	}
	return first;
}

void PrintOrderId(Individual* id) 
{
	Individual* tempId;
	Individual* changing = id;

	while (changing != NULL)
	{
		if (changing->next != NULL)
		{
			tempId = changing->next;
		}
		else 
		{
			tempId = NULL;
		}
		while (tempId != NULL)
		{
			if (changing->IdNum > tempId->IdNum) 
		    {
				Individual secTemp = { changing->Name, changing->IdNum,changing->marks };
				changing->IdNum = tempId->IdNum;
				changing->marks = tempId->marks;
				changing->Name = tempId->Name;

				tempId->IdNum = secTemp.IdNum;
				tempId->marks = secTemp.marks;
				tempId->Name = secTemp.Name;
		    }

			tempId = tempId->next;
		}
		changing = changing->next;
	}
}

void PrintOrderMarks(Individual* marks) 
{
	Individual* tempMarks;
	Individual* changing = marks;

	while (changing != NULL)
	{
		if (changing->next != NULL)
		{
			tempMarks = changing->next;
		}
		else
		{
			tempMarks = NULL;
		}
		while (tempMarks != NULL)
		{
			if (changing->marks > tempMarks->marks)
			{
				Individual secTemp = { changing->Name, changing->IdNum,changing->marks };
				changing->IdNum = tempMarks->IdNum;
				changing->marks = tempMarks->marks;
				changing->Name = tempMarks->Name;

				tempMarks->IdNum = secTemp.IdNum;
				tempMarks->marks = secTemp.marks;
				tempMarks->Name = secTemp.Name;
			}

			tempMarks = tempMarks->next;
		}
		changing = changing->next;
	}
}

void PrintResult(Individual* individual, int idDis, int marksDis) 
{
	Individual* NewData = individual;

	while (NewData != NULL)
	{
		if (NewData->IdNum != idDis && idDis != NULL)
		{

			NewData = NewData->next;

			continue;
		}

		if (NewData->marks < marksDis && marksDis >= 0)
		{

			NewData = NewData->next;

			continue;
		}

		printf("\nStudent ID: %i, ", NewData->IdNum);
		printf("Student Name: %s, ", NewData->Name);
		printf("Student Mark: %d, ", NewData->marks);
		printf("\n");

		NewData = NewData->next;
	}
}

void Options() 
{
	printf("\nPress 1 to dispaly Info in order of ID's.\n");
	printf("Press 2 to display Info based on Marks.\n");
	printf("Press 3 to display Students Info.\n");
	printf("Press 4 to display the Passed Students Info.\n");
	printf("Press 5 to quit.\n\n");
	printf("Enter the Selection: ");
}