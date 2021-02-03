//C++ program to implement Starrsen Matrix Multiplication
#include<iostream>
using namespace std;
//Function to print a given array
void print(int C[2][2])
{
    int i,j;
    cout<<"Printing the product of matrix A and B\n";
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}
//Function to implement Starrsen Matrix Multiplication
void starrsen(int A[2][2], int B[2][2])
{
    int C[2][2],p1,p2,p3,p4,p5,p6,p7;
    p1=A[0][0]*(B[0][1]-B[1][1]);
    p2=(A[0][0]+A[0][1])*B[1][1];
    p3=(A[1][0]+A[1][1])*B[0][0];
    p4=A[1][1]*(B[1][0]-B[0][0]);
    p5=(A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
    p6=(A[0][1]-A[1][1])*(B[1][0]+B[1][1]);
    p7=(A[0][0]-A[1][0])*(B[0][0]+B[0][1]);
    C[0][0]=p5+p4-p2+p6;
    C[0][1]=p1+p2;
    C[1][0]=p3+p4;
    C[1][1]=p1+p5-p3-p7;
    print(C);
}
//Driver Code
int main()
{
    int A[2][2],B[2][2],i,j;
    cout<<"Enter the elements of matrix A\n";
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"Enter the elements of matrix B\n";
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            cin>>B[i][j];
        }
    }
    starrsen(A,B);
    return 0;
}
