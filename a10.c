#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void push(int);
int pop();
void display();

int write()
{
   int num;
   FILE *fptr;
   fptr = fopen("e:\\numbers.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   int i;
	for(i=top;i>=0;i--)
		fprintf(fptr,"%d\t",stack[i]);
   
   fclose(fptr);

}

int read()
{
	int num;
   FILE *fptr;

   if ((fptr = fopen("e:\\numbers.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }

   while(fscanf(fptr,"%d",&num) == 1)
			push(num);
   fclose(fptr); 
}




void main()
{
	read();
	printf("\nData in file : \n");
	display();
    int ch,data;
    printf("\t****MENU****\n");
    printf("\t 1. PUSH\n");
    printf("\t 2. POP\n");
    printf("\t 3. DISPLAY\n");
    printf("\t 4. EXIT\n");
    do{
        printf("\t Enter Your Choice : ");
        scanf("\t %d",&ch);
        switch(ch)
        {
            case 1:
                printf("\t Enter Data : ");
                scanf("%d",&data);
                push(data);
                write();
                break;
            case 2:
                pop();
                write();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default :
                printf("\t Enter Proper Choice \n");
                break;
        }
    }while(ch!=4);
    
    
}
void push(int item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

int pop()
{
    int item;
	if(top <0)
	{
		printf("stack under flow:");
    }
	else
	{
		item = stack[top];
		printf("\t %d : DELETE\n",item);
		top = top-1;
		return(item);
	}
}
void display()
{
    if(top==-1)
    {
        printf("\tSTACK IS EMPTY\n");
    }
    int i;
    for(i=top;i>=0;i--)
    {
        printf("\t| %d |\n",stack[i]);
    }
}

