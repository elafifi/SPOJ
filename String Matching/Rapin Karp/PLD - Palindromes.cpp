/**
* Author   : Ahmed Elafifi
* Date     : 9/9/2018
* category : Rapin-Karp
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;

//23456 add L and Rem Most
//54321 add Most and Rem Least
ll fixMode(ll a,ll m)
{
    return (a%m + m)%m;
}
//a*x + b*y = g
ll eGCD(ll a, ll b, ll& x, ll& y) {

    if(!b)
    {
        x = 1,y = 0;
        return a;
    }
    ll g = eGCD(b, a%b, y, x);
    // cur_y = prev_x - (a/b)*cur_x
    // x = prev_y
     y -= (a/b)*x;
    return g;
}
bool modInv(ll a, ll m, ll& inv)
{
    ll t;
    ll g = eGCD(a,m,inv,t);
    inv = fixMode(inv,m);
    return g == 1;
}
//12*10 + 3 = 123
void add_L_Digit(ll& h,ll d, ll b, ll m)
{
    h = ( (h * b)%m + d)%m;
}

//23+1*100 = 123
void add_M_Digit(ll& h, ll d, ll p,ll m)
{
    h = (h + (d*p)%m)%m;
}
///(123 - d)/b
void rem_L_Digit(ll& h, ll d, ll inv, ll m)
{
    h = ((h-d)*inv)%m;
}
///123 - 1*100 = 23
void rem_M_Digit(ll& h, ll d, ll p, ll m)
{
    h = fixMode(h-(d*p)%m,m);
}
ll fPow(ll a,ll p,ll m)
{
    if(!p)return 1;
    if(p&1) return (a*fPow((a*a)%m,p>>1,m))%m;
    return fPow((a*a)%m,p>>1,m)%m;
}

ll k,base = 129,h1,h2,ans,h3,h4,h5,h6;
int main()
{
    cin>>k;
    string s;
    cin>>s;
    if(k == 1){
        cout << s.size();
        return 0;
    }
    int sz = s.size();
    if(k>sz)return 0*puts("0");
    for(int i = 0;i<k;i++)
    {
        add_L_Digit(h1,s[i],base,MOD);
        add_M_Digit(h2,s[i],fPow(base,i,MOD),MOD);
    }
    
    if(h1 == h2 && h3 == h4 && h5 == h6)ans++;
    ll p = fPow(base,k-1,MOD);

    ll inv = 0;
    modInv(base,MOD,inv);

    for(int i = 0;i<sz-k+1;i++)
    {
        rem_M_Digit(h1,s[i],p,MOD);
        add_L_Digit(h1,s[i+k],base,MOD);
        rem_L_Digit(h2,s[i],inv,MOD);
        add_M_Digit(h2,s[i+k],p,MOD);

        if(h1 == h2)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}

