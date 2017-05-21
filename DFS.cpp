#include<iostream>
#include<stdlib.h>
using namespace std;
struct label * makeset(int);
int link(struct node * ,int );
void DFS_visit(struct node *);
int time=0;
struct node
{   int data;
    int d;
    int f;
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
	temp->f=0;
	temp->rep = temp;
	temp->next = NULL;
	return p;
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
	temp->f = 0;
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

cout<<"enter no. of vertex";
cin>>l;

for(int i=0;i<l;i++)
{
temp1[i]=makeset(i);
}
cout<<endl;

//link(temp1[0],1);
//link(temp1[0],3);
//link(temp1[1],0);
//link(temp1[1],4);
//link(temp1[2],5);
link(temp1[2],3);
//link(temp1[2],7);
link(temp1[3],1);
//link(temp1[3],7);
//link(temp1[3],2);
//link(temp1[7],6);
//link(temp1[7],3);
//link(temp1[6],2);
//link(temp1[6],5);
//link(temp1[6],3);
//link(temp1[6],7);
link(temp1[5],0);
//link(temp1[5],6);
//link(temp1[5],2);
link(temp1[4],0);


    cout<<"Path is : \n";
    for(int i=0;i<l;i++)
    {
        u = temp1[i]->head;
        if(u->w==1)
        {
        DFS_visit(u);
        cout<<endl;
        }
    }

return 0;
}

void DFS_visit(struct node *u)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct node *temps = (struct node *) malloc(sizeof(struct node));
        u->w=0;
        u->g=1;
        u->d = ++time;
        temp = u->next;
        if(temp!=NULL)
        {
            temps = temp->rep;
        while(temp != NULL)
        {
              if(temps->w == 1)
              {
                    temps->g=1;
                    temps->w=0;
                    temps->parent = u;
                    DFS_visit(temps);
              }
        temp = temp->next;
        if(temp!=0)
        temps= temp->rep;
        }
        }
   u->g=0;
   u->b=1;
   u->f = ++time;
    cout<<" "<<u->data;
}

