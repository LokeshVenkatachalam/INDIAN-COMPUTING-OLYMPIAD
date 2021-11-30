#include<bits/stdc++.h>
using namespace std;
int main();
vector<int>v;
int dp[1000008];
//inoi  priodic string  success
void fact(int c)
{
    for(int y=1;(y*y)<=c;y++)
    {
        if((c%y)==0)
        {    if(y!=(c/y))
            {
                v.push_back(y);
                v.push_back((c/y));
            }
            else
            {
                v.push_back(y);
            }

        }
    }
}
void in(int d,int g)
{    dp[1]=2;
    for(int i=2;i<=d;i++)
    {
        dp[i]=(dp[i-1]*2)%g;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    fact(n);
    sort(v.begin(),v.end());
    in(n,m);


        for(int i=1;i<(v.size()-1);i++)
        {
            for(int j=0;j<i;j++)
            {
              if(v[i]%v[j]==0)
              {
                  dp[v[i]]=(dp[v[i]]-dp[v[j]]+m)%m;
              }

            }
        }
        int ans;

        ans=dp[n];
       for(int i=0;i<(v.size()-1);i++)
       {
           ans=(ans-dp[v[i]]+m)%m;

       }
       cout<<ans;
       return 0;

}
