//C++ program for implementation of Linear Search
#include<iostream>
#include<chrono>//To record time
using namespace std;
int search(int array[], int n, int x)//Function to implement linear search
{
        int i;
        for (i = 0; i < n; i++)
                if (array[i] == x)
                        return i;
        return -1;
}
void insert(int array[],int n)//Function to insert elements in array
{
        int i;
        for(i=0;i<n;i++)
        {
                cout<<"Enter the "<<i+1<<" element: ";
                cin>>array[i];
        }
}
int main(void)//Driver Function
{
        int n,i,x;
        cout<<"Enter the size of array: ";
        cin>>n;
        int array[n];
        insert(array,n);
        cout<<"Enter the number you want to find in array: ";
        cin>>x;
        auto start = std::chrono::high_resolution_clock::now();
        int result = search(array, n, x);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double>elapsed = finish - start;
        if(result == -1)
                cout<<"Element is not present in array";
        else
                cout<<"Element is present at index " <<result;
        std::cout<<"\nElapsed Time: "<<elapsed.count()<<" seconds\n";
        return 0;
}
