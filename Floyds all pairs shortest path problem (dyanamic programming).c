#include<stdio.h>

void path(int,int);

int a[10][10],b[10][10];

int main(void)
{
	int  n , i , j , k , p , q;
	
	printf("How many vertices are there?\n");
	scanf("%d",&n);
	
	printf("Write all cost of edges required, and if no edge, then insert a large number\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Between %d,%d: ",i+1,j+1);
			scanf("%d",&a[i][j]);
			b[i][j]=-1;
		}
	}
	
	printf("\nBetween which vertices you want to get shortest path?\n");
	scanf("%d %d",&p,&q);
	
	//Cost analysis
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if( a[i][j] > a[i][k] + a[k][j] )
				{
					a[i][j] = a[i][k] + a[k][j];
					b[i][j]=k;
				}
			}
		}
	}
	
	//Path analysis
	printf("\nPath analysis: \n");
	printf("%d",p);
	path(p-1,q-1);
	printf("%d",q);
	
	printf("\nCost analysis: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("  %d  ",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

void path(int start , int end)
{
	int k;
	k=b[start][end];
	
	if(k==-1)
		return;
	else
	{
		path(start,k);
		printf("  %d  ",k+1);
		path(k,end);
	}
	return;
}

