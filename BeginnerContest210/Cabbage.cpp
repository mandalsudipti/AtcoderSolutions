#include<bits/stdc++.h>
using namespace std ;

int main()
{
    long long int N , A , X , Y ;
    cin>>N>>A>>X>>Y ;
    
    long long int cost = X * min(A,N) ;
    if(N > A)
    {
        cost+=(Y * (N - A)) ;
    }
    
    cout<<cost<<endl;
    return 0 ;
}