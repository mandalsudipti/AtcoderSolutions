#include<bits/stdc++.h>
using namespace std ;

bool sortfunc(const pair<string,string>& A , const pair<string,string>& B)
{
    if(A.first == B.first)
        return A.second < B.second ;
    else
        return A.first < B.first ;
}

int main()
{
    int n ;
    cin>>n ;
    
    vector<pair<string,string>>arr(n) ;
    
    for(int i = 0 ; i < n ; i++)
    {
        string S , T ;
        cin>>S>>T ;
        arr[i] = make_pair(S,T) ;
    }
    
    sort(arr.begin() , arr.end() , sortfunc) ;
    
    bool flag = false ;
    
    for(int i = 0 ; i < n-1 ; i++)
    {
        if(arr[i].first == arr[i+1].first && arr[i].second == arr[i+1].second)
        {
            flag = true ;
            break;
        }
    }
    
    if(flag)
        cout<<"Yes";
    else
        cout<<"No" ;
        
    return 0 ;
}