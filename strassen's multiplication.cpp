/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
double A[20][20], B[20][20], C[20][20];

void add(double m[][20],double n[][20], int size,double o[][20]){
    int i,j;       
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            o[i][j] = m[i][j] + n[i][j];   
        }
    }
}

void sub(double m[][20],double n[][20],int size,double o[][20]){
    int i,j;
    for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                        o[i][j]= m[i][j] - n[i][j];
                }
        }
}

void
getMatrix (double mat[][20], int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  cin >> mat[i][j];
	}
    }
}


void
printMatrix (double mat[][20], int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  cout << mat[i][j] << "\t";
	}
      cout << endl;
    }
}

int
divideN (int n)
{
  int subn;
  if (n & n - 1 != 0)
    {
      subn = log (n) / log (2);
    }
  return pow (2, subn + 1);
}

void
multiply (double A[][20], double B[][20], int n, int subn,double C [][20])
{
  if (n == 1)
    {
      C[0][0] = A[0][0] * B[0][0];
    }
  else
    {
        double a11[20][20], a12[20][20], a21[20][20], a22[20][20];
        double b11[20][20], b12[20][20], b21[20][20], b22[20][20];   
        int nsize = n / 2;
      for(int i=0;i<nsize;i++){
            for(int j=0;j<nsize;j++){
                a11[i][j]=A[i][j];
                a12[i][j]=A[i][j+nsize];
                a21[i][j]=A[i+nsize][j];
                a22[i][j]=A[i+nsize][j+nsize];                   
                b11[i][j]=B[i][j];
                b12[i][j]=B[i][j+nsize];
                b21[i][j]=B[i+nsize][j];
                b22[i][j]=B[i+nsize][j+nsize];
            }
        }
      double p[20][20], q[20][20],r[20][20],s[20][20],t[20][20],u[20][20],v[20][20];
      double c11[20][20],c12[20][20],c21[20][20],c22[20][20];
      double tmp1[20][20],tmp2[20][20],tmp3[20][20],tmp4[20][20],tmp5[20][20],tmp6[20][20];
      double tmp7[20][20],tmp8[20][20],tmp9[20][20],tmp10[20][20];
    
      //p
      add(a11,a22,nsize,tmp1);
      add(b11,b22,nsize,tmp2);
      multiply(tmp1,tmp2,nsize,n,p);
      //q
      add(a21,a22,nsize,tmp3);
      multiply(tmp3,b11,nsize,n,q);
      //r
      sub(b12,b22,nsize,tmp4);
      multiply(a11,tmp4,nsize,n,r);
      //s 
      sub(b21,b11,nsize,tmp5);
      multiply(a22,tmp5,nsize,n,s);
      //t 
      add(a11,a12,nsize,tmp6);
      multiply(tmp6,b22,nsize,n,t);
      //u 
      sub(a21,a11,nsize,tmp7);
      add(b11,b12,nsize,tmp8);
      multiply(tmp7,tmp8,nsize,n,u);
      //v 
      sub(a12,a22,nsize,tmp9);
      add(b21,b22,nsize,tmp10);
      multiply(tmp9,tmp10,nsize,n,v);
      
      double t1[20][20],t2[20][20],t3[20][20],t4[20][20];
      //c11
      add(p,v,nsize,t1);
      sub(s,t,nsize,t2);
      add(t1,t2,nsize,c11);
      //c12
      add(r,t,nsize,c12);
      //c21
      add(q,s,nsize,c21);
      //c22
      add(r,u,nsize,t3);
      sub(p,q,nsize,t4);
      add(t3,t4,nsize,c22);
        int a=0;
        int b=0;
        int c=0;   
        int d=0;
        int e=0;
        int nsize2= 2*nsize;
        for(int i=0;i<nsize2;i++){
            for(int j=0;j<nsize2;j++){
                if(j>=0 && j<nsize && i>=0 && i<nsize){
                    C[i][j] = c11[i][j];
                }
                if(j>=nsize && j<nsize2 && i>=0 && i<nsize){
                    a=j-nsize;
                    C[i][j] = c12[i][a];
                }
                if(j>=0 && j<nsize && i>= nsize && i < nsize2){
                    c=i-nsize;
                    C[i][j] = c21[c][j];
                }
                if(j>=nsize && j< nsize2 && i>= nsize && i< nsize2 ){
                    d=i-nsize;
                    e=j-nsize;
                    C[i][j] =c22[d][e];
                }
            }   
        }
    }
}

int
main ()
{
  int n;
  cout << "\nEnter size of both the matrix : ";
  cin >> n;
  cout << "\nEnter first matrix=>\n";
  getMatrix (A, n);
  cout << "\nEnter second matrix=>\n";
  getMatrix (B, n);
  int subn = divideN (n);
  multiply (A, B, n, subn,C);
  cout << "\nA=\n";
  printMatrix (A, n);
  cout << "\nB=\n";
  printMatrix (B, n);
  cout<<"\nMatrix multiplication using Strassen's method is=>\n";
  printMatrix(C,n);

  return 0;
}