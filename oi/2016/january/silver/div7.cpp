#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define f0r(x,n) for(ll x=0;x<n;x++)
#define f0ri(x,n) for(ll x=1;x<n;x++)
#define trav(x, n) for(auto x : n)
#define travc(x, n) for(auto const&x : n)
#define MX 50001
using namespace std;
void setIO(string s) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
ll n, id[MX], ps[MX], re[MX], mx=0;
vector<ll> lo(7);
// ids, psums, remainders, lo=last occurrence
int main() {
	setIO("div7");
  fill(lo.begin(),lo.end(),-1);
	cin>>n;
  f0r(i, n) cin >> id[i];
  ps[0]=id[0];
  f0ri(i,n) ps[i]=ps[i-1]+id[i];
  f0r(i,n) re[i]=ps[i]%7;
  f0r(i,n) lo[re[i]]=i;
  f0r(i,n) mx = max (mx, lo[re[i]] - i);
  cout<<mx<<endl;
}