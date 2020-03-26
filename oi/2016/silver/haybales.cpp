#include <bits/stdc++.h>
#define pb push_back
#define vll vector<long long>
#define srt(b) sort(b.begin(), b.end())
#define f0r(x,n) for(long long x=0;x<n;x++)
using namespace std;
typedef long long ll;
void setIO(string s) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
vll hbs; // vector of all haybales
ll n,q; // n and q
ll fge(ll l, ll r, ll x) { // first element greater than or equal to
  ll z=-1;
  while(l<=r){
    int m=l+(r-l)/2;
    if(hbs[m]==x)
      return m;
    if(hbs[m]<x) {
      l=m+1;
    }
    else {
    	z=m;
      r=m-1;
    }
  }
  return z;
}
ll lle(ll l,ll r,ll x) { // last element less than or equal to
  ll z=-1;
  while(l<=r){
    int m=l+(r-l)/2;
    if(hbs[m]==x)
      return m;
    if(hbs[m]<x) {
      z=m;
      l=m+1;
    }
    else
      r=m-1;
  }
  return z;
}
int main() {
  setIO("haybales"); // set up i/o
  cin>>n>>q; // read in n and q
  f0r(i,n) { // add all haybales to the vector of haybales (hbs)
    ll hb;
    cin>>hb;
    hbs.pb(hb);
  } srt(hbs); // sort the vector of haybales so you can binary search
  f0r(z,q) {
    ll a,b,ia,ib,c=0; // a, b, and index of A, index of B
    cin>>a>>b; // read in a,b
    ia=fge(0,n-1,a); // index of A is first element >= A
    ib=lle(0,n-1,b); // index of B is last element <= B
    if(ia==-1) // if A is greater than hbs[n-1] then it'd be -1, if it's before it'd be 0
      c=0;
    else if(ib==-1) // if all elements are greater than B, answer is 0
      c=0;
    else
    	c=ib-ia+1;
    cout<<c<<"\n";
  }
}
