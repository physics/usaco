#include <bits/stdc++.h>
#define f0r(x,n) for(int x=0;x<n;x++)
#define pii pair<int,int>
#define pb push_back
using namespace std;
void setIO(string v) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((v+".in").c_str(),"r",stdin);
  freopen((v+".out").c_str(),"w",stdout);
}
int n,a;
vector<pii> c; // coords
int main () {
  setIO("triangles");
  cin>>n;
  f0r(i, n) {
    int x,y;
    cin>>x>>y;
    c.pb({x,y});
  }
  f0r(i,n) {
    f0r(j,n) {
      f0r(e,n) {
        if(c[i].first==c[j].first||c[i].first==c[e].first||c[j].first==c[e].first) {
          if(c[i].second==c[j].second||c[i].second==c[e].second||c[j].second==c[e].second) {
            int x1=c[i].first,y1=c[i].second;
            int x2=c[j].first,y2=c[j].second;
            int x3=c[e].first,y3=c[e].second;
            a=max(a,(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
          }
        }
      }
    }
  }
  cout<<a<<endl;
}