#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int n , k ,a ;
    cin>>n>>k>>a ;
    
    if(a == 1)
    {
        if(k % n == 0)
            cout<<n<<endl;
        else
            cout<<(k % n)<<endl;
    }
    else
    {
        int last_pos = ( k%n == 0 ? n : (k % n)) ;
        //cout<<last_pos<<endl;
        a-- ;
        if(last_pos + a <= n)
            cout<<(last_pos + a)<<endl;
        else
            cout<<(last_pos + a)%n<<endl;
    }
    return 0 ;
}