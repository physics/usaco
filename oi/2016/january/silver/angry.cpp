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
ll n,k,g; // n,k, as well as g (g means global maximum amt. needed)
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
  setIO("angry"); // set up i/o
  cin>>n>>k; // read in n and k
  f0r(i,n) { // add all haybales to the vector of haybales (hbs)
    ll hb;
    cin>>hb;
    hbs.pb(hb);
  } srt(hbs); // sort the vector of haybales so you can binary search
  vector<vll> s(k);
  ll ms=(hbs[0]+hbs[n-1])/k; //midpoints
  f0r(i,n)
  	s[hbs[i]/(ms+1)].pb(hbs[i]);
  //f0r(i,k) {
  //	for(ll x : s[i]) cout<<x<<" ";
  //	cout<<"\n";
	//}
	f0r(i,k) {
		//cout<<"hullo1"<<"\n";
		ll sz=s[i].size();
		//cout<<"hullo2"<<"\n";
		ll mpt=(ll)ceil((s[i][0]+s[i][sz-1])*1.0/2);
		//cout<<"hullo3"<<"\n";
		ll left=mpt-s[i][0];
		//cout<<"hullo4"<<"\n";
		ll right=s[i][sz-1]-mpt;
		//cout<<"hullo5"<<"\n";
		g=max(g,max(left,right));
		//cout<<"hullo6"<<"\n";
	}
	cout<<g<<"\n";
}
