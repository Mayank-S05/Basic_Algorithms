#include<iostream>
#include<stdlib.h>
using namespace std;
struct label * makeset(int);
int link(struct node * ,int );
void en(struct node * ,struct node *);
struct node * deq(struct node * );
int f =-1;
int b = -1;


struct node
{   int data;
    int d;
	struct node *next;
	struct node *rep;
    int b;
    int g;
    int w;
    struct node *parent;
};
struct label
{
struct node * head;
struct node * tail;
};


struct label *temp1[10];


struct label * makeset(int i)
	{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct label *p = (struct label *) malloc(sizeof(struct label));
    p->head = temp;
	p->tail = temp;

	temp->w=1;
	temp->g=0;
	temp->b=0;
	temp->data=i;
	temp->parent = NULL;
	temp->d=99999;
	temp->rep = temp;
	temp->next = NULL;
	return p;
	}

void en(struct node * s[],struct node *temp)
{
 if (b>=9)
    {
        cout<<"\nfull!!";
        f=-1;
        b=-1;
    }
    else
    {
    s[++b] = temp;
    }
}

struct node * deq(struct node * s[])
{
if(f==b)
    cout<<"under flow!!";
else
    ++f;
    int x = s[f]->data;
return (temp1[x]->head);
}


int link(struct label * a,int x)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));

    temp->w=1;
	temp->g=0;
	temp->b=0;
	temp->data=x;
	temp->parent = NULL;
	temp->d=99999;
	temp->rep = temp1[x]->head;
	temp->next = NULL;
	a->tail->next =temp;
    a->tail = temp;
}

int main()
{
int x,i,j,l=0;

struct node *temp = (struct node *) malloc(sizeof(struct node));
struct node *temps = (struct node *) malloc(sizeof(struct node));
struct node *u = (struct node *) malloc(sizeof(struct node));
struct node *v = (struct node *) malloc(sizeof(struct node));
struct node *q[10];

cout<<"enter no. of vertex";
cin>>l;

for(int i=0;i<l;i++)
{
temp1[i]=makeset(i);
}
cout<<endl;

link(temp1[0],1);
link(temp1[0],4);
link(temp1[1],0);
link(temp1[1],5);
link(temp1[2],5);
link(temp1[2],6);
link(temp1[2],3);
link(temp1[3],6);
link(temp1[3],7);
link(temp1[3],2);
link(temp1[7],6);
link(temp1[7],3);
link(temp1[6],2);
link(temp1[6],5);
link(temp1[6],3);
link(temp1[6],7);
link(temp1[5],1);
link(temp1[5],6);
link(temp1[5],2);
link(temp1[4],0);

temp1[1]->head->g =1;
temp1[1]->head->w=0;
en(q,temp1[1]->head);
    cout<<"Path is : ";
    while(f<b)
    {
    u = deq(q);
    cout<<u->data<<" ";
    temp = u->next;
    temps = temp->rep;


    while(temp != 0)
    {
    v = temps;
    if(v->w==1)
    {   v->g=1;
        v->w=0;
        v->parent = u;
        en(q,v);
    }
    temp = temp->next;
    if(temp!=0)
    temps = temp->rep;
    }
    u->g=0;
    u->b=1;

}
return 0;
}
