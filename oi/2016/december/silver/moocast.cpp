#include <bits/stdc++.h>
#define pb push_back
#define f0r(x,n) for(long long x=0;x<n;x++)
#define unvisit(a,x,i,n) for(int x=i;x<=n;x++) a[x]=false;
using namespace std;
typedef long long ll;
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
int n, maxVisited=1;
bool visited[201];
vector<int> adjList[201];
void dfs(int n){
	if(visited[n])
  	return;
  visited[n] = true;
  for(int a:adjList[n]){
    if(!visited[a])
      dfs(a);
	}
}
int main() {
  setIO("moocast");
  cin>>n;
  vector<tuple<int,int,int>> cows;
  f0r(i,n) {
  	int x,y,p;
  	cin>>x>>y>>p;
  	cows.pb(make_tuple(x,y,p));
	}
	f0r(i,n) {
		int origX, origY, capability;
		origX = get<0>(cows[i]);
		origY = get<1>(cows[i]);
		capability = get<2>(cows[i]);
		f0r(j,n) {
			if(i==j) continue;
			int reachX, reachY;
			reachX = get<0>(cows[j]);
			reachY = get<1>(cows[j]);
			double distance = sqrt(((origX-reachX)*(origX-reachX))+((origY-reachY)*(origY-reachY)));
			if(abs(distance)<=capability)
				adjList[i+1].pb(j+1);
		}
	}
	for(int i=1;i<=n;i++) {
		dfs(i);
		int v = 0;
		for(int i=1;i<=n;i++)
			if(visited[i])
				v++;
		maxVisited=max(maxVisited,v);
		unvisit(visited,x,1,n);
	} 
	cout<<maxVisited<<endl;
}
