//A2305220739_Sanjana_Lab11.C
/*              BOILER PLATE
Name of the student : Sanjana
Enrollment Number : A2305220739 
Class & Section : 3CSE9-X
Name of the Practical : Binary tree
Function Used : create, insert, inorder, preorder, postorder, delete
Structure Used : node
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
struct node *root=NULL;

struct node *create(int value) {
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* insert(struct node* node, int value) {
    if (node == NULL) 
        return create(value);
    if (value<node->data) {
    node->left=insert(node->left,value);
    }
    else if (value>node->data) {
    node->right=insert(node->right,value);
    }
    return node;
}

void preorder(struct node * binaryTree) {
    if (binaryTree!=NULL) {
        printf("%d\n",binaryTree->data);
        preorder(binaryTree->left);
        preorder(binaryTree->right);
    }
}

void inorder(struct node * binaryTree) {
    if (binaryTree!=NULL) {
        inorder(binaryTree->left);
        printf("%d\n",binaryTree->data);
        inorder(binaryTree->right);
    }
}

void postorder(struct node * binaryTree) {
    if (binaryTree!=NULL) {
        postorder(binaryTree->left);
        postorder(binaryTree->right);
        printf("%d\n",binaryTree->data);
    }
}

void delete(struct node * tree)
{
    if(tree) {
        delete(tree->left);
        delete(tree->right);
        free(tree);
    }
}
void menu()                                                           
{
    char ch='y';
	int choice1,choice2,val,flag=0;
    struct node *root=NULL,*temp;
	do
    {
        fflush(stdin);
        printf("\n\t\tMENU FOR OPERATIONS ON BINARY TREE : ");
        printf("\n\t1. Creation");
        printf("\n\t2. Insertion");
        printf("\n\t3. Delete tree");
        printf("\n\t4. Display");
        printf("\n\t5. Exit menu");
        printf("\n\n\tEnter your choice(1-4) : ");
        scanf("%d",&choice1);
        
        switch(choice1) {
            case 1: 
                    if(flag>0)
	                printf ("\n\tBinary tree is already created!!!");
	                else {
                        printf("\n\tBinary tree created");
                        break;
	                }
                    
            case 2: printf("\n\tEnter value to insert : ");
                    scanf("%d",&val);
                    root=insert(root,val);
                    break;
            case 3:
                    delete(root);
                    root=NULL;
                    printf("\n\tTree is deleted.");
                    break;
            case 4:
                    printf("\n\tChoose representation type :");
                    printf("\n\t\t1. Pre-order form");
                    printf("\n\t\t2. In-order form");
                    printf("\n\t\t3. Post-order form");
                    printf("\n\t\tEnter your choice : ");
                    scanf("%d",&choice2);
                    switch(choice2) {
                        case 1:preorder(root); break;
                        case 2:inorder(root); break;
                        case 3:postorder(root); break;
                        default: printf("\n\t\tWRONG CHOICE!!!");
                    }
                    break;
                
            case 5 : ch='n';
                     printf("\n\t\tExiting from program....");
                     break;
            default: printf("\n\t\tWRONG CHOICE!!!");
        }
    }while(ch=='y');

	getch();
}

int main()
{
	menu();                                                       
	return 0;
}


