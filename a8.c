// C program to Implement a stack 
//using singly linked list 
#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
	int data; 
	struct Node* head; 
}*top=NULL; 
 

int write()
{
   int num;
   FILE *fptr;
   fptr = fopen("e:\\linknum.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      return;             
   }
   
   
   struct Node *temp;	
 	temp = top; 
	while (temp != NULL)
	 { 
		fprintf(fptr,"%d->", temp->data); 
		temp = temp->head; 
  	}
   fclose(fptr);

}

int read()
{
	int num;
   FILE *fptr;

   if ((fptr = fopen("e:\\linknum.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }

   while(fscanf(fptr,"%d",&num) == 1)
			push(num);
   fclose(fptr); 
}

void push(int data) 
{ 
	struct Node* temp; 
	temp = (struct Node*)malloc(sizeof(struct Node)); 
	if (!temp) { 
		printf("\nHeap Overflow"); 
		exit(1); 
	} 
	temp->data = data; 
	temp->head = top; 
	top = temp; 
} 
int isEmpty() 
{ 
	return top == NULL; 
} 

void pop() 
{ 
	struct Node* temp; 

	 
	if (top == NULL) { 
		printf("\nStack Underflow"); 
		exit(1); 
	} 
	else { 
		
		temp = top; 
		top = top->head; 

		 
		temp->head = NULL; 

		free(temp); 
	} 
} 

void display()  
{ 
	struct Node* temp; 

	if (top == NULL) { 
		printf("\nStack Underflow"); 
		exit(1); 
	} 
	else { 
		temp = top; 
		while (temp != NULL) { 

			printf("%d->", temp->data); 

			temp = temp->head; 
		} 
	} 
} 

 

int main() 
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
            	{
                printf("\t Enter Data : ");
                scanf("%d",&data);
                push(data);
                write();
                break;
            	}
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
    
 

	return 0; 
} 

