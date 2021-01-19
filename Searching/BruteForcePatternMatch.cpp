//C++ program to implement Brute force string matching
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void search(char* pattern, char* text)//Function to implement brute force string matching
{
        int M = strlen(pattern);
        int N = strlen(text);
        for(int i=0; i<=N-M; i++)
        {
                int j;
                for (j=0; j<M; j++)
                        if (text[i+j]!=pattern[j])
                                break;
                if (j == M)
                        cout<<"Pattern found at index "<<i<<endl;
        }
}
int main()//Driver Function
{
        char text[20],pattern[20];
        cout<<"Enter a text: ";
        cin>>text;
        cout<<"Enter the pattern to search: ";
        cin>>pattern;
        search(pattern,text);
        return 0;
}
