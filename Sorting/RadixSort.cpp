//C++ program to implement Radix sort
#include <iostream>
using namespace std;

//Function to find the max number in an array
int getMax(int arr[], int n)
{
        int mx = arr[0];
        for (int i = 1; i < n; i++)
                if (arr[i] > mx)
                        mx = arr[i];
        return mx;
}

//Function to implement Count sort
void countSort(int arr[], int n, int exp)
{
        int output[n];
        int i, count[10] = { 0 };
        for (i = 0; i < n; i++)
                count[(arr[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
                count[i] += count[i - 1];
        for (i = n - 1; i >= 0; i--)
        {
                output[count[(arr[i] / exp) % 10] - 1] = arr[i];
                count[(arr[i] / exp) % 10]--;
        }
        for (i = 0; i < n; i++)
                arr[i] = output[i];
}

//Function to implement Radix sort
void radixsort(int arr[], int n)
{
        int m = getMax(arr, n);
        for (int exp = 1; m / exp > 0; exp *= 10)
                countSort(arr, n, exp);
}

//Function to print an array
void print(int arr[], int n)
{
        cout<<"Sorted Array is: "<<endl;
        for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
        cout<<endl;
}
//Driver code
int main()
{
        int n, i;
        cout<<"Enter the number of elements to be sorted: ";
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        {
                cout<<"------------------------------------------------------------------"<<endl;
                cout<<"Enter the "<<i+1<<" element: ";
                cin>>arr[i];
        }
        cout<<"------------------------------------------------------------------"<<endl;
        radixsort(arr, n);
        print(arr, n);
        return 0;
}
