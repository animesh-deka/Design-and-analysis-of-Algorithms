//C++ Program to implement Merge sort
#include <iostream>
#include <fstream>
#include<chrono>
using namespace std;
void Merge(int arr[], int l, int m, int r)//Function to merge the sorted array
{
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];
        for (i = 0; i < n1; i++)
                L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
                R[j] = arr[m + 1 + j];
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
                if (L[i] <= R[j])
                {
                        arr[k] = L[i];                                                                                                                                                                                                     i++;
                }
                else
                {
                        arr[k] = R[j];
                        j++;
                }
                k++;
        }
        while (i < n1)
        {
                arr[k] = L[i];
                i++;
                k++;
        }
        while (j < n2)
        {
                arr[k] = R[j];
                j++;
                k++;
        }
}
void MergeSort(int arr[], int l, int r)//Function to implement merge sort
{
        fstream merging;
        merging.open("InputData.txt", ios::in);
        if (l < r)
        {
                int m = l + (r - l) / 2;
                MergeSort(arr, l, m);
                MergeSort(arr, m + 1, r);
                Merge(arr, l, m, r);
        }
}
void print(int A[], int size)//Function to print array
{
        int i;
        for (i = 0; i < size; i++)
                cout<<" "<<A[i];
}
int main()//Driver Function
{
        int arr_size;
        cout << "Input the size of array: ";
        cin >> arr_size;
        ofstream merging;
        int array[1200]{};                                                                                      int i;                                                                                                  merging.open("InputData.txt");
        if (!merging)
        {
                cout << "Error, File not found!" << endl;
                exit(1);
        }
        for (i = 0; i <arr_size; i++)
        {
                array[i] = (rand() % 1000) + 1;
                merging << array[i];
        }
        merging.close();
        cout<<"Array given is:";
        print(array, arr_size);
        auto start = std::chrono::high_resolution_clock::now();
        MergeSort(array, 0, arr_size - 1);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        cout<<"\nSorted array:";
        print(array, arr_size);
        std::cout << "\nElapsed time: " << elapsed.count() << " s\n";
        return 0;
}
