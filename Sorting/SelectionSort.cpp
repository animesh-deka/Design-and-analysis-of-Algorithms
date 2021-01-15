// C++ program for implementation of Selection sort
#include<iostream>
#include<chrono>//For recording time
using namespace std;
void swap(int *x, int *y)// Function to swap
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionsort(int array[],int n)// Function to Selection sort
{  
    int i, j, min;
    for (i = 0; i < n-1; i++)  
    {  
        min = i;  
        for (j = i+1; j < n; j++)
            if (array[j] < array[min])  
                min = j;   
        swap(&array[min], &array[i]);  
    }
}  
void print(int array[],int n)// Function to print sorted array
{
    int i;
    cout<<"Sorted Array is:";
    for(i=0;i<n;i++)
        cout<<array[i]<<",";
}
void insert(int array[],int n)// Function to insert elements in array
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the "<<i+1<<" element:";
        cin>>array[i];
    }
}
int main()
{
    int n,i;
    cout<<"Enter the size of array:";
    cin>>n;
    int array[n];
    auto start = std::chrono::high_resolution_clock::now();
    selectionsort(array,n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double>elapsed = finish - start;
    print(array,n);
    std::cout<<"Elapsed Time: "<<elapsed.count()<<"seconds\n";
    return 0;
}
