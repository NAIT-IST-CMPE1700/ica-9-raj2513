#pragma once

typedef struct  Individual
{
	char* Name;
	int IdNum;
	int marks;
	struct  person* next;
}Individual;

Individual* OnePerson(char* name, int id, int marks);
Individual* Group(int groupSize);

void PrintOrderId(Individual* id);
void PrintOrderMarks(Individual* marks);
void PrintResult(Individual* individual, int idDis, int marksDis);
void Options();

static const char AllNames[10][10] = { "Raj","Liam", "Ethan", "Bruno", "Akash", "Kevin", "Will", "Patrick", "Tim", "Jeese" };