#include <bits/stdc++.h>
#define pb push_back
#define f0r(x,n) for(int x=0;x<n;x++)
#define f0ri(x,n) for(int x=1;x<n;x++)
using namespace std;
void setIO(string s) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
int n,q,f;
vector<vector<int>> cows;
string ac = "";
int main() {
	setIO("bcount");
	cin>>n>>q>>f;
	if     (f==1) cows.pb ({1,0,0}) ;
	else if(f==2) cows.pb ({0,1,0}) ;
	else if(f==3) cows.pb ({0,0,1}) ;
	ac = to_string(f);
	f0r(i,n-1) {
		int cow; cin >> cow;
		ac += to_string(cow);
	}
	f0ri(i,n){
		int cow = ac[i] - '0' ;
		cows.pb (cows[i-1]) ;
		if (cow==1) cows[i][0] ++ ;
		else if(cow==2) cows[i][1] ++ ;
		else if(cow==3) cows[i][2] ++ ;
	}
	f0r(i,q){
		int a,b,h,g,j;
		cin>>a>>b;
		if(a==b) {
			if(ac[a-1]=='1') cout<<1<<" "<<0<<" "<<0<<"\n";
			else if(ac[a-1]=='2') cout<<0<<" "<<1<<" "<<0<<"\n";
			else if(ac[a-1]=='3') cout<<0<<" "<<0<<" "<<1<<"\n";
		}
		else {
			h=cows[b-1][0]-cows[a-1][0];
			if(ac[a-1]=='1') h++;
			g=cows[b-1][1]-cows[a-1][1];
			if(ac[a-1]=='2') g++;
			j=cows[b-1][2]-cows[a-1][2];
			if(ac[a-1]=='3') j++;
			cout<<h<<" "<<g<<" "<<j<<"\n";
		}
	}
}