#include <bits/stdc++.h>
#define pb push_back
#define f0r(x,n) for(int x=0;x<n;x++)
#define f0ri(x,n) for(int x=1;x<n;x++)
#define trav(x, n) for(auto x : n)
#define travc(x, n) for(auto const&x : n)
#define MX 100001
using namespace std;
void setIO(string s) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
int n, hw[MX], ps[MX], mn[MX], mx, crm=MX;
double avg;
set<int> best;
// hw=homework, ps=prefix sums, mn=minimum, mx=maximum, crm=current minimum
int main() {
	setIO("homework");
	cin>>n;
	f0r(i,n) cin >> hw[i];
	ps[0]=hw[0];
	f0ri(i,n) ps[i]=ps[i-1]+hw[i];
	for(int i=n-1;i>=0;i--) {
		if(hw[i] < crm) crm=hw[i];
		mn[i] = crm;
	}
	f0ri(i,n-1) {
		double a = (ps[n-1]-ps[i-1]-mn[i])/(1.0*n-i-1);
		if(a>avg) avg=a;
	}
	f0ri(i,n-1) {
		double a = (ps[n-1]-ps[i-1]-mn[i])/(1.0*n-i-1);
		if(a==avg) best.insert(i);
	}
	travc(average,best) cout<<average<<endl;
}