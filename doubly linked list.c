//A2305220739_Sanjana_Lab8.C
/*              BOILER PLATE
Name of the student : Sanjana
Enrollment Number : A2305220739 
Class & Section : 3CSE9-X
Name of the Practical : Doubly Linked List
Function Used : createDList, disBeginning, disEnd, countNodes, 
iBeginning, iSpecificLoc, iEnd, dBeginning, dEnd, dSpecificLoc, menu
Structure Used : Nil
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    struct node *pre;
    int data; 
    struct node *next;       
};

struct node *head=NULL;    

void createDList() {
    char ch='y';
    struct node *ptr,*nw;
    while(ch!='n') {
        printf("\n\tEnter data : ");
        //adding node value and setting its next to null
        nw=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&nw->data);
        nw->pre=NULL;
        nw->next=NULL;
        if(head==NULL) {
            head=nw;
        } 
        else {
            //transversing throught nodes with loop
            for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
            {
                //node is added at last
                ptr->next=nw;
                nw->pre=ptr;
            }
        }
        printf("\n\t\tDo you want to continue adding data : ");
        scanf(" %c",&ch);
    }
}

void disBeginning() {
    struct node *temp;
    temp=head;
    if(head==NULL) {
        printf("\n\t\tList is empty");
    }
    
    else {
        if(temp->next==NULL) {
            printf("\n\tList contains elements : ");
            printf(">--|NULL|%d|NULL|-->",temp->data);
        }
        else {
            printf("\n\tList contains elements : ");
            printf(">--|NULL|%d|%u|<==>",temp->data,temp->next);
            temp=temp->next;
            while(temp->next!=NULL) {
                printf("|%u|%d|%u|<==>",temp->pre,temp->data,temp->next);
                temp=temp->next;
            }
            printf("|%u|%d|NULL|-->",temp->pre,temp->data);
        }
    }
}

void disEnd() {
    struct node *temp;
    temp=head;
    if(head==NULL) {
        printf("\n\t\tList is empty");
    }
    
    else {
        if(temp->next==NULL) {
            printf("\n\tList elements in reverse order : ");
            printf("<--|NULL|%d|NULL|--<",temp->data);
        }
        else {
            printf("\n\tList elements in reverse order : ");
            while(temp->next!=NULL) {
                temp=temp->next;
                
            }
            //end node reached
            //transversing in reverse order
            printf("<--|%u|%d|NULL|<==>",temp->pre,temp->data);
            temp=temp->pre;
            while(temp!=head) {
                printf("|%u|%d|%u|<==>",temp->pre,temp->data,temp->next);
                temp=temp->pre;
            }
            printf("|NULL|%d|%u|--<",temp->data,temp->next);
        }
    }
}

void countNodes() {
    struct node *temp;
    int count=0;
    temp=head;
    if(head==NULL) {
        printf("\nList is empty");
    }
    
    else {
        printf("\nList contains elements : ");
        while(temp!=NULL) {
        temp=temp->next;
        count++;
        }
    }
    printf("\n\tNumber of nodes in linked list are : %d",count);
}

//functions for insertion
//funtion for insertion at the beginning of DLL
void iBeginning() {
    struct node *nw;
        nw=(struct node*)malloc(sizeof(struct node));
        nw->pre=NULL;
        if(head==NULL) {
            nw->next=NULL;
            head=nw;
        }
        else  {
            nw->next=head;
            head->pre=nw;
            head=nw;
        }
        printf("\n\tEnter the number to insert at the beginning : ");
        scanf("%d",&nw->data);
        printf("\n\t%d is inserted at beginning in node",nw->data);
}

//function to insert at specific location in DLL
void iSpecificLoc() {
    int pos=1, count=0;
    struct node *ptr,*nw;
        nw=(struct node*)malloc(sizeof(struct node));
        nw->pre=NULL;
        nw->next=NULL;
        if(head==NULL) {
            head=nw;
        }
        else {
            printf("\n\tEnter the position to insert in list : ");
            scanf(" %d",&pos);
            for(ptr=head;count<pos-2;ptr=ptr->next) {
                count++;
                if(ptr->next==NULL) {
                    printf("\n\t\tNOT FOUND!!");
                    goto label;
                }
            }
            ptr->next->pre=nw;
            nw->next=ptr->next;
            nw->pre=ptr;
            ptr->next=nw;
        }
        printf("\n\tEnter the number to insert at %d : ", pos);
        scanf(" %d",&nw->data);
        printf("\n\t%d is inserted in node",nw->data);
        label:printf(" ");
}

//function to insert at the end of LIST
void iEnd() {
    struct node *nw,*ptr;
        nw=(struct node*)malloc(sizeof(struct node));
        nw->next=NULL;
        if(head==NULL) {
            nw->pre=head;
            head=nw;
        }
        else  {
            for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
            ptr->next=nw;
            nw->pre=ptr;
        }
        printf("\n\tEnter the number to insert : ");
        scanf("%d",&nw->data);
        printf("\n\t%d is inserted in node",nw->data);
}

//functions to delete from LIST
//Functions to delete from beginning in DLL
void dBeginning() {
    struct node *temp=head;
    if(head==NULL) {
        printf("\n\n\t\tLIST IS EMPTY!!!");
    }
    else  {
        if(head->next==NULL)
            head=NULL;
        else {
            head=temp->next;
            temp->pre=NULL;
        }
        free(temp);
        printf("\n\tNode from beginning deleted");
    }
}

//function to delete from specific location in DLL
void dSpecificLoc() {
    struct node *temp=head;
    int pos,count=0;
        if(head==NULL) {
            printf("\n\n\t\tLIST IS EMPTY!!!");
        }
        else  {
        printf("\n\tEnter position to delete : ");
        scanf("%d",&pos);
            for(temp=head;count<pos-1;temp=temp->next) {
                count++;
                if(temp->next==NULL) {
                    printf("\n\t\tNOT FOUND!!");
                    goto label;
                }
            }
            temp->pre->next=temp->next;
            temp->next->pre=temp->pre;
            free(temp);
            printf("\n\tNode from %d deleted",pos);
    }
    label: printf(" ");
}

//function to delete from end
void dEnd() {
    struct node *temp=head;
        if(head==NULL) {
            printf("\n\n\t\tLIST IS EMPTY!!!");
        }
        else  {
        if(temp->next==NULL&&temp->pre==NULL)
            head=NULL;
        else {
            for(temp=head;temp->next!=NULL;temp=temp->next);
        temp->pre->next=NULL;
        }
        free(temp);
        printf("\n\tNode from end deleted");
    }
}

void menu()                                                           
{
    char ch='y';
	 int choice1, flag=0;
	 char choice2;

	do
    {
        fflush(stdin);
		printf("\n\n\t\tMENU FOR OPERATIONS ON SINGLY LINKED LIST");
		printf("\n\t1. Creation of a Doubly Linked List");
		printf("\n\t2. Display Linked list");
		printf("\n\t3. Count number of nodes in DLL");
		printf("\n\t4. Insertion in DLL");
		printf("\n\t5. Deletion in DLL");
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
			        createDList();
    			        printf("\n\n\t\tSingly linked list is created successfully");
    			        flag++;
			        }
				    break;
			case 2:
					printf("\n\t\ta.Display from beginning");
		            printf("\n\t\tb.Display from end"); 
		            printf("\n\n\t\tEnter your choice(a-b):");
		            scanf(" %c",&choice2);
		            switch(choice2) {
		                case 'a':
		                            disBeginning();
		                            break;
		                case 'b':
		                            disEnd();
		                            break;
		                default :
		                            printf("\n\n\t\tINVALID CHOICE!!!!");
		            }
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
		                            break;
		                case 'b':
		                            iSpecificLoc();
		                            break;
		                case 'c':
		                            iEnd();
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
		                            break;
		                case 'b':
		                            dSpecificLoc();
		                            break;
		                case 'c':
		                            dEnd();
		                            break;
		                default : 
		                printf("\n\n\t\tINVALID CHOICE!!!!");
		            }
			        break;
            case 6: 
                    printf("\nThank you for using Doubly Linked List!!!!");
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









