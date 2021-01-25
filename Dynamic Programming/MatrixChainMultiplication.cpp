// C++ program using memoization 
#include <bits/stdc++.h> 
using namespace std; 
int dp[100][100]; 
// Function for matrix chain multiplication 
int matrixChainMemoised(int* p, int i, int j) 
{ 
	if (i == j) 
	{ 
		return 0; 
	} 
	if (dp[i][j] != -1) 
	{ 
		return dp[i][j]; 
	} 
	dp[i][j] = INT_MAX; 
	for (int k = i; k < j; k++) 
	{ 
		dp[i][j] = min( 
			dp[i][j], matrixChainMemoised(p, i, k) 
					+ matrixChainMemoised(p, k + 1, j) 
					+ p[i - 1] * p[k] * p[j]); 
	} 
	return dp[i][j]; 
} 
int MatrixChainOrder(int* p, int n) 
{ 
	int i = 1, j = n - 1; 
	return matrixChainMemoised(p, i, j); 
} 
// Driver Code 
int main() 
{ 
    int n, i;
    cout<<"Enter the total number of inputs: ";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter the value of dimension of matrix "<<i+1<<" :";
        cin>>arr[i];
    }
    memset(dp, -1, sizeof dp); 

	cout << "Minimum number of multiplications is "<< MatrixChainOrder(arr, n); 
}
