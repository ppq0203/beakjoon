#include <stdio.h>
#include <stdlib.h>
#define MAX 9 //n ,m <= 8

int func_compare(const void * first, const void * second);
int makelist(int,int,int[MAX],int,int[MAX]);

int main()
{
	int n, m;
	int position = 1; // start list position = 1
	int list[MAX] = {0};
	int numlist[MAX] = {0};
	list[0] = 1;
	scanf("%d %d", &n, &m); // input n,m 
	for(int i = 1; i <= n; i++)
		scanf("%d", numlist+i); // input the number of n
	qsort((int *)numlist, n+1, sizeof(int), func_compare); //sort number list
	makelist(n,m,list, position, numlist);

	return 0;
}

int func_compare(const void * first, const void * second) 
{
	if (*(int*)first > *(int *)second) //ascending order
		 return 1;
	else
		return 0; 
}

void printlist(int[MAX],int,int[MAX]);

int makelist(int n, int m, int list[MAX], int position, int numlist[MAX]) // make & print number
{
	int include;
	int save;
	if(position > m) // if makelist finish print list
	{
		printlist(list, m, numlist);
		return 0;
	}
	else
	{
		for(int i = list[position-1]; i <= n; i++) // loop previous number ~ n , if position = 1 (first loop),i = 1~n because list[0] = 1
		{
			list[position] = i; // put list number
			save = list[position];
			makelist(n, m, list, position+1, numlist); // find next number
			while (numlist[save] == numlist[i+1]) //compare nextlist number if it's same, pass next number
				++i;
		}
		return 0;
	}
}

void printlist(int list[MAX], int m, int numlist[MAX])
{
	for(int i = 1; i <= m; i++)
	{
		printf("%d ", numlist[list[i]]);
	}
	printf("\n");
}