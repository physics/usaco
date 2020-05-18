#include <bits/stdc++.h>
#define f0r(x,n) for(int x=0;x<n;x++)
using namespace std;
void setIO(string v) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((v+".in").c_str(),"r",stdin);
  freopen((v+".out").c_str(),"w",stdout);
}
int n,p;
map<string,int> cs;
int main () {
  setIO("citystate");
  cin>>n;
  f0r(i,n) {
    string c,s;
    cin>>c>>s;
    if(c.substr(0,2)!=s) {
      string cmb = c.substr(0,2) + s;
      if(!cs.count(cmb))
        cs[cmb] = 0;
      cs[cmb]=cs[cmb]+1;
    }
  }
  for(const auto& key : cs) {
    string rev = key.first.substr(2,4) + key.first.substr(0,2);
    if(cs.count(rev))
      p+=cs[key.first]*cs[rev];
  }
  cout<<p/2<<endl;
}