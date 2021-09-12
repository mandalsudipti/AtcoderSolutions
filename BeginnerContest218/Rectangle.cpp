#include<bits/stdc++.h>
using namespace std ;

bool sortbyY(const pair<long long int,long long int>& A , const pair<long long int,long long int>& B)
{
    return A.second < B.second ;
}

int main()
{
    int n ;
    cin>>n;
    
    vector<pair<long long int,long long int>>points ;
    vector<vector<long long int>>diff_y ;
    int x , y ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin>>x>>y;
        points.push_back(make_pair(x,y));
    }
    
    sort(points.begin() , points.end() , sortbyY);
    
    for(int i = 0 ; i < n ; i++)
    {
        if(diff_y.size() == 0 || points[i].second != points[i-1].second)
        {
            vector<long long int>tmp = {points[i].first} ;
            diff_y.push_back(tmp) ;
        }
        else
            diff_y[diff_y.size() - 1].push_back(points[i].first) ;
    }
    
    for(int i = 0 ; i < diff_y.size() ; i++)
        sort(diff_y[i].begin() , diff_y[i].end());
        
    long long int ans = 0 ;
    for(int i = 0 ; i < diff_y.size() ; i++)
    {
        for(int j = i+1 ; j < diff_y.size() ; j++)
        {
            int idx1 = 0 , idx2 = 0 ;
            long long int cnt = 0;
            while(idx1 < diff_y[i].size() && idx2 < diff_y[j].size())
            {
                if(diff_y[i][idx1] == diff_y[j][idx2])
                {
                    cnt++ ;
                    idx2++; 
                    idx1++;
                }
                else if(diff_y[i][idx1] < diff_y[j][idx2])
                    idx1++;
                else
                    idx2++;
            }
            ans+=((cnt * (cnt - 1))/2);
        }
    }
    
    cout<<ans;
    
    return 0 ;
}