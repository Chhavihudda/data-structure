#include<stdio.h>
#include<conio.h>
#include< alloc.h>
typedef struct nodeType{
int coeff;
int power;
struct nodeType *next;
}node;
void main()
{
node *poly1,*poly2,*poly3;
int choice,element,after,before;
void readpolynomial(node **);
void printpolynomial(node *);
void addpolynomial(node *,node *,node**);
void addnode(node **,float,int);
void deletepolynomial(node **);
poly1=poly2=poly3=NULL;
clrscr();
printf("\nProgram to Add Two Polynomial\n");
printf("\n    \n");
printf("Enter first Polynomial");
readpolynomial(&poly1);
printf("Enter second Polynomial");
readpolynomial(&poly2);
addpolynomial(poly1,poly2,&poly3);
printf("\nSum of polynomial\n");
printpolynomial(poly1);
printf("\nand\n");
printpolynomial(poly2);
printf("\nis");
printpolynomial(poly3);
getch();
deletepolynomial(&poly1);
deletepolynomial(&poly2);
deletepolynomial(&poly3);
}
void addnode (node **ptr,float coef,int powe)
{
node *tempPtr;
tempPtr=(node*)malloc(sizeof(node));
tempPtr->coeff=coef;
tempPtr->power=powe;
if(*ptr==NULL)
{
tempPtr->next=NULL;
*ptr=tempPtr;
}
else
{
tempPtr->next=*ptr;
*ptr=tempPtr;
}
}

void readpolynomial(node **p)
{
int coefficient,power;
printf("Enter the coefficient in ascending order of power");
while(1)
{
printf("enter the degree of x:\n");
scanf("%d",&power);
printf("enter its coefficient\n");
scanf("%d",&coefficient);
addnode(p,coefficient,power);
printf("Any more term(Y/N)?:\n");
if(toupper(getch())=='N')
break;
}
}
void printpolynomial(node *ptr)
{
if(ptr!=NULL)
printf("%d%d",ptr->coeff,ptr->power);
for(ptr=ptr->next;ptr!=NULL;ptr=ptr->next)
{
if(ptr->coeff>0)
printf("+");
if (ptr->power==0)
printf("%d",ptr->coeff);
else if(ptr->power==1)
printf("%d",ptr->coeff);
else
printf("%d%d",ptr->coeff,ptr->power);
}

}


void addpolynomial(node *ptr1,node *ptr2, node **ptr3)
{int powe;
int coef;
while ((ptr1!=NULL)&&(ptr2!=NULL))

{
 if(ptr1->power>ptr2->power)
 {
 coef=ptr1->coeff;
 powe=ptr1->power;
 ptr1=ptr1->next;
 }
 else if(ptr1->power<ptr2->power)
 {
 coef=ptr2->coeff;
 powe=ptr2->power;
 ptr2=ptr2->next;
 }
 else
 {
 coef=ptr1->coeff+ptr2->coeff;
 powe=ptr1->power;
 ptr2=ptr2->next;
 }
 if(coef!=0)
 addnode(ptr3,coef,powe);
 if(ptr1==NULL)
 {
 for(;ptr2!=NULL;ptr2=ptr2->next)
 addnode(ptr3,ptr2->coeff,ptr2->power);
 }
 else if(ptr2==NULL)
 {
 for(;ptr1!=NULL;ptr1=ptr1->next)
 addnode(ptr3,ptr2->coeff,ptr2->power);
 }
 }
 }
 void deletepolynomial(node **ptr)
 {
 node *temp;
 while (*ptr!=NULL){
 temp=*ptr;
 *ptr=(*ptr)->next;
 free(temp);
 }
 }

