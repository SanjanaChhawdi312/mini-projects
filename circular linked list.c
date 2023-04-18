//A2305220739_Sanjana_Lab7.C
/*              BOILER PLATE
Name of the student : Sanjana
Enrollment Number : A2305220739 
Class & Section : 3CSE9-X
Name of the Practical : Singly Linked List
Function Used : createList, display, countNodes, iBeginning, iSpecificLoc, iEnd, dBeginning, dSpecificLoc, dEnd
Structure Used : Nil
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//================================================================================
struct node {
    int data; 
    struct node *next;       
};

struct node *head=NULL;    
//================================================================================
//================================================================================

//******************************************************************************

//function for creating list
int createCList() {
    char ch='y';
    struct node *ptr,*nw;
    while(ch!='n') {
        printf("\n\tEnter data : ");
        nw=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&nw->data);
        nw->next=NULL;
        if(head==NULL) {
            head=nw;
        } 
        else {
            for(ptr=head;ptr->next!=head;ptr=ptr->next);
            {
                ptr->next=nw;
            }
        }
        nw->next=head;
        printf("\n\t\tDo you want to continue adding data : ");
        scanf(" %c",&ch);
    }
}
//******************************************************************************

//function for displaying list
void display() {
    if(head==NULL) {
        printf("\n\t\tList is empty");
    }
    
    else {
        struct node *temp=head;
        printf("\n\tList contains elements : ");
        if(head->next==head)
            printf("==>|%d|%u|==",temp->data,temp->next);
        else {
            printf("==>|%d|%u|--->",temp->data,temp->next);
            temp=temp->next;
            while(temp->next!=head) {
                printf("|%d|%u|--->",temp->data,temp->next);
                temp=temp->next;
            }
            printf("|%d|%u|==",temp->data, temp->next);
        }
    }
}
//******************************************************************************

//function for counting 
void countNodes() {
    struct node *temp;
    int count=1;
    temp=head;
    if(head==NULL) {
        printf("\nList is empty");
    }
    
    else {
        printf("\nList contains elements : ");
        temp=temp->next;
        while(temp!=head) {
        temp=temp->next;
        count++;
        }
    }
    printf("\n\tNumber of nodes in linked list are : %d",count);
}
//******************************************************************************

//functions for insertion
//------------------------------------------------------------------------------
//funtion for insertion at the beginning of list
void iBeginning() {
    struct node *nw,*temp=head;
        nw=(struct node*)malloc(sizeof(struct node));
        printf("\n\tEnter the number to insert : ");
        scanf("%d",&nw->data);
        if(head==NULL) {
            nw->next=head;
            head=nw;
        }
        else  {
        while(temp->next!=head)
            temp=temp->next;
        nw->next=head;
        head=nw;
        temp->next=head;
        }
        printf("\n\t%d is inserted at the beginning of node successfully",nw->data);
}
//------------------------------------------------------------------------------
//function to insert at specific location
void iSpecificLoc() {
    int pos=1, count=0;
    struct node *ptr,*nw;
        nw=(struct node*)malloc(sizeof(struct node));
        nw->next=NULL;
        if(head==NULL) {
            nw->next=head;
            head=nw;
        }
        else {
            printf("\n\tEnter the position to insert in list : ");
            scanf(" %d",&pos);
            for(ptr=head;count!=pos-2;ptr=ptr->next) {
                count++;
                if(ptr->next==head) {
                    printf("\n\t\tNOT FOUND!!");
                    goto label;
                }
            }
            nw->next=ptr->next;
            ptr->next=nw;
        }
        printf("\n\tEnter the number to insert at %d : ", pos);
        scanf(" %d",&nw->data);
        printf("\n\t%d is inserted at %d in node successfully",nw->data,pos);
        label:printf(" ");
}
//------------------------------------------------------------------------------
//function to insert at the end of LIST
void iEnd() {
    struct node *nw,*ptr;
        nw=(struct node*)malloc(sizeof(struct node));
        nw->next=NULL;
        if(head==NULL) {
            head=nw;
            nw->next=head;
        }
        else  {
            for(ptr=head;ptr->next!=head;ptr=ptr->next);
            ptr->next=nw;
            nw->next=head;
        }
        printf("\n\tEnter the number to insert : ");
        scanf("%d",&nw->data);
        printf("\n\t%d is inserted in at the end of node successfully",nw->data);
}
//*****************************************************************************

//functions to delete from LIST
//------------------------------------------------------------------------------
//Functions to delete from beginning
void dBeginning() {
    if(head==NULL) {
        printf("\n\n\t\tLIST IS EMPTY!!!");
    }
    else  {
        struct node *temp1=head,*temp2=head;
        if(temp1->next==head){
            head=NULL;
            free(temp1);
        }
        else {
            for(temp1=head;temp1->next!=head;temp1=temp1->next);
            head=temp2->next;
            temp1->next=head;
            free(temp2);
        }
        printf("\n\tNode from beginning deleted successfully");
    }
}
//------------------------------------------------------------------------------
//function to delete from specific location 
void dSpecificLoc() {
    struct node *temp1, *temp2;
    int pos,count=0;
        if(head==NULL) {
            printf("\n\n\t\tLIST IS EMPTY!!!");
        }
        else  {
        printf("\n\tEnter position to delete : ");
        scanf("%d",&pos);
            for(temp1=head;count!=pos-1;temp1=temp1->next) {
                count++;
                if(temp1->next==head) {
                    printf("\n\t\tNOT FOUND!!");
                    goto label;
                }
                temp2=temp1;
            }
            temp2->next=temp1->next;
            free(temp1);
            printf("\n\tNode from %d deleted successfully",pos);
    }
    label: printf(" ");
}
//------------------------------------------------------------------------------
//function to delete from end
void dEnd() {
    struct node *temp1=head, *temp2;
        if(head==NULL) {
            printf("\n\n\t\tLIST IS EMPTY!!!");
        }
        else  {
        if(temp1->next==head)
            head=NULL;
        else {
            for(temp1=head;temp1->next!=head;temp1=temp1->next)
            temp2=temp1;
        temp2->next=head;
        free(temp1);
        printf("\n\tNode from end deleted successfully");
        }
    }
}
//******************************************************************************
//================================================================================
//================================================================================
void menu()                                                           
{
    char ch='y';
	 int choice1, flag=0;
	 char choice2;

	do
    {
        fflush(stdin);
		printf("\n\n\t\tMENU FOR OPERATIONS ON SINGLY LINKED LIST");
		printf("\n\t1. Creation of a Circular Linked List");
		printf("\n\t2. Display Circular Linked list");
		printf("\n\t3. Count number of nodes in CLL");
		printf("\n\t4. Insert a node in list");
		printf("\n\t5. Delete a node in list");
		printf("\n\t6. Exit");
		printf("\n\n\tEnter your choice(1-4):");
		scanf("%d",&choice1);
        
        fflush(stdin);
		switch(choice1)
		{
			case 1: 
			        if(flag>0)
			        printf("\n\t\tLIST ALREADY CREATED!!!");
			        else {
			        createCList();
    			        printf("\n\n\t\tCircular linked list is created successfully");
    			        flag++;
			        }
				    break;
			case 2:
					display();
					break;
			case 3: 
			        countNodes();
			        break;
			case 4:
			        printf("\n\t\ta.Insert at beginning");
		            printf("\n\t\tb.Insert at specific location");
		            printf("\n\t\tc.Insert at end"); 
		            printf("\n\n\t\tEnter your choice(a-c):");
		            scanf(" %c",&choice2);
		            switch(choice2)
		            {
		                case 'a':
		                            iBeginning();
		                            display();
		                            break;
		                case 'b':
		                            iSpecificLoc();
		                            display();
		                            break;
		                case 'c':
		                            iEnd();
		                            display();
		                            break;
		                default : 
		                printf("\n\n\t\tINVALID CHOICE!!!!");
		            }
			        break;
			case 5:
			        printf("\n\t\ta.Delete from beginning");
		            printf("\n\t\tb.Delete from specific location");
		            printf("\n\t\tc.Delete from end");
		            printf("\n\n\t\tEnter your choice(a-c):");
		            scanf(" %c",&choice2);
		            switch(choice2)
		            {
		                case 'a':
		                            dBeginning();
		                            display();
		                            break;
		                case 'b':
		                            dSpecificLoc();
		                            display();
		                            break;
		                case 'c':
		                            dEnd();
		                            display();
		                            break;
		                default : 
		                printf("\n\n\t\tINVALID CHOICE!!!!");
		            }
			        break;
            case 6: 
                    printf("\nThank you for using Circular Linked List!!!!");
					return;
					break;
			default:
				printf("\n\n\t\tWRONG CHOICE!!!!");
		}
	}while(ch!='n' || ch!='N');

	getch();
}

int main()
{
	menu();                                                             //Calling menu function in main
}
