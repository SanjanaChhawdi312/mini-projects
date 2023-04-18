//A2305220739_Sanjana_Lab10.C
/*              BOILER PLATE
Name of the student : Sanjana
Enrollment Number : A2305220739 
Class & Section : 3CSE9-X
Name of the Practical : Stack, queue and addition of 2 polynomials using Singly Linked List
Function Used : push, pop, dispStack
Structure Used : Nil
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//______________________________________________________________________________
//******************************stack node**************************************
struct node1 {
    int data; 
    struct node1 *next;       
};

struct node1 *top=NULL;    

//**********push operation in stack
void push() {
    char ch='y';
    while(ch=='y'){
        struct node1 *nw;
        nw=(struct node1*)malloc(sizeof(struct node1));
        printf("\n\t\tEnter the value to push in stack : ");
        scanf("%d",&nw->data);
        if(top==NULL) {
            nw->next=NULL;
        }
        else {
            nw->next=top;
        }
        top=nw;
        printf("\n\t\t%d succesfully inserted in stack",top->data);
        printf("\n\t\t\tDo you want to continue adding value into stack : ");
        scanf(" %c",&ch);
    };
}

//*************pop operation in stack
void pop() {
    char ch='y';
    while(ch=='y'){
        if(top==NULL) {
            printf("\n\t\tSTACK IS EMPTY!!!");
        }
        else {
        struct node1 *temp=top;
        top=temp->next;
        printf("\n\t\t%d succesfully deleted from stack",temp->data);
        free(temp);
        }
        printf("\n\t\t\tDo you want to continue deleting value into stack : ");
        scanf(" %c",&ch);
    }
}

//*************display operation in stack
void dispStack(){
    if(top==NULL)
        printf("\n\t\tStack is empty");
    else {
        struct node1 *temp;
        printf("\n\t\tStack contains :\n");
        printf("\n\t\t-------------------");
        for(temp=top;temp->next!=NULL;temp=temp->next) {
            if(temp==top) {
                printf("\n\t\t||%d|%u||",temp->data,temp->next);
                printf("<---top");
            }
            else
                printf("\n\t\t||%d|%u||",temp->data,temp->next);
            printf("\n\t\t-------------------");
        }
        printf("\n\t\t||%d|NULL||",temp->data);
        printf("\n\t\t-------------------");
    }
}
//______________________________________________________________________________
//******************************queue node*************************************
struct node2 {
    int data; 
    struct node2 *next;       
};
struct node2 *front=NULL, *rear=NULL;

//**********enqueue operation in queue
void enqueue() {
    char ch='y';
    while(ch=='y'){
        struct node2 *nw;
        nw=(struct node2*)malloc(sizeof(struct node2));
        nw->next=NULL;
        printf("\n\t\tEnter the value to insert in queue : ");
        scanf("%d",&nw->data);
        if(front==NULL) {
            front=nw;
        }
        else {
            rear->next=nw;
        }
        rear=nw;
        printf("\n\t\t%d succesfully inserted in queue",front->data);
        printf("\n\t\t\tDo you want to continue adding value into queue : ");
        scanf(" %c",&ch);
    };
}

//**********dequeue operation in queue
void dequeue() {
    char ch='y';
    while(ch=='y'){
        if(front==NULL) {
            printf("\n\t\tQUEUE IS EMPTY!!!");
        }
        else {
        struct node1 *temp=front;
        front=temp->next;
        printf("\n\t\t%d succesfully deleted from queue",temp->data);
        free(temp);
        }
        printf("\n\t\t\tDo you want to continue deleting value into queue : ");
        scanf(" %c",&ch);
    }
}

//*************display operation in queue
void dispQ(){
    if(front==NULL)
        printf("\n\t\tQueue is empty");
    else {
        struct node1 *temp;
        printf("\n\t\tQueue contains :\n");
        for(temp=front;temp->next!=NULL;temp=temp->next) {
            if(temp==front) {
                printf("\n\t\tfront->");
            }
            printf("||%d|%u||-->",temp->data,temp->next);
        }
        
        printf("||%d|NULL||<--rear",temp->data);
    }
}

//______________________________________________________________________________
//******************************Polynomial**************************************
struct node3 {
    int coeff;
    int power;
    struct node3 *next;       
};
struct node3 *poly1=NULL, *poly2=NULL, *poly3=NULL;

//*************Function for creating polynomials 
void createPoly(struct node3 *temp1) {
    char ch='y';
    do {
        printf("\n\tEnter coefficient :");
        scanf("%d",&temp1->coeff);
        printf("\n\tEnter power : ");
        scanf("%d",&temp1->power);
        temp1->next=(struct node3*)malloc(sizeof(struct node3));
        temp1=temp1->next;
        temp1->next=NULL;
        printf("\n\t\t\tDo you want to continue adding polynomials in equation : ");
        scanf(" %c",&ch);
    }while(ch=='y');
}

//*************Function for displaying polynomials 
void displayPoly(struct node3 *temp2) {
    printf("\t\t");
    while(temp2->next!=NULL) {
        printf("  %dX^%d ",temp2->coeff,temp2->power);
        temp2=temp2->next;
        if(temp2->next!=NULL) {
            printf("+");
        }
    }
}

//*************Function for adding both the polynomials 
void addPoly(struct node3 *temp1,struct node3 *temp2,struct node3 *temp3) {
    while(temp1->next&&temp2->next)
     {
      if(temp1->power>temp2->power)
      {
       temp3->power=temp1->power;
       temp3->coeff=temp1->coeff;
       temp1=temp1->next;
       }
      else if(temp1->power<temp2->power)
      {
       temp3->power=temp2->power;
       temp3->coeff=temp2->coeff;
       temp2=temp2->next;
       }
      else
      {
       temp3->power=temp1->power;
       temp3->coeff=temp1->coeff+temp2->coeff;
       temp1=temp1->next;
       temp2=temp2->next;
       }
      temp3->next=(struct node3 *)malloc(sizeof(struct node3));
      temp3=temp3->next;
      temp3->next=NULL;
     }
     while(temp1->next||temp2->next) {
      if(temp1->next)
      {
       temp3->power=temp1->power;
       temp3->coeff=temp1->coeff;
       temp1=temp1->next;
       }
      if(temp2->next)
      {
       temp3->power=temp2->power;
       temp3->coeff=temp2->coeff;
       temp2=temp2->next;
       }
       temp3->next=(struct node3 *)malloc(sizeof(struct node3));
       temp3=temp3->next;
       temp3->next=NULL;
    }
}

/*______________________________________________________________________________
________________________________________________________________________________*/
void menu()                                                           
{
    char ch='y', ch2='y';
	 int choice1, flag=0;
	 poly1=(struct node3 *)malloc(sizeof(struct node3));
	 poly2=(struct node3 *)malloc(sizeof(struct node3));
	 poly3=(struct node3 *)malloc(sizeof(struct node3));
	 char choice2;

	do
    {
        fflush(stdin);
        printf("\n\t\tMENU FOR PROGRAMS : ");
        printf("\n\tProgram 1 : Stack using single linked list");
        printf("\n\tProgram 2 : Queue using single linked list");
        printf("\n\tProgram 3 : Adding two polynomial using single linked list");
        printf("\n\tExit menu");
        printf("\n\n\tEnter your choice(1-4) : ");
        scanf("%d",&choice1);
        
        switch(choice1) {
            case 1:
                    ch2='y';
                    while(ch2=='y') {
                        printf("\n\t\t\tOperations to perform in stack : ");
                        printf("\n\t\ta. Push in stack");
                        printf("\n\t\tb. Pop from stack");
                        printf("\n\t\tc. Display stack ");
                        printf("\n\n\t\tEnter your choice(a-c) : ");
                        scanf(" %c",&choice2);
                        switch(choice2){
                            case 'a': push();
                                      break;
                            case 'b': pop();
                                      break;
                            case 'c': dispStack();
                                      break;
                            default : printf("\n\tWRONG CHOICE!!");
                        }
                        printf("\n\t\tDo you want to continue in stack program(y/n) : ");
                        scanf(" %c",&ch2);
                    }
                    break;
            case 2:
                    ch2='y';
                    while(ch2=='y') {
                        printf("\n\t\t\tOperations to perform in queue : ");
                        printf("\n\t\ta. Add value in queue");
                        printf("\n\t\tb. Delete from queue");
                        printf("\n\t\tc. Display queue ");
                        printf("\n\n\t\tEnter your choice(a-c) : ");
                        scanf(" %c",&choice2);
                        switch(choice2){
                            case 'a': enqueue();
                                      break;
                            case 'b': dequeue();
                                      break;
                            case 'c': dispQ();
                                      break;
                            default : printf("\n\tWRONG CHOICE!!");
                        }
                        printf("\n\t\tDo you want to continue in queue program(y/n) : ");
                        scanf(" %c",&ch2);
                    }
                    break;
            case 3:
                    ch2='y';
                    while(ch2=='y') {
                    printf("\n\t\t\tOperations to perform in polynomial: ");
                    printf("\n\t\ta. Enter first polynomial ");
                    printf("\n\t\tb. Enter second polynomial");
                    printf("\n\t\tc. Display first polynomial");
                    printf("\n\t\td. Display second polynomial");
                    printf("\n\t\te. Add both polynomials");
                    printf("\n\t\tf. Display the sum of both polynomials ");
                    printf("\n\n\t\tEnter your choice(a-c) : ");
                    scanf(" %c",&choice2);
                    switch(choice2){
                        case 'a': printf("\n\t\tEnter values for first polynomial=>\n");
                                  createPoly(poly1);
                                  break;
                        case 'b': printf("\n\t\tEnter values for second polynomial=>\n");
                                  createPoly(poly2);
                                  break;
                        case 'c': printf("\n\t\tFirst polynomial contains=>\n");
                                  displayPoly(poly1);
                                  break;
                        case 'd': printf("\n\t\tSecond polynomial contains=>\n");
                                  displayPoly(poly2);
                                  break;
                        case 'e': printf("\n\t\t----Polynomials are added----\n");
                                  addPoly(poly1,poly2,poly3);
                                  break;
                        case 'f': printf("\n\t\tFinal polynomial contains=>\n");
                                  displayPoly(poly3);
                                  break;
                        default : printf("\n\tWRONG CHOICE!!");
                    }
                        printf("\n\t\tDo you want to continue in polynomial program(y/n) : ");
                        scanf(" %c",&ch2);
                    }
                    break;
            case 4 : ch='n';
                     printf("\n\t\tExiting from progrma....");
                     break;
            default: printf("\n\t\tWRONG CHOICE!!!");
        }
    }while(ch=='y');

	getch();
}

int main()
{
	menu();                                                             //Calling menu function in main
	return 0;
}
