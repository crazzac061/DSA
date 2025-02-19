#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr={6,5,7,8,3,9,2};
    int n= arr.size();
    for (int i=0; i<n;i++)
    {
        int min=i;
        for (int j=i+1;j<n;j++)
        {
            if (arr[j]<arr[i])
            {
                min=j;
            }
        }

        swap(arr[i],arr[min]);

    }
    
    for (int i=0 ;i<n; i++)
    {
        cout<<arr[i]<<",";
    }

    return 0;



}