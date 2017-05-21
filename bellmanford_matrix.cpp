
#include<iostream>
#include<stdlib.h>
using namespace std;
struct label * makeset(int);
int link(struct node * ,int );
void DFS_visit(struct node *);
int relax (struct label * , struct node *);

int time=0;
int c=1;
struct node
{   int data;
    int weight;

    //int f;
	struct node *next;
	struct node *rep;
    //struct node *parent;
};
struct label
{
struct node * head;
struct node * tail;
int d;
//struct label * own;
};


struct label *temp1[10];


struct label * makeset(int i)
	{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
    struct label *p = (struct label *) malloc(sizeof(struct label));
    //p->own = p;
	p->head = NULL;
	p->tail = NULL;
    p->d =9999;
	//temp->w=1;
	//temp->g=0;
	//temp->b=0;
	//temp->data=i;
	//temp->parent = NULL;
	//temp->weight=99999;
	//temp->f=0;
	//temp->rep = temp;
	//temp->next = NULL;
	return p;
	}


int link(struct label * a,int x,int w)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));

    //temp->w=1;
	//temp->g=0;
	//temp->b=0;
	temp->data=x;
	//temp->d=9999;
	//temp->parent = NULL;
	temp->weight=w;
	//temp->f = 0;
	if(a->head == NULL && a->tail == NULL)
    {
        a->head = temp;
        a->tail = temp;
    }
    else
    {
    a->tail->next =temp;
    a->tail = temp;
	}
	temp->rep = temp1[x]->head;
	temp->next = NULL;
}
int main()
{
int x,i,j,l=0;

struct node *temp = (struct node *) malloc(sizeof(struct node));
struct node *temps = (struct node *) malloc(sizeof(struct node));
struct label *u = (struct label *) malloc(sizeof(struct label));
struct label *v = (struct label *) malloc(sizeof(struct label));

cout<<"enter no. of vertex";
cin>>l;

for(int i=0;i<l;i++)
{
temp1[i]=makeset(i);
}

cout<<endl;

link(temp1[0],2,6);

link(temp1[0],3,3);

link(temp1[1],0,3);

//link(temp1[1],4);
link(temp1[2],3,2);
//link(temp1[2],3);
//link(temp1[2],7);
link(temp1[3],1,1);
link(temp1[3],2,1);
link(temp1[4],3,2);
link(temp1[4],1,4);
//link(temp1[7],3);
//link(temp1[6],2);
//link(temp1[6],5);
//link(temp1[6],3);
//link(temp1[6],7);
//link(temp1[5],0);
//link(temp1[5],6);
//link(temp1[5],2);
//link(temp1[4],0);

     u = temp1[0];
     u->d =0;
    for(int i=1;i<l;i++)
    {
        u=temp1[i-1];
        v=temp1[i];
        temp = u->head;
        while(temp!=NULL)
        {
            //cout<<"ab";
            relax(u,temp);
            temp = temp->next;
        }
        cout<<endl;
    }
    c=1;
    for(int i=1;i<l;i++)
    {
        u = temp1[i-1];
        v = temp1[i];
        temp = u->head;
        while(temp!=NULL)
        {
            relax(u,temp);
            if(c==0)
                    {
                        cout<<"not possible";
                    return 0;
                    }
            temp = temp->next;

        }
    }
for(int i=0;i<l;i++)
{
cout<<"distance of "<<i<<" vertex is : "<<temp1[i]->d<<endl;
}
return 0;
}


int relax (struct label * a, struct node * temp)
{
    if((temp1[temp->data]->d) > (temp->weight + a->d) )
    {
        temp1[temp->data]->d = temp->weight + a->d;
        c=0;
    }
    else
        {
            c=1;
            return 0;
        }
}
