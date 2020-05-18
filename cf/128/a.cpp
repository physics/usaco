#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define F0R(x,y) for(int x=0;x<y;x++)
#define F0R1(x,y) for(int x=1;x<y;x++)

#define trav(a, x) for (auto a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

char chess[8][8];
int row, col;
vector<pi> s; // statues
bool win;

int dx[8] = {  1, 0, 1, -1, 1, -1, 0, -1, };
int dy[8] = { -1,-1, 0, -1, 1,  0, 1,  1  };

void statues () {
  trav(statue, s) {
    int x = statue.f;
    int y = statue.s;
    if(y+1 >= 8) {
      chess[x][y] = '.';
    }
    else {
      chess[x][y] = '.';
      chess[x][y+1] = 'S';
    }
  }
}

void dfs (int x, int y) {
  
  cout << x << " " << y << endl;

  if(chess[x][y] == 'A') {
    win = true;
    return;
  }

  F0R(pos, 8) {
    if((x+dx[pos] < 8 && x+dx[pos] >= 0) && (y+dy[pos] < 8 && y+dy[pos] >= 0)) {
      if(chess[x+dx[pos]][y+dy[pos]] != 'S') {
        statues();
        if(chess[x+dx[pos]][y+dy[pos]] == 'S') {
          return;
        }
        else {
          dfs(x+dx[pos], y+dy[pos]);
        }
      }
    }
  }
}

int main () {

  row = 7;
  col = 0;

  F0R(i,8) {
    F0R(j,8) {
      cin>>chess[i][j];
      if(chess[i][j]=='S') {
        s.pb(mp(i,j));
      }
    }
  }

  dfs(row,col);
  
  if(win) cout << "WIN";
  else cout << "LOSE";

}
