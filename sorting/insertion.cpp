#include<bits/stdc++.h>
using namespace std;

int main ()
{
    vector<int> arr={33,54,23,31,87,64};
    int n= arr.size();
    for (int i=0; i<n; i++)
    {

        for (int j=i;j>0;j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }


        }
    }
    for (int i; i<n;i++)
    {
        cout<<arr[i]<<',';
    }
    return 0;
}