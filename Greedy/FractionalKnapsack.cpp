//C++ program to implement Fractional Knapsack Problem
#include<iostream>
#include<algorithm>
using namespace std; 
//Structure for an item which stores weight of the respective item 
struct Item 
{ 
	int profit, weight;
}arr[10];

bool cmp(struct Item a, struct Item b) 
{ 
	double r1 = (double)a.profit / (double)a.weight; 
	double r2 = (double)b.profit / (double)b.weight; 
	return r1 > r2; 
} 
//Function to implement fractional knapsack 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{
	sort(arr, arr + n, cmp); 
	int curWeight = 0; 
	double finalvalue = 0.0; 
	for (int i = 0; i < n; i++) 
	{ 
		if (curWeight + arr[i].weight <= W)
		{ 
			curWeight += arr[i].weight; 
			finalvalue += arr[i].profit; 
		} 
		else
		{ 
			int remain = W - curWeight; 
			finalvalue+= arr[i].profit*((double)remain/(double)arr[i].weight); 
			break; 
		} 
	} 
	return finalvalue; 
}  
// Driver code 
int main() 
{ 
  int W,n;
  Item arr[10];
  cout<<"Enter the total number of input: ";
  cin>>n;
  cout<<"Enter the weight of Knapsack: ";       
  cin>>W;
  cout<<"Enter the Respective Weight and Profit"<<endl;
  for(int i=0;i<n;i++)
  {	
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"Enter weight of "<<i+1<<" item: ";
    cin>>arr[i].weight;
    cout<<"Enter Profit of "<<i+1<<" item: ";
    cin>>arr[i].profit;
  }
  cout<<"--------------------------------------------------------------------"<<endl;  
  cout <<"Max value attained: "<<fractionalKnapsack(W, arr,n)<<endl; 
  return 0; 
}
