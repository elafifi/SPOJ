/**
* Author  : Ahmed Elafifi
* Date    : 10/9/2018
* Category: Rapin Karp
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

ll fixMod(ll a,ll m)
{
    return (a%m + m)%m;
}
//12*10+5 = 125
void add_L_Digit(ll& h,ll d,ll b,ll m)
{
    h = ((h*b)%m + d)%m;
}
//25 + 1*100 = 125
void add_M_Digit(ll& h,ll d,ll p,ll m)
{
    h = (h+ (d*p)%m)%m;
}
//(125 - 5)/10 =
void rem_L_Digit(ll& h,ll d,ll inv,ll m)
{
    h = (fixMod(h-d,m)*inv)%m;
}
///125 - 1*100 = 25
void rem_M_Digit(ll& h, ll d,ll p,ll m)
{
    h = fixMod(h-(d*p)%m,m);
}

//a*x + b*y = g
ll eGCD(ll a,ll b,ll& x,ll& y)
{
    if(!b)
    {
        x = 1,y = 0;
        return a;
    }
    ll g = eGCD(b,a%b,y,x);
    //x = prev_y
    //y = prev_x - ( a/b )*cur_x
    y -= (a/b)*x;
    return g;
}
////a*x = -b*y+g
bool modInv(ll a,ll m,ll& inv)
{
    ll t;
    ll g = eGCD(a,m,inv,t);
    return g == 1;
}
ll fPow(ll a,ll p,ll m)
{
    if(!p)return 1;
    if(p&1)return (a*fPow((a*a)%m,p>>1ll,m))%m;
    return fPow((a*a)%m,p>>1ll,m)%m;
}
set<pair<ll,ll>>st;
ll t,n,k,h1,h2,base = 129;
int main()
{
    cin>>t;
    while(t--)
    {
        h1 = 0,h2 = 0;
        cin>>n>>k;
        string s;
        cin>>s;
        ll p = fPow(base,k-1,MOD);
        ll p2 = fPow(base,k-1,MOD+2);
        for(int i = 0;i<k;i++)
        {
            add_L_Digit(h1,s[i],base,MOD);
            add_L_Digit(h2,s[i],base,MOD+2);
        }
        st.insert({h1,h2});
        for(int i = 0;i<s.size()-k;i++)
        {
            cout<<h1<<" "<<h2<<endl;
            rem_M_Digit(h1,s[i],p,MOD);
            add_L_Digit(h1,s[i+k],base,MOD);

            rem_M_Digit(h2,s[i],p2,MOD+2);
            add_L_Digit(h2,s[i+k],base,MOD+2);
            st.insert({h1,h2});
        }
        cout<<h1<<" "<<h2<<endl;
        cout<<st.size()<<endl;
        st.clear();
    }
    return 0;
}
