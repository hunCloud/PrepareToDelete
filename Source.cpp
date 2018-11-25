#define use_CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct WORD{
	char Name[256];
	char Meaning[512];
};

void inputDict(int &i,int &j, WORD a[])
{
	FILE *f;
	f = fopen("DICT.txt", "rt");
	i = 0, j = 0;
	while (!feof(f))
	{
		fscanf(f, "%s", a[i++].Name);
		fgets(a[j++].Meaning, 512, (FILE*)f);
	}
}

void searchDict(char a[],int i,int j, WORD D[])
{
	for (int k = 0; k < i; k++)
	{
		if (strcmp(D[k].Name, a) == 0)
			printf("%s", D[k].Meaning);
	}
}

void main()
{
	char a[256];
	int i, j;
	WORD Dict[1000];
	inputDict(i, j, Dict);
	printf("Nhap tu can tra: ");
	scanf("%s", a);
	searchDict(a, i, j, Dict);
}