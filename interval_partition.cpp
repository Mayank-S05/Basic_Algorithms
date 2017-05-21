#include<iostream>
using namespace std;
void swap(int*,int,int);
void heapify(int *,int);
void buildheap(int*);
void heapsort(int*);
void eftf(int * ,int *);
int heapsize = 5;
int st[5] = {2,4,6,8,9};
int end[5] = {7,5,10,12,13};
int x=0;
int s=0;
int main()
{
buildheap(st);
 for(int j =0 ;j<5;j++)
     cout<<st[j]<<" ";
for(int j =0 ;j<5;j++)
     cout<<" "<<end[j]<<" ";

heapsize=5;
eftf(st,end);

cout<<endl;
cout<<"end:";
 for(int j =0 ;j<5;j++)
     cout<<end[j]<<" ";
     cout<<endl<<"start:";
for(int i =0 ;i<5;i++)
cout<<st[i]<<" ";
return 0;
}

void eftf(int a[],int b[])
{
    int c[5],co=0;
    c[0]=0;
for(int i=0;i<=4;i++)
{    cout<<"\na:"<<a[0]<<" ";
    s=0;
     heapify(a,0);
    cout<<"\na:"<<a[0]<<" ";
    s=1;
     buildheap(c);
      cout<<a[0];
    for(int i=0;i<=4;i++)
    cout<<"\nc"<<c[i];
     if(a[0]>=c[0])
    {   cout<<endl;

        c[0] = b[0];
        a[0]=999999;
    }
    else
       {
            co++;
           c[co] = b[0];

           a[0]=999999;
       }
}
       cout<<"c is"<<co+1;

    }




void swap(int a[],int x,int y)
{

int t;
     t=a[x];
     a[x] = a[y];
     a[y] = t;
}

void heapify(int a[],int i)
{


     int l = (2*i) + 1;
     int r = (2*i) + 2;
     int smallest;



     if(l<heapsize && a[l]<a[i])
          smallest = l;
          else
          smallest = i;

      if(r<heapsize && a[r]<a[smallest])
          smallest = r;

     if(smallest!=i)
   {
     swap(a,smallest,i);
     if(s==0)
     swap(end,smallest,i);
     heapify(a,smallest);
   }

}
void buildheap(int a[])
{
   int h = 5/2;
   while(h!=-1)
   {
       heapify(a,h);
       h--;
   }

}

/*void heapsort(int a[])
{
 for(int i = 4;i>=0;i--)
     {
          swap(a,0,i);
          swap(st,0,i);
          heapsize--;
          heapify(a,0);
     }

}
*/
