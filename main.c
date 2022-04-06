
#include<stdio.h>
#include <conio.h>
 

 int insert_array_element(int a[],int n);
 int show_array_element(int a[],int n);
 
int main()
{
    int a[1000],i,n;  
 
    printf("Enter size of array: ");
    scanf("%d",&n);
 
    printf("Enter %d elements in the array : ", n);
    insert_array_elementt(a,n);
    printf("\nElements in array are: ");
    show_array_element(a,n);
 
    return 0;
}


 int insert_array_elementt(int a[],int n)
 { 
   int i;
    
for(i=0;i<n;i++)
     {
         scanf("%d", &a[i]);
   } 
         
   
          
 }

int  show_array_element(int a[],int n)
{ 
    int i;
    
	for(i=0;i<n;i++)
    {
        printf("%d  ", a[i]);
    } 
}