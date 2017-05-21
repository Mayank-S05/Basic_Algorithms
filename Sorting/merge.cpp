#include<iostream>
using namespace std;

void mergesort(int*,int,int);
void merg(int * , int ,int , int );
int main()
{
int a[10]={23,6,25,57,43,88,34,84,1,36};
mergesort(a,0,9);
for(int i=0 ; i<=9;i++)
    {
        cout<<" "<<a[i];
    }
cout<<"\n";
return 0;
}

void mergesort(int a[], int p,int r)
{
    if(p<r)
    {
    int mid = (p+r) / 2;
    mergesort(a,p,mid);
    mergesort(a,mid+1,r);
    merg(a,p,mid,r);
    }
}

void merg(int a[] , int p,int q, int r)
{
    int n1 = q - p +1;
    int n2 = r - q ;
    int L[n1],R[n2];
    int i,j;
    for(i=0 ; i<n1 ; i++)
    {
        L[i] = a[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j] = a[j+q+1];
    }
        i=0,j=0;
        int k=p;
    while(i<n1 && j<n2)
      {
          if(L[i]<R[j])
           {
            a[k] = L[i];
            i++;
           }
        else if(L[i]>R[j])
        {
            a[k] = R[j];
                j++;
        }
        k++;
     }
     while(i<n1)
     {
        a[k] = L[i];
        i++;
        k++;
     }
     while(j<n2)
     {
        a[k] = R[j];
        j++;
        k++;
     }
}
