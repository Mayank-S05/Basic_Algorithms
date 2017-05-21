#include<iostream>
#include<stdlib.h>
using namespace std;
void en(int*,int);
void deq(int*);
int f =-1;
int b = -1;
int main()
{
   int a[10];
   int c = 1 ;
   while(c)
    {   int x;
        cout<<"\n1.enqueue \n2.dequeue \n3.print";
        cin>>x;
        if(x==1)
        {
        int n;
        cout<<"enter the data to add";
        cin>>n;
        en(a,n);
        }
        else if(x==2)
         deq(a);
        else
        {   cout<<f<<" "<<b;
                    for(int i=f+1;i<=b;i++)
            cout<<"elements are : "<<a[i]<<"  ";
        }
    }
return 0;
}

void en(int a[] , int s)
{
 if (b>=9)
    {
        cout<<"\nfull!!";
        f=-1;
        b=-1;
    }
    else
    {
    a[++b] = s;
    }
}

void deq(int a[])
{
if(f==b)
    cout<<"under flow!!";
else
    cout<<"deleted element "<<a[++f];
}
