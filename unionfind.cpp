#include<iostream>
#include<stdlib.h>
using namespace std;
struct label * makeset(int);
void print(struct node *);
int link(struct node * ,int,  struct node *,int );
struct node * find(struct label *);
struct node
{
	struct node *next;
	struct node *rep;

};
struct label
{
int count;
struct node * head;
struct node * tail;
};


struct label *temp1[10];


struct label * makeset(int i)
	{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct label *p = (struct label *) malloc(sizeof(struct label));
	p->count = 1;
    p->head = temp;
	p->tail = temp;
	temp->rep = temp;
	temp->next = NULL;
	return p;
	}

void print(struct label * temp[],int g)
{
	struct node *temp4 = (struct node *) malloc(sizeof(struct node));

	for(int i=0;i<g;i++)
{	cout<<endl;
	if(temp[i]!=NULL)
    {
	temp4 = temp[i]->head;
	for(;temp4 !=NULL;)
		{
		cout<<" Head : "<<temp[i]->head<<" tail : "<<temp[i]->tail<<" count : "<<temp[i]->count<<" Rep : "<<temp4->rep<<" \n";
		temp4=temp4->next;
		}
    }
}
}

int link(struct label * a,int x, struct label * b,int y)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    if(find(a)==find(b))
    {
        cout<<"Already Linked!!\n";
    }
  else if(a->count >= b-> count)
  	{

		a->tail->next = b->head;
		a->tail = b->tail;
		temp = find(b);
		a->count = a->count + b->count;

  		for(int d =y;temp!=NULL;d++)
		{
		temp->rep = a->head;
		temp=temp->next;
        temp1[d] = a;
		}
        return y;
  	}

  else
  {
  	  	b->tail->next = a->head;
  	  	b->tail = a->tail;
  	  	temp = find(a);
  	  	b->count = b->count + a->count;
        a->head = b->head ;
        a=b;

  		for(int d = x;temp!=NULL;d++)
		{
		temp->rep = b->head;
		temp=temp->next;
		temp1[d] = b;
		}
		return x;
  }

}

struct node * find(struct label * x)
{
        return (x->tail->rep);

}

int main()
{
int x,i,j,c=1,data,l=0,l1,l2;

struct node *temp = (struct node *) malloc(sizeof(struct node));

int f=0;
cout<<"enter no. of vertices";
cin>>l;



for(int i=0;i<l;i++)
{
temp1[i]=makeset(i);
}

for(int i=0;i<l;i++)
{
cout<<temp1[i]->head<<"  ";
}

while(c)
{
cout<<"\n1.union find \n2.print data";
cin>>x;

if(x==1)
{
cout<<"enter the vertex nos for union";
cin>>l1>>l2;
int d =link(temp1[l1-1],l1-1,temp1[l2-1],l2-1);
}

else if(x==2)
{
print(temp1,l);
}
cout<<"continue(0/1)\n";
cin>>c;
}

return 0;
}
