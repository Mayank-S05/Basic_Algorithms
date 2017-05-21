#include<iostream>
using namespace std;
void insertion(int*);
void swaps(int*,int,int);
int main()
{
int a[10]={23,6,25,57,43,88,34,84,1,36};
insertion(a);

for(int i=0 ; i<=9;i++)
    {
        cout<<" "<<a[i];
    }
cout<<"\n";

return 0;
}

void insertion(int a[])
{
int i=0,j=1;

for(int k=1;k<=9;k++)
    {   int key = a[k];
        j=k-1;
        while(j>=0&&a[j]>key)
        {
          swaps(a,j,j+1);
            --j;
        }
        a[j+1]=key;
    }

}

    void swaps(int a[],int i,int j)
{
    int t = a[i];
    a[i]=a[j];
    a[j]=t;
}
