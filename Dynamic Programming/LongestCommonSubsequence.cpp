// Dynamic Programming C++ implementation of LCS problem
#include<iostream> 
using namespace std; 
// Utility function to get max of 2 integers
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 
int lcs( char *X, char *Y, int m, int n ) 
{ 
	int L[m + 1][n + 1]; 
	int i, j; 
	for (i = 0; i <= m; i++) 
	{ 
		for (j = 0; j <= n; j++) 
		{ 
		if (i == 0 || j == 0) 
			L[i][j] = 0; 
	
		else if (X[i - 1] == Y[j - 1]) 
			L[i][j] = L[i - 1][j - 1] + 1; 
	
		else
			L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
		} 
	} 
	return L[m][n]; 
} 
// Driver Code 
int main() 
{ 
    int m,n,i;
    cout<<"Enter the length of first string: ";
    cin>>n;
    cout<<"Enter the length of second string: ";
    cin>>m;
	char X[m], Y[n];
	cout<<"Enter the first string:"<<endl;
    for(i=0;i<n;i++)
        cin>>X[i];
	cout<<"Enter the second string:"<<endl;
    for(i=0;i<m;i++)
        cin>>Y[i];        
	
	cout << "Length of LCS is "
		<< lcs( X, Y, m, n ); 
	
	return 0; 
}
