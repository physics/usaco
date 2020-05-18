#include <bits/stdc++.h>
#define pb push_back
#define f0r(x,n) for(int x=0;x<n;x++)
#define f0ri(x,n) for(int x=1;x<n;x++)
#define mp(x,y) make_pair(x,y)
#define MX 102
#define ppii pair<pair<int,int>,pair<int,int>>
#define f first
#define s second
using namespace std;

void setIO(string s) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int n,k,r;
set<ppii> roads;
vector<pair<int,int>> cows;
bool visited[MX][MX];
set<ppii> d; // distant

vector<pair<int, int>> neighbours (int x, int y) {
  vector<pair<int,int>> nbrs;
  if(x+1<=n) nbrs.pb(mp(x+1,y)); // Right
  if(x-1>=1) nbrs.pb(mp(x-1,y)); // Left
  if(y+1<=n) nbrs.pb(mp(x,y+1)); // Up
  if(y-1>=1) nbrs.pb(mp(x,y-1)); // Down
  return nbrs;
}

void dfs(int x, int y){
  if(visited[x][y])
  	return;
  visited[x][y] = true;
  for(pair<int,int> a:neighbours(x,y)){
    ppii path = {{x,y},{a.f,a.s}};
    ppii reversePath = {{a.f,a.s},{x,y}};
  	if(!visited[a.f][a.s]&&!roads.count(path)&&!roads.count(reversePath))
  	  dfs(a.f,a.s);
  }
}

int main() {
  setIO("countcross");
  cin>>n>>k>>r;
  f0r(i,r) {
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ppii road = {{x1,y1},{x2,y2}};
    ppii reverseRoad = {{x2,y2},{x1,y1}};
    roads.insert(road);
    roads.insert(reverseRoad);
  }
  f0r(i,k) {
    int x,y;
    cin>>x>>y;
    cows.pb(mp(x,y));
  }
  f0r(i,k) {
    dfs(cows[i].f,cows[i].s);
    f0r(o,k) {
      if(cows[o]==cows[i]) continue;
      if(!visited[cows[o].f][cows[o].s]) {
        ppii pear = {{cows[i].f,cows[i].s},{cows[o].f,cows[o].s}};
        ppii reversePear = {{cows[o].f,cows[o].s},{cows[i].f,cows[i].s}};
        d.insert(pear);
        d.insert(reversePear);
      }
    }
    f0r(j, 101)
      f0r(g, 101)
        visited[j][g]=false;
  }
  cout<<d.size()/2<<endl;
}
