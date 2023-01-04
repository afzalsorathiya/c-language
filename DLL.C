/* 'C' Program for maintaining Doubly Linked List with its different operations  */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
  int n;
  struct node *l,*r;
}*start=NULL,*temp;

void ins();
void del();
void traverse();

void instop();
void insbot();

void deltop();
void delbot();

int main()
{
  int c;
 

  do
  {
    printf("\n ---------------------Doubly Linked List--------------------------\n");
    printf("\n 1 : Insertion at Top ");
    printf("\n 2 : Insertion at Bottom ");
    printf("\n 3 : Deletion at Top ");
    printf("\n 4 : Deletion at Bottom ");
    printf("\n 5 : Traverse ");
    printf("\n 6 : Exit ");
    printf("\n Enter ur choice : ");
    scanf("%d",&c);
    switch(c)
    {
      case  1 : ins();
		instop();
		break;
      case  2 : insbot();
		break;
      case  3 : deltop();
		break;
      case  4 : delbot();
		break;
      case  5 : traverse();
		break;      
	
      default : printf("\n U've entered wrong choice.");
    }
  }while(1);
return 0;
}

void ins()
{
  temp=(struct node *)malloc(sizeof(struct node));
  if(temp==NULL)
      printf("\n Overflow");
  else
  {
    printf("\n Enter element u want 2 insert :");
    scanf("%d",&temp->n);
    if(start==NULL)
    {
      temp->l=NULL;
      temp->r=NULL;
      start=temp;
    }
  }
}

void instop()
{
  if(start!=NULL)
  {
    temp->l=NULL;
    temp->r=start;
    start->l=temp;
    start=temp;
  }
}

void insbot()
{
  struct node *ptr;
  ptr=start;

  ins();
  if(start!=NULL)
  {
    while(ptr->r!=NULL)
	  ptr=ptr->r;
    ptr->r=temp;
    temp->l=ptr;
    temp->r=NULL;
  }
}

void traverse()
{
  struct node *ptr;
  if(start==NULL)
      printf("\n Doubly Linked List is empty");
  else
  {
    ptr=start;
    printf("\n Elements of Doubly Linked List :\n");
    while(ptr!=NULL)
   {
     printf("%d\n",ptr->n);
     ptr=ptr->r;
   }
  }
}

void del()
{
  if(start==NULL)
  {
      printf("\n Underflow");
      return;
  }
  else
      temp=start;
}

void deltop()
{
  del();
  if(start!=NULL)
  {
    start=start->r;
    start->l=NULL;
    printf("\n Deleted element : %d",temp->n);
    free(temp);
  }
}

void delbot()
{
  struct node *t,*ptr;

  del();
  if(start!=NULL)
  {
    if(temp->r==NULL)
	start=NULL;
    else
    {
      while(temp->r!=NULL)
      {
	t=temp;
	temp=temp->r;
      }
      t->r=NULL;
    }
    printf("\n Deleted element : %d",temp->n);
    free(temp);
  }
}



