#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int sum = 0 , val ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin>>val ;
        if(val > 10)
            sum+=(val-10);
    }
    cout<<sum<<endl;
    return 0 ;
}