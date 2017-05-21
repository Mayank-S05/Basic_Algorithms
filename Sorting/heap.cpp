#include<iostream>
using namespace std;
void heapify(int*,int,int);
void buildheap(int * , int ,int );
void heapsort(int*);
int b[15];
int main()
{
int a[15] = {23,6,25,57,43,88,34,84,75,36};
buildheap(a,5,9);

heapsort(a);
for(int i=0;i<10;i++)
{
    cout<<"  "<<a[i];
}

return 0;
}

void heapify(int a[] , int i ,int x)
{
    int l = 2*i+1;
    int r = (2*i)+2;
    int largest = i;
    if(l<=x && a[i]<a[l])
                largest = l;

    if(r<=x && a[largest]<a[r])
            largest = r;
    if(i!=largest)
    {
            int t =a[i];
            a[i] = a[largest];
            a[largest] = t;
            heapify(a,largest,x);
    }

}

void buildheap(int a[] , int i,int x)
{
    while(i>=0)
    {
        heapify(a,i,x);
        i--;
    }

}

void heapsort(int a[])
{

    int x =9;
    int t;
    while(x>=0)
    {
    t = a[0];
    a[0] = a[x];
    a[x] = t;
    x--;
    heapify(a,0,x);
    }
}
