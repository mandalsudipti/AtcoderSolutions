#include<bits/stdc++.h>
using namespace std ;

long double get_area(vector<long long int>& A , vector<long long int>& B , vector<long long int>& C)
{
    return (B[0] - A[0])*(C[1] - A[1]) - (C[0] - A[0])*(B[1] - A[1]) ;
}

int main()
{
    int n ;
    cin>>n ;
    
    vector<vector<long long int>>vertices(n , vector<long long int>(2)) ;
    for(int i = 0 ; i < n ; i++)
        cin>>vertices[i][0]>>vertices[i][1] ;
    
    int count = 0 ;    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            for(int k = j+1 ; k < n ; k++)
            {
                if(get_area(vertices[i] , vertices[j] , vertices[k]) != 0)
                    count++ ;
            }
        }
    }
    
    cout<<count<<endl;
    
    return 0 ;
}