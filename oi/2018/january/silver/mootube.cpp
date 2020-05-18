#include <bits/stdc++.h>
#define pb push_back
#define f0r(x,n) for(int x=0;x<n;x++)
#define f0ri(x,n) for(int x=1;x<n;x++)
#define unvisit(a,x,i,n) for(int x=i;x<=n;x++) a[x]=false;
#define mp make_pair
using namespace std;
void setIO(string s) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
typedef std::pair<int,int> pairy;
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pairy) const
    {
        return std::hash<T1>()(pairy.first) ^ std::hash<T2>()(pairy.second);
    }
};
unordered_map<pairy,int,pair_hash> r; // relevance
int n,q,K,vi; // vi = visited counter
vector<int> adj[5001];
bool visited[5001];
void dfs(int n){
  if(visited[n])
      return;
  vi++;
  visited[n] = true; 
  for(int a:adj[n]){
      if(!visited[a]&&r[{n,a}]>=K)
        dfs(a);
  }
}
int main() {
  setIO("mootube");
  cin>>n>>q;
  f0r(i,n-1) {
    int p,q,rl;
    cin>>p>>q>>rl;
    adj[p].pb(q);
    adj[q].pb(p);
    r.insert(mp(mp(p,q),rl));
    r.insert(mp(mp(q,p),rl));
  }
  f0r(i,q) {
    int k,v;
    cin>>k>>v;
    K=k;
    dfs(v);
    cout<<vi-1<<endl;
    vi=0;
    unvisit(visited,x,1,n);
  }
}
