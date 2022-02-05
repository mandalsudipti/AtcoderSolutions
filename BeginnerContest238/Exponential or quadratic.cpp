#include<bits/stdc++.h>
using namespace std ;

//2^n > n^2 

int main()
{
    long long int n ;
    cin>>n ;
    
    long long int square = (n*n) ;
    int left_most_bit = (int)(log2(square)) ;
    
    if(left_most_bit < n )
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
        
    return 0 ;
}