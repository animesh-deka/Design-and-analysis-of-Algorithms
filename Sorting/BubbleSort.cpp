// C++ program for implementation of Bubble sort
#include<iostream>
#include<chrono> // For recording time
using namespace std;
void swap(int *x, int *y) // Function to swap
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubblesort(int array[],int n) // Function to implement bubble sort
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+ 1])
            {
                swap(&array[j],&array[j+ 1]);
            }
        }
    }
}
void print(int array[],int n) // Function to print sorted array
{
    int i;
    cout<<"Sorted Array is:";
    for(i=0;i<n;i++)
        cout<<array[i]<<",";
}
void insert(int array[],int n) // Function to insert elements in array
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the "<<i+1<<" element:";
        cin>>array[i];
    }
}

// Driver function	
int main()
{
    int n,i;
    cout<<"Enter the size of array:";
    cin>>n;
    int array[n];
    insert(array,n);
    auto start = std::chrono::high_resolution_clock::now();
    bubblesort(array,n);
    print(array,n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>elapsed = finish - start;
    std::cout<<"Elapsed Time: "<<elapsed.count()<<"seconds\n";
    return 0;
}
