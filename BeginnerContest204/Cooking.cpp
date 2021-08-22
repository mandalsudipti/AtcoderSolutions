#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int sum = 0 ;
    vector<int>arr(n);
    
    for(int i = 0; i < n ; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    
    vector<vector<bool>>get_sum(n , vector<bool>(sum+1,false));
    get_sum[0][arr[0]] = true ;
    
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <= sum ; j++)
        {
            if(arr[i] == j)
                get_sum[i][j] = true ;
                
            else if(get_sum[i-1][j] == true)
                get_sum[i][j] = true ;
                
            else if((j - arr[i]) > 0 && (get_sum[i-1][j - arr[i]] == true))
                get_sum[i][j] = true ;
        }
    }
    
    int min_time = sum ;
    
    for(int j = 1 ; j <= sum ; j++)
    {
        if(get_sum[n-1][j] == true)
        {
            min_time = min(min_time , max(j , sum - j));
        }
    }
    
    cout<<min_time<<endl;
    return 0 ;
}
