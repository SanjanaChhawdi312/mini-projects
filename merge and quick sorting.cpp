#include <iostream>

using namespace std;
int n;

//swap function
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

//function to print array
void printArray(int A[]){
    for(int k=0;k<n;k++){
        cout<<A[k]<<"   ";
    }
    cout<<endl<<endl;
}

//Quick sort
int partition(int A[],int start,int end){
    int x=A[end];
    int i=start-1;
    for(int j=start;j<=end-1;j++){
        if(A[j]<x){
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[end]);
    cout<<"\nstart="<<start<<"   end="<<end<<"  pivot="<<i+1<<"\n";
    printArray(A);
    return i+1;
}
void quicksort(int A[],int start,int end){
    if(start<end){
        int pivot=partition(A,start,end);
        quicksort(A,start,pivot-1);
        quicksort(A,pivot+1,end);
    }
}


//Merge Sort
void merge(int A[],int start,int mid,int end){
    int n1=mid-start+1;
    int n2=end-mid;
    int leftA[n1],rightA[n2];
    for(int i=0;i<n1;i++){
        leftA[i]=A[start+i];
    }
    for(int j=0;j<n2;j++){
        rightA[j]=A[mid+j+1];
    }
    int i=0,j=0,k=start;
    while(i<n1&&j<n2){
        if(leftA[i]<=rightA[j]){
            A[k]=leftA[i];
            i++;
        }
        else{
            A[k]=rightA[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k]=leftA[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]=rightA[j];
        j++;
        k++;
    }
    cout<<"\nstart="<<start<<"   end="<<end<<"  mid="<<mid<<"\n";
    printArray(A);
}

void mergesort(int A[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        mergesort(A,start,mid);
        mergesort(A,mid+1,end);
        merge(A,start,mid,end);
    }
}


//Main 
int main()
{
    int start, end, A[20],choice;
    char ch='y';
    do{
        cout<<"\nEnter size of array : ";
        cin>>n;
        start=0,end=n-1;
        cout<<"\nEnter elements of array : \n";
        for(int i=start;i<=end;i++){
            cin>>A[i];
        }
        cout<<"\n\nMenu for sorting=>";
        cout<<"\n1. Merge sort";
        cout<<"\n2. Quick sort";
        cout<<"\nChoose one of the method to sort array (1-2) : ";
        cin>>choice;
        switch(choice){
            case 1:
            mergesort(A, start, end);
            cout<<"\nFinal array is:";
            printArray(A);
            break;
            case 2:
            quicksort(A, start, end);
            cout<<"\nFinal array is:";
            printArray(A);
            break;
            default:
            cout<<"\nError!! Enter one of the two options";
        }   
        cout<<"\nDo you want to continue (y/n) : ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');

    return 0;
}


