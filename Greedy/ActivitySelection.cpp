//C++ program to implement Activity Selection Problem
#include<iostream>
using namespace std;
//Function to select maximum number of activites
void selectMaxActivities(int start[], int finish[], int n)
{
        int i=0, j;
        cout<<("Following activities are selected :");
        cout<<i+1<<" "; //First Activity is always selected
        for(j=1; j<n; j++)
        {
                if(start[j]>=finish[i])
                {
                        cout<<j+1<<" ";
                        i=j;
                }
        }
       cout<<endl;
}
//Driver Code
int main()
{
        int n, i;
        cout<<"Enter the total number of activities: ";
        cin>>n;
        int start[n], finish[n];
        for(i=0; i<n; i++)
        {
                cout<<"-----------------------------------------------------------------"<<endl;
                cout<<"Enter the start time of "<<i+1<<" activity: ";
                cin>>start[i];
                cout<<"Enter the finish time of "<<i+1<<" activity: ";
                cin>>finish[i];
        }
        cout<<"-----------------------------------------------------------------"<<endl;
        selectMaxActivities(start, finish, n);
        return 0;
}
