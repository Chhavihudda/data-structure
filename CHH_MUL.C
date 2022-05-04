#include<stdio.h>
#include<conio.h>
typedef struct nodetype{
int coeff;
int  power;
struct node_type*next;
} node;
void main()
{
node *poly1,*poly2,*poly3;
void readpoly(node **);
void printpoly(node *);
void multipoly(node *,node *,node **);
void addnode(node ***,int,int);
void *search(node *,int);
void delpoly(node **);
poly1=poly2=poly3=NULL;
prinf("program to multiply polynommial");
printf("\n++++++++++++++++++++++++++++++\n\n");
printf("enter the terms of polynomial\n ");
printf("in ascending order\n");
printf("enter first polynomial\n");
readoly(&poly1);
clrscr();
printf("enter second polynomial\n");
readpoly(&poly2);
multipoly(poly1,poly2,&poly3);
printf("\n product of polynommial \n\n");
printpoly(poly1);
printf("\n\nand\n\n");
printpoly(poly2);
printf("\n\nis\n\n");
printpoly(poly3);
printf("\n\n\npress any continue to exit \n");
getch();
delpoly(&poly1);
delpoly(&poly2);
delpoly(&poly3);
		     }
void insertnode(node ***ptr,int coef,int powe)
{
node *tempptr,*loc,*ploc;
tempptr=(node*) malloc (sizeof(node));
tempptr->coeff=coef;
tempptr->power=powe;
if(**ptr==NULL)
{
tempptr->next=NULL;
**ptr=tempptr;
}
else{
ploc=NULL;
loc=**ptr;
while((loc!=NULL&&powe<loc->power))
{
ploc=loc;
loc=loc->next;
}
tempptr->next=ploc->next;
ploc->next=tempptr;
}

void addnode(node ***ptr,int coef, int powe)
{
node *tempptr;
static node *last;
tempptr=(node *)malloc(sizeof(node));
tempptr->coeff=coef;
tempptr->power=powe;
tempptr->next=NULL;
if(**ptr==NULL)
**ptr=last=tempptr;
else{
last->next=tempptr;
last=tempptr;
}
}

void readpoly(node **p)
{
int coefficient;
int power;
while(1)
{
printf("enter the degree of x:");
scanf("%d",&power);
printf("enter its coefficient :");
scanf("%d",&coefficient);
addnode(&p,coefficient,power);
printf("\n any more term(Y/N)?:");
if(toupper(getche())=='N')
break;
}

void printpoly(node *ptr)
{
if(ptr!=NULL)
printf("%dx^%d",ptr->coeff,ptr->power);
for(ptr=ptr->next;ptr!=NULL;ptr=ptr->next)
{
if(ptr->coeff>0)
printf("+");
if(ptr->power==0)
printf("%d",ptr->coeff);
else if(ptr->power==1)
printf("%dx",ptr->coeff);
else
printf("%dx^%d",ptr->coeff,ptr->power);
}
}

void multipoly(node *ptr1,node *ptr2,node **ptr3)
{
int powe,coef;
node *temp, *loc ,*tt;
while(ptr1!=NULL)
{
temp=ptr2;
while(temp!=NULL)
{
coef=ptr1->coeff*temp->coeff;
powe=ptr1->power+temp->power;
tt=*ptr3;
loc=search(tt,powe);
if(loc==NULL)
insertnode(&ptr3,coef,powe);
else
loc->coeff+=coef;
temp=temp->next;
}
ptr1=ptr1->next;
}

void delpoly(node **ptr)
{
node *temp;
while(ptr!=NULL)
{
temp=*ptr;
*ptr=(*ptr)->next;
free(temp);
}
}

node *search(node *ptr,int degree)
{
while(ptr!=NULL)
{
if(ptr->power==degree)
break;
ptr=ptr->next;
}
return ptr;
}



