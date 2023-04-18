//A2305220739_Sanjana_Lab12-14-15.C
/*              BOILER PLATE
Name of the student : Sanjana
Enrollment Number : A2305220739 
Class & Section : 3CSE9-X
Name of the Practical : Binary search tree
Function Used : create, insert, inorder, preorder, postorder, delete, min
Structure Used : node
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left, *right;
};
struct node *root = NULL;

//function for creating new node
struct node *create (int value){
  struct node *temp = (struct node *) malloc (sizeof (struct node));
  temp->data = value;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

//------------------------------------------------------------------------------
//function for inserting values in binary tree
struct node *insert (struct node *node, int value){
  if(node==NULL)
    return create(value);
  if (value<node->data) {
      node->left=insert(node->left,value);
    }
  else if(value>node->data) {
      node->right=insert(node->right,value);
    }
  return node;
}

//------------------------------------------------------------------------------
//function for pre order transversal
void preorder (struct node *binaryTree){
  if(binaryTree!=NULL) {
      printf("%d\t, ", binaryTree->data);
      preorder(binaryTree->left);
      preorder(binaryTree->right);
    }
}

//function for in order transversal
void inorder (struct node *binaryTree) {
  if(binaryTree!=NULL) {
      inorder(binaryTree->left);
      printf("%d\t, ", binaryTree->data);
      inorder(binaryTree->right);
    }
}

//function for post order tranversal 
void postorder(struct node *binaryTree){
  if(binaryTree!=NULL) {
      postorder(binaryTree->left);
      postorder(binaryTree->right);
      printf("%d\t, ",binaryTree->data);
    }
}

//------------------------------------------------------------------------------
//minimum value in binary tree i.e. leftmost node value
struct node *min (struct node *current) {
  while(current->left!=NULL)
    current=current->left;
  return current;
}

//------------------------------------------------------------------------------
//function to delete given node in binary tree
struct node *delete (struct node *root, int data) {
  struct node* parent=NULL;  
  struct node* current=root;  
  if(current==NULL)
    return NULL;
  if(root->data<data)
        root->right=delete(root->right,data);
  else if(root->data>data)
        root->left=delete(root->left,data);
  else {
        //when there is no child i.e leaf node
        if(current->left==NULL&&current->right==NULL) {  
            free(current); 
            return NULL;
        }  
        //when there is one child i.e only right child
        else if(current->left==NULL)  {  
            struct node *temp= current->right;
            free(current);
            return temp;
        }  
        //when there is one child i.e only left child
        else if(current->right==NULL) {
            struct node *temp=current->left;
            free(current);
            return temp;
        }
        //when there are both the children present
        else {
            struct node* rightMin=min(root->right);
            root->data=rightMin->data;
            root->right=delete(root->right,rightMin->data);
        }
    }  
    return current;
}  

/*______________________________________________________________________________
--------------------------------------------------------------------------------
_______________________________________________________________________________*/
void menu () {
  char ch='y';
  int choice1,choice2,val,flag = 0;
  struct node *root = NULL,*temp;
  do {
      fflush (stdin);
      printf ("\n\t\tMENU FOR OPERATIONS ON BINARY SEARCH TREE : ");
      printf ("\n\t1. Creation");
      printf ("\n\t2. Insertion");
      printf ("\n\t3. Delete tree");
      printf ("\n\t4. Display");
      printf ("\n\t5. Exit menu");
      printf ("\n\n\tEnter your choice(1-4) : ");
      scanf ("%d", &choice1);

      switch (choice1) {
	    case 1:
	    if (flag > 0)
	        printf ("\n\tBinary search tree is already created!!!");
	    else {
	        printf ("\n\tBinary search tree created");
	        break;
	   }

	    case 2:
	        printf ("\n\tEnter value to insert : ");
	        scanf ("%d", &val);
	        root=insert (root, val);
	        break;
	    case 3:
    	  printf ("\n\tEnter number to delete : ");
    	  scanf ("%d", &val);
    	  root = delete (root, val);
    	  printf ("\n\t%d deleted", val);
    	  break;
	    case 4:
    	  printf ("\n\tChoose representation type :");
    	  printf ("\n\t\t1. Pre-order form");
    	  printf ("\n\t\t2. In-order form");
    	  printf ("\n\t\t3. Post-order form");
    	  printf ("\n\t\tEnter your choice : ");
    	  scanf ("%d", &choice2);
    	  switch (choice2) {
    	  case 1:
    	      preorder (root);
    	      break;
    	  case 2:
    	      inorder (root);
    	      break;
    	  case 3:
    	      postorder (root);
    	      break;
    	  default:
    	      printf ("\n\t\tWRONG CHOICE!!!");
    	 }
    	  break;

	    case 5:
	        ch = 'n';
        	printf ("\n\t\tExiting from program....");
        	break;
	    default:
	        printf ("\n\t\tWRONG CHOICE!!!");
	    }
    } while (ch == 'y');
  getch ();
}

int main () {
  menu ();
  return 0;
}


