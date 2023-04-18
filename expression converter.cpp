//A2305220739_Sanjana_Lab5.C
/*              BOILER PLATE
Name of the student : Sanjana
Enrollment Number : A2305220739 
Class & Section : 3CSE9-X
Name of the Practical : Infix to postfix, postfix to infix, 
Function Used : push, pop, isFull, isEmpty, postfix, infix
Structure Used : Nil
*/

#include <iostream>
#include<conio.h>
#include <string.h>

using namespace std;
#define max 15//declaring and defining stack and top
  	int top=-1;          
    char sStack[max];
    
//isEmpty function   
  int isEmpty ()		
  {
    if (top==-1)
      return 1;
    else
      return 0;
  }
  
//isFull dunction
  int isFull ()			
  {
    if (top==max-1)
      return 1;
    else
      return 0;
  }

//pop function  
  char pop()			
  {
    char temp;
    if (isEmpty ())
	temp = ' ';
    else
    {
	temp = sStack[top];
	--top;
    }
    return temp;
  }

//push function
  void push(char val)		
  {
    if (isFull())
	cout<<"\n\tStack is full";
    
    else
    {
	++top;
	sStack[top] = val;
    }
  }
 
char expr[50];
void input()
{
    cout<<"Enter infix expression : ";
    cin>>expr;
}
void Postfix()
{
    int choice1, size1, size2;
    char postfix1[50];
    
    size1=strlen(expr);
    //loop for putting converting into postfix using stack
    for(int i1=0, i2=0;i1<=size1;i1++,i2++) 
    {
        if(((expr[i1]>=65)&&(expr[i1]<=90))||((expr[i1]>=97)&&(expr[i1]<=122)))
        postfix1[i2]=expr[i1];
        
        else if(expr[i1]==']'||expr[i1]==')')
        {
            int temp=top;
            while((sStack[temp]!='['||sStack[temp]!='(')&&temp>0)
            {
                if(sStack[top]!='(')
            {
                postfix1[i2]=sStack[top];
                i2++;  
                pop();
                temp--;
            }
            else
            break;
            }
            pop();
            i2--;
        }
        
        else if((sStack[top]=='*'||sStack[top]=='/')&&(expr[i1]=='+'||expr[i1]=='-'))
        { 
            char temp3= sStack[top];
            pop();
            push(expr[i1]);
            postfix1[i2]=temp3;
        }
        
        else
        {
         push(expr[i1]);
         i2--;
        }
    }
    
    size2=strlen(postfix1);
    //loop for for pushing remaining operators of previous string    
    for(int k=size2,i=0;k<=size2+strlen(sStack);k++,i++)
    {
        if(sStack[top-i]==')')
        i++;
        postfix1[k]=sStack[top-i];
    }
    
    //loop for printing final string
    cout<<"\nPostfix expression is :";
    for(int l=0;l<=size2+strlen(sStack);l++)
    {
        cout<<postfix1[l];
    }
}

void prefix()
{
    int choice1, size3,size4;
    char postfix2[50], str[50], prefix[50];
    
    size3=strlen(expr);
    //reversing string
    for(int i=0;i<=size3;i++) 
    {
        if(expr[size3-i]=='(')
            expr[size3-i]=')';
        else if(expr[size3-i]==')')
            expr[size3-i]='(';
        str[i]=expr[size3-i];
    }
    cout<<"\nStep 1: Reversed string including brackets : ";
    
    //for displaying reversed loop
    for(int loopDis=0;loopDis<=size3;loopDis++)
    {
        cout<<str[loopDis];
    }
    
    //loop for putting converting into reversed string into postfix
    for(int i1=0, i2=0;i1<=size3;i1++,i2++) 
    {
        if(((str[i1]>=65)&&(str[i1]<=90))||((str[i1]>=97)&&(str[i1]<=122)))
        postfix2[i2]=str[i1];
        
        else if(str[i1]==']'||str[i1]==')')
        {
            int temp=top;
            while((sStack[temp]!='['||sStack[temp]!='(')&&temp>0)
            {
                if(sStack[top]!='(')
            {
                postfix2[i2]=sStack[top];
                i2++;  
                pop();
                temp--;
            }
            else
            break;
            }
            pop();
            i2--;
        }
        
        else if((sStack[top]=='*'||sStack[top]=='/')&&(str[i1]=='+'||str[i1]=='-'))
        { 
            char temp3= sStack[top];
            pop();
            push(str[i1]);
            postfix2[i2]=temp3;
        }
        
        else
        {
         push(str[i1]);
         i2--;
        }
    }
    
    size4=strlen(postfix2);
    //loop for for pushing remaining operators of previous string    
    for(int k=size4,i=0;k<=size4+strlen(sStack);k++,i++)
    {
        if(sStack[top-i]==')')
        i++;
        postfix2[k]=sStack[top-i];
    }
    
    //loop for printing final string
    cout<<"\nStep 2: Postfix expression of reversed string in step 1 is : ";
    for(int l=0;l<=size4+strlen(sStack);l++)
    {
        cout<<postfix2[l];
    }
    
    //loop for again reversing 2nd step to obtain final expression
    cout<<"\nStep 3: Again reverse step 2\nFinal expression is : ";
    for(int m=0;m<=size4+strlen(sStack);m++)
    {
        prefix[m]=postfix2[size4+strlen(sStack)-m];
        cout<<prefix[m];
    }
}
void menu()                                                             //menu function body starts
{
	int choice1, s, Array1[max];
	char ch;                                                       //variable declarations

	do
    {

		cout<<"\n\n\t\tMENU FOR OPERATIONS ON ARRAY";
		cout<<"\n\t1. Insert an infix expression";
		cout<<"\n\t2. Convert infix to postfix";
		cout<<"\n\t3. Convert infix to prefix";
		cout<<"\n\t4. Evaluate the postfix expression for a given infix expression ";
		cout<<"\n\t5. Exit";
		cout<<"\n\n\tEnter your choice(1-5):";
		cin>>choice1;
		switch(choice1)
		{
			case 1:
                    input();
					break;
			case 2:
					Postfix();
					break;
			case 3: 
			        prefix();
			        break;
            case 5: 
                    printf("\nThank you for using menu!!!!");
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







