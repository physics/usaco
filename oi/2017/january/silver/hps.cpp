#include <bits/stdc++.h>
#define MX 100001
#define f0r(x,n) for(int x=0;x<n;x++)
#define f0ri(x,n) for(int x=1;x<n;x++)
using namespace std;
void setIO(string s) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
int n, g[3][MX], mx=-1;
char f;
map<char,int> e;
int main() {
  setIO("hps");
  cin>>n>>f;
  e.insert({'H',0});
  e.insert({'P',1});
  e.insert({'S',2});
  g[e[f]][0]=1;
  f0ri(i,n) {
    char m; cin >> m;
    f0r(b,3)
      g[b][i]=g[b][i-1];
    g[e[m]][i]++;
  }
  int win=-1;
  f0r(i,n) {
    int best, best2;
    f0r(t,3) {
      if(g[t][i]>mx) {
        mx=g[t][i];
        best=t;
      }
    }
    mx=-1;
    f0r(t,3) {
      int x=g[t][n-1]-g[t][i];
      if(x>mx) {
        mx=x;
        best2=t;
      }
    }
    mx=-1;
    int lw=g[best][i] + g[best2][n-1]-g[best2][i];
    if(lw>win)
      win=lw;
  }
  cout<<win<<endl;
}
