//C++ program to implement QuickSort
#include <iostream>
#include<chrono>
using namespace std;
void swap(int* a, int* b)//Function to swap element
{
        int t = *a;
        *a = *b;
        *b = t;
}
int partition (int arr[], int low, int high)//Function to slect last element as pivot elemet and place it accordingly
{
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
                if (arr[j] < pivot)
                {
                        i++;
                        swap(&arr[i], &arr[j]);
                }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
}
void quickSort(int arr[], int low, int high)//Function to implement Quick Sort
{
        if (low < high)
        {
                int pi = partition(arr, low, high);
                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
        }
}
void printArray(int arr[], int size)//Function to print an array
{
        int i;
        for (i = 0; i < size; i++)
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
        quickSort(arr, 0, arr_size - 1);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        cout<<"Sorted array: \n";
        printArray(arr, arr_size);
        std::cout << "Elapsed time: " << elapsed.count() << " s\n";
        return 0;
}
