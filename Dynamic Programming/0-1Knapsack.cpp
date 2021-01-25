//C++ program to implement 0/1 Knapsack dynamically
#include <iostream>
using namespace std;
//Function to return the max number
int max(int a, int b)
{
        return (a > b) ? a : b;
}
//Function to implement 0/1 Knapsack
int knapSack(int W, int wt[], int val[], int n)
{
        int i, w;
        int K[n + 1][W + 1];
        for (i = 0; i <= n; i++)
        {
                for (w = 0; w <= W; w++)
                {
                        if (i == 0 || w == 0)
                                K[i][w] = 0;
                        else if (wt[i - 1] <= w)
                                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                        else
                                K[i][w] = K[i - 1][w];
                }
        }
        return K[n][W];
}
//Driver Code
int main()
{
        int W, n;
        cout<<"Enter the total number of input: ";
        cin>>n;
        int wt[n], val[n];
        cout<<"Enter the weight of Knapsack: ";
        cin>>W;
        cout<<"Enter the Respective Weight and Profit"<<endl;
        for(int i=0;i<n;i++)
        {
                cout<<"--------------------------------------------------------------------"<<endl;
                cout<<"Enter weight of "<<i+1<<" item: ";
                cin>>wt[i];
                cout<<"Enter Profit of "<<i+1<<" item: ";
                cin>>val[i];
        }
        cout<<"--------------------------------------------------------------------"<<endl;
        cout <<"Max value attained: "<<knapSack(W, wt, val, n)<<endl;
        return 0;
}
