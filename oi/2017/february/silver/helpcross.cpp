#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define lb lower_bound
#define up upper_bound
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
#define F0R(x,n) for(int x=0;x<n;x++)
#define MX 100001
using namespace std;
typedef long long ll;

void setIO(string s) { // benq i/o
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

bool ss (const pi &a, const pi &b) {
  return a.s < b.s;
}

int c,n;
vector<int> ch;
vector<pi> cows;

int main() {
  setIO("helpcross");
  cin>>c>>n;
  F0R(i,c) {
    int chicken;
    cin>>chicken;
    ch.pb(chicken);
  }
  sort(ch.begin(), ch.end());
  F0R(i,n) {
    int a,b;
    cin>>a>>b;
    cows.pb(mp(a,b));
  }
  sort(cows.begin(), cows.end(), ss);
  F0R(i,n) {
    int start = cows[i].f;
    int end = cows[i].s;
    vector<int>::iterator low;
    low = lower_bound(ch.begin(), ch.end(), start);
    if(low != ch.end()) {
      int pos = low - ch.begin();
      if(ch[pos] <= end) {
        ch.erase(ch.begin() + pos);
      }
    }
  }
  cout << c - ch.size() << endl;
}
