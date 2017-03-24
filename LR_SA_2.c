#include <stdlib.h>
#include <stdio.h>
/*
	S[i] = R[i]/R, i = 1,m, R = summ(R[i])
	V[j] = summ(P[i][j] * S[i]), j = 1,n
	Z[1],Z[2]..Z[n] ~ V[j]
*/
void print_ans(int ans)
{
	printf("\t+=========================================+\n");
	printf("\t");
	switch(ans)
	{
		case 1: printf("An increase in the wages of the city administration."); break;
		case 2: printf("Repair of roads."); break;
		case 3: printf("An increase in the wages of medical workers."); break;
		case 4: printf("Repair of the court territories."); break;
	}
	printf("\n");
	printf("\t+=========================================+\n");
}

int calculating( float P[3][4], float R[3], float S[3], float v[4])
{
	int ans = -1;
	return ans;
}

void interface(float P[3][4], int ANS)
{
	printf("\t+-----------------------------------------+\n");
	printf("\t|Ei/Zj |\tZ1  |\tZ2  |\tZ3  |\tZ4  |\n");
	printf("\t+-----------------------------------------+\n");
	printf("\t|  E1  |\t%.2f |\t%.2f |\t%.2f |\t%.2f |\n", P[0][0], P[0][1], P[0][2], P[0][3]);
	printf("\t+-----------------------------------------+\n");
	printf("\t|  E2  |\t%.2f |\t%.2f |\t%.1f |\t%.2f |\n", P[1][0], P[1][1], P[1][2], P[1][3]);
	printf("\t+-----------------------------------------+\n");
	printf("\t|  E3  |\t%.2f |\t%.2f |\t%.2f |\t%.2f |\n", P[2][0], P[2][1], P[2][2], P[2][3]);
	printf("\t+-----------------------------------------+\n");


}

int main()
{
	float P[3][4] = {0.20, 0.30, 0.20, 0.30,
					 0.10, 0.35, 0.20, 0.35,
					 0.60, 0.00, 0.00, 0.40};
	float R[3] = {8, 5, 10};
	float S[3] = {0, 0, 0};
	float V[4] = {0, 0, 0, 0};
	int ans = calculating( R, S, V);
	print_ans(ans);
	return 0;
}