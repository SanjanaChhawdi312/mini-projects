/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
//Bubble Sort
void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=n;j>=i+1;j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
        if(i==n-1){
            cout<<"\n\n\nSorted array : ";
        }
        else{
            cout<<"\nIteration "<<i<<" : ";
        }
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" , ";
        }
    }
}
//insertion Sort
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&key<=arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        if(i==n-1){
            cout<<"\n\n\nSorted array : ";
        }
        else{
            cout<<"\nIteration "<<i<<" : ";
        }
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" , ";
        }
    }
}
//Selection sort
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        if(i==n-2){
            cout<<endl<<"\n\n\nSorted array : ";
        }
        else{
            cout<<endl<<"\nIteration "<<i+1<<" : ";
        }
        for(int k=0;k<n;k++){
            cout<<arr[k]<<", ";
        }
    }
}

int main()
{
    int choice,arr[45],n;
    char ch='y';
    do{
        cout<<"\nEnter size limit : ";
        cin>>n;
        //input array elements
        cout<<"\nEnter array elements : "<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"\n\t\tSort using :";
        cout<<"\n\t1. Bubble sort";
        cout<<"\n\t2. Insertion sort";
        cout<<"\n\t3. Selection sort";
        cout<<"\nEnter your choice (1-3) : ";
        cin>>choice;
        switch(choice){
            case 1 : 
            bubbleSort(arr,n);
            break;
            case 2 : 
            insertionSort(arr,n);
            break;
            case 3 :
            selectionSort(arr,n);
            break;
            default:
            cout<<"\n\nInvalid choice!! Enter between 1 and 3";
        }
        cout<<"\nDo you want to continue in menu (y/n) : ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');

    return 0;
}


