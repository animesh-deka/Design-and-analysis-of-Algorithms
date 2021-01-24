//C++ program to implement Binary Search with file handling
#include <iostream>
#include<chrono>
#include<fstream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)//Binary search function
{
        fstream searching;
        searching.open("Inputdat_1.txt", ios::in);
        if (r >= l) {
                int mid=l+(r-l)/2;
        if (arr[mid]==x)
                return mid;
        if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
}
void print(int array[],int n)//Function to print array
{
        ifstream searching;
        searching.open("inputdata.txt");
        int i;
        cout<<"Given Array is:";
        for(i=0;i<n;i++)
                cout<<array[i]<<",";
}
int main(void)//Driver function
{
        int n,x,i;
        cout<<"Input the size of array: ";
        cin>>n;
        ofstream searching;
        int array[1200]{};
        searching.open("inputdata.txt");
        if (!searching)
        {
                cout << "Error, File not found!" <<endl;
                exit(1);
        }
        for (i = 0; i < n; i++)
        {
                array[i] = (i*33)/13+i;
                searching << array[i];
        }
        print(array,n);
        cout<<"\nEnter the element you want to search: ";
        cin>>x;
        auto start = std::chrono::high_resolution_clock::now();
        int result = binarySearch(array, 0, n - 1, x);
        if(result==-1)
                cout << "Element is not present in array";
        else
                cout << "Element is present at index " << result;
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "\nElapsed time for binarySearch: " << elapsed.count() << "s\n";
        return 0;
}
