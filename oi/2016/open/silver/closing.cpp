#include <bits/stdc++.h>
#define pb push_back
#define srt(b) sort(b.begin(), b.end())
#define f0r(x,n) for(long long x=0;x<n;x++)
#define unvisit(a,x,i,n) for(int x=i;x<=n;x++) a[x]=false;
using namespace std;
void setIO(string s) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
int n,m,v=0; // v=visited
vector<int> adjList[3001];
bool visited[3001];
bool avoid[3001];
void dfs(int n){
	if(visited[n])
    return;
  else v++;
  visited[n] = true; 
  for(int a:adjList[n]){
    if(!visited[a] && !avoid[a])
      dfs(a);
	}
}
int main() {
	setIO("closing");
	cin>>n>>m;
	if(m<n-1) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	f0r(i,m) {
		int a,b;
		cin>>a>>b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	vector<int> closing(n-1);
	int reserve;
	f0r(i,n-1)
		cin>>closing[i];
	cin>>reserve;
	f0r(i,n-1) {
		avoid[closing[i]]=true;
		dfs(reserve);
		if(v>=n-(i+1))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		v=0;
		unvisit(visited,x,1,n);
	}
}
