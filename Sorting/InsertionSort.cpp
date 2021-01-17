//C++ program for insertion sort
#include <iostream>
#include<chrono>
using namespace std;
void insertionSort(int arr[], int n)//Function to implement insertion sort
{
        int i, key, j;
        for (i = 1; i < n; i++)
        {
                key = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > key)
                {
                        arr[j + 1] = arr[j];
                        j = j - 1;
                }
                arr[j + 1] = key;
        }
}
void printArray(int arr[], int n)//Function to print array
{
        int i;
        for (i = 0; i < n; i++)
                cout << arr[i] << " ";
        cout << endl;
}
int main()//Driver code
{
        int arr[1200],arr_size,i;
        cout << "Input the size of array: ";
        cin >> arr_size;
        for (i = 0; i <arr_size; i++)
                arr[i] = (rand() % 1000) + 1;
        cout<<"Array given is: \n";
        printArray(arr, arr_size);
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(arr,arr_size);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        cout<<"\nSorted array: \n";
        printArray(arr, arr_size);
        std::cout << "Elapsed time: " << elapsed.count() << " s\n";
        return 0;
}
