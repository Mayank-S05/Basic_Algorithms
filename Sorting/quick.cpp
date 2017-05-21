#include<iostream>
using namespace std;

void quicksort(int*,int,int);
void swaps(int*,int,int);
int part(int*,int,int);

int main()
{
int a[10]={23,6,25,57,43,88,34,84,1,36};
quicksort(a,0,9);
for(int i=0 ; i<=9;i++)
    {
        cout<<" "<<a[i];
    }
cout<<"\n";
return 0;
}

int part(int a[],int p,int q)
{
int j=p,i=p-1;
int pivot = a[q];

for(int k=p;k<q;k++)
{
        if(a[k]<pivot)
        {   swaps(a,i+1,k);
            i++;
            j++;
        }
        else if(a[k]>pivot)
            {

                j++;

            }
}
swaps(a,i+1,q);
return(i+1);
}

void quicksort(int a[] , int p, int r)
{
    if(p<r)
    {
    int t = part(a,p,r);
    quicksort(a,p,t-1);
    quicksort(a,t+1,r);
    }
}

void swaps(int a[],int i,int j)
{
    int t = a[i];
    a[i]=a[j];
    a[j]=t;
}
