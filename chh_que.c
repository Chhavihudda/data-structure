#include<stdio.h>
#include<conio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int data);
void dequeue();
void display();
void peek();
void main()
{
int data,ch;
clrscr();
while(1){
printf("ENTER CHOICE\n1.enqueue\t2.dequeue\t3.display\t4.peek\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter data\n");
	scanf("%d", &data);
	 enqueue(data);
	break;
case 2: dequeue(data);
	   break;
case 3: display();
	 break;
case 4: peek();
	break;
case 5: exit(1);
	 break;
default :printf("xxx U ENTER WRONG CHOICE xxx\n");
}}}


void enqueue(int x)
{
if(rear==N-1)
{printf("****OVER FLOW****\n");}
else if(front==-1 && rear==-1){
front=rear=0;
queue[rear]=x;
}
else  {
rear++ ;
queue[rear]=x;}}

void dequeue(){
if(front== -1 && rear== -1)
{
printf("****UNDER FLOW****\n");
}
else if(front==rear){
front=rear=-1;
}
else
{
printf("\nelement delete=%d\n",queue[front]);
front++;
}
}

void display()
{
int i;
if(front==-1 && rear==-1)
{
printf("********queue is empty**********\n");
}
else{
for(i=front;i<rear+1;i++)
{
printf("\n%d\n",queue[i]);
}}}

void peek(){
if(front==-1 && rear==-1)
{
printf("**EMPTY**\n");
}
else {
printf("\n%d\n",queue[front]);
}}
