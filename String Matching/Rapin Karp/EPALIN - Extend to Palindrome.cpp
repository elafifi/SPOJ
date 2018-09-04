/**
* Author   : Ahmed Elafifi
* Date     : 4/9/2018
* category : Rapin-Karp
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
ll fixMod(ll a,ll m)
{
    return (a%m + m)%m;
}

///55 ==> 551
///55*10 + 1 ==> 551
void add_L_Digit(ll& h, ll d, ll b, ll m)
{
    h = ((h*b)%m + d)%m;
}
///15 + 7*100 == 715
void add_M_Digit(ll& h, ll d, ll p, ll m)
{
    h = (h + (d*p)%m)%m;
}
ll fPow(ll b,ll p,ll m) {
    if(!p) return 1;
    if(p&1) return b*fPow((b*b)%m,p>>1,m)%m;
    return fPow((b*b)%m,p>>1,m)%m;
}
ll h1,h2,Base = 129,sz;
int main() {
    string s,req;
    while(cin>>s)
    {
        sz = 0;
        h1 = 0,h2 = 0;
        req = "";
        for(int i = s.size()-1;i>=0;i--) {
        add_L_Digit(h1,s[i],Base,MOD);
        add_M_Digit(h2,s[i],fPow(Base,s.size()-i-1,MOD),MOD);
        if(h1 == h2)
        {
            sz = i;
        }
    }
    req = s.substr(0,sz);
    reverse(req.begin(),req.end());
    cout<<s<<req<<endl;
    }

}
