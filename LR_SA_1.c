#include <stdio.h>
#include <stdlib.h>

void print(int ANS)
{
	switch(ANS+1)
	{
		case 1: printf(" Provide all GPW veterans free air tickets"); break;
		case 2: printf(" Provide all participants of GPW with modern comfortable accomodation"); break;
		case 3: printf(" Open a chain of stores \"Veteran\""); break;
		case 4: printf(" Organize round-the-clock social security"); break;
		case 5: printf(" To provide preferential sale on credit"); break;
		case 6: printf(" Organize service with pre-order and home delivery"); break;	
		case 7: printf(" Provide veterans with high-tech medical care"); break;
		case 8: printf(" Grow up pension"); break;
	}
}

void interface(float m[8][8], int ANS)
{
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t|i/j |\tZ1  |\tZ2  |\tZ3  |\tZ4  |\tZ5  |\tZ6  |\tZ7  |\tZ8  |\n");
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t|Z1  |\t    |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\n", m[0][1], m[0][2], m[0][3], m[0][4], m[0][5], m[0][6], m[0][7]);
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t|Z2  |\t%.1f |\t    |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\n", m[1][0], m[1][2], m[1][3], m[1][4], m[1][5], m[1][6], m[1][7]);
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t|Z3  |\t%.1f |\t%.1f |\t     |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\n", m[2][0], m[2][1], m[2][3], m[2][4], m[2][5], m[2][6], m[2][7]);
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t|Z4  |\t%.1f |\t%.1f |\t%.1f |\t     |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\n", m[3][0], m[3][1], m[3][2], m[3][4], m[3][5], m[3][6], m[3][7]);
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t|Z5  |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t    |\t%.1f |\t%.1f |\t%.1f |\n", m[4][0], m[4][1], m[4][2], m[4][3], m[4][5], m[4][6], m[4][7]);
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t|Z6  |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t    |\t%.1f |\t%.1f |\n", m[5][0], m[5][1], m[5][2], m[5][3], m[5][4], m[5][6], m[5][7]);
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t|Z7  |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t    |\t%.1f |\n", m[6][0], m[6][1], m[6][2], m[6][3], m[6][4], m[6][5], m[6][7]);
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t|Z8  |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t%.1f |\t    |\n", m[7][0], m[7][1], m[7][2], m[7][3], m[7][4], m[7][5], m[7][6]);
	printf("\t+-------------------------------------------------------------------+\n");
	printf("\t+===================================================================+\n");
	printf("\t\t");		 print(ANS); printf("\n");
	printf("\t+===================================================================+\n");
}

int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b);
}

int main()
{
	float matrix[8][8] =
	{9, 0, 1, 1, 1, 1, 0, 0,
	 1, 9, 1, 1, 1, 1, 0, 0.5,
	 0, 0, 9, 0, 1, 1, 0, 0,
	 0, 0, 1, 9, 1, 1, 0, 0,
	 0, 0, 0, 0, 9, 0, 0, 0,
	 0, 0, 0, 0, 1, 9, 0, 0,
	 1, 1, 1, 1, 1, 1, 9, 0.5,
	 1, 0.5, 1, 1, 1, 1, 0.5, 9};

	float R =0;
	float C[8]= {0,0,0,0,0,0,0,0};
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j<8; j++)
		{
			C[i] += matrix[i][j];
		}
		R += C[i];
	}


	float V[8];
	printf("1)Provide all GPW veterans free air tickets\n");
	printf("2)Provide all participants of GPW with modern comfortable accomodation\n");
	printf("3)Open a chain of stores \"Veteran\"\n");
	printf("4)Organize round-the-clock social security\n");
	printf("5)To provide preferential sale on credit\n");
	printf("6)Organize service with pre-order and home delivery\n");	
	printf("7)Provide veterans with high-tech medical care\n");
	printf("8)Grow up pension\n");
	
	
	for (int i = 0; i<9; i++)
		{
			V[i] = C[i]/R;
			printf("\n variance %d = %f", i, V[i]);
		}
		printf("\n");
		float T[8];
		for(int i = 0; i<9;i++)
			T[i] = V[i];
	qsort(T, 9, sizeof(int), cmpfunc);
	for (int i = 0; i<9; i++)
		printf("\n %f", T[i]);
	
printf("\n");	
	float ANS_VALUE = V[0];
	int ANS = 0;

	for (int i = 1; i<8; i++)
		if(ANS_VALUE < V[i])
		{
			ANS_VALUE = V[i];
			ANS = i;
		}


	interface(matrix, ANS);
	return 0;
}
