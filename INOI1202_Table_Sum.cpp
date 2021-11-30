#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[N];
int dp1[N];
int dp2[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp1[1]=a[1]+1;
    for(int i=2;i<=n;i++)
    {
        dp1[i]=max(dp1[i-1],(a[i]+i));
    }
   dp2[n]=a[n]+n;
   for(int i=(n-1);i>0;i--)
   {
       dp2[i]=max(dp2[i+1],(a[i]+i));
   }
   int ans=0;
   cout<<dp1[n]<<' ';
   for(int i=(n-1);i>=1;i--)
   {
       ans=max((dp1[i]+n-i),(dp2[i+1]-i));
       cout<<ans<<' ';
   }
    return 0;
}
