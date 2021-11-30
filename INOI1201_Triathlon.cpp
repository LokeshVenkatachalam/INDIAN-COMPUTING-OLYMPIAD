#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[N];
int b[N];
int c[N];
long long int d[N];
bool compare(int x1,int y1)
{
    return (d[x1]>d[y1]);
}


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
        d[i]=b[i]+c[i];

    }
    sort(a+1,a+n+1,compare);
    sort(d+1,d+n+1);
    long long int ans,sam;
    sam=0;
    ans=sam;
    for(int i=n;i>0;i--)
    {
        sam+=a[i];
        ans=max(ans,(sam+d[i]));
    }
    cout<<ans;
    return 0;


}
