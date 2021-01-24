//C++ code to implement count sort
#include <iostream>
using namespace std;
//Function to implement count sort
void countSort(int array[], int n) 
{
    int output[10], count[10];
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) 
    {
        count[array[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < n; i++) 
    {
        array[i] = output[i];
    }
}
//Function to print an array
void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}
//Driver Code
int main() 
{
    int n, i;
    cout<<"Enter the number of elements to be sorted: ";
    cin>>n;
    int array[n];
    for(i=0;i<n;i++)
    {
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Enter the "<<i+1<<" element: ";
        cin>>array[i];
    }
    cout<<"------------------------------------------------------------------"<<endl;
    countSort(array, n);
    printArray(array, n);
}
