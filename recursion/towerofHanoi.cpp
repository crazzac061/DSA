# include <bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n, char source , char auxuliary, char destination)
{
    if (n==1)
    {
        cout<<"Move disk "<< n <<" from "<<source <<" to "<<destination<<endl;
        return;

    }
    TowerOfHanoi(n-1,source,destination,auxuliary);
    cout<<"Move disk "<< n <<" from "<<source<<" to "<<destination<<endl;
    TowerOfHanoi(n-1,destination,source,auxuliary);
}

int main()
{
    int disk;
    cout<<"enter the number of disks"<<endl;
    cin>>disk;
    TowerOfHanoi(disk,'A','B','C');
    return 0;
}