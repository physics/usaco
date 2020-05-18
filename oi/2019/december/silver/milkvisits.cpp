#include <bits/stdc++.h>
#define pb push_back
#define f0r(x,n) for(int x=0;x<n;x++)
#define f0ri(x,n) for(int x=1;x<n;x++)
using namespace std;
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
int n,m,cmpcnt=1;
vector<int> adj[100001];
int comp[100001];
string cows;
void dfs(int node){
  if(comp[node])
  	return;
  comp[node]=cmpcnt;
  for(int a:adj[node])
    if(cows[a-1]==cows[node-1])
  	  dfs(a);
}
int main() {
  setIO("milkvisits");
  cin>>n>>m>>cows;
  f0r(i,n-1) {
    int x,y;
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  f0ri(i,n+1) {
    if(comp[i]==0)
      dfs(i);
    cmpcnt++;
  }
  f0r(i,m) {
    int a,b;
    char hg;
    cin>>a>>b>>hg;
    if(comp[a]!=comp[b]||cows[a-1]==hg||cows[b-1]==hg)
      cout<<1;
    else
      cout<<0;
  }
}