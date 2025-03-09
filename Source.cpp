#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int numaraLit(char* sir)
{
	int num = 0;
	while (sir[num] != '\0')
		num++;
	return num;
}

int main()
{
	char text[100];
	scanf(" %[^\n]", text);
	char vectorCuv[10][100];
	int nr = 0;
	char* p = strtok(text, " ");
	while (p)
	{
		strcpy(vectorCuv[nr], p);
		nr++;
		p = strtok(NULL, " ");
	}
	for (int i = 0; i < nr; i++)
	{
		for (int j = i + 1; j < nr; j++)
		{
			if (numaraLit(vectorCuv[i]) < numaraLit(vectorCuv[j]))
			{
				char aux[100];
				strcpy(aux, vectorCuv[i]);
				strcpy(vectorCuv[i], vectorCuv[j]);
				strcpy(vectorCuv[j], aux);
			}
			else
				if (numaraLit(vectorCuv[i]) == numaraLit(vectorCuv[j]))
					if(strcmp(vectorCuv[i], vectorCuv[j]) > 0)
					{
						char aux[100];
						strcpy(aux, vectorCuv[i]);
						strcpy(vectorCuv[i], vectorCuv[j]);
						strcpy(vectorCuv[j], aux);
					}
		}
	}
	for (int i = 0; i < nr; i++)
	{
		printf("%s\n", vectorCuv[i]);
	}
	return 0;
}

