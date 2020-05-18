#include <bits/stdc++.h>

using namespace std;
 
#define int long long

typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ld,ld> pdd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<pii> vpii;
typedef vector<pdd> vpdd;

#define FOR(x,y) for(int x=0;x<y;x++)
#define FOR1(x,y) for(int x=1;x<y;x++)
#define LOOP(y) for(int x=0;x<y;x++)

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
const int INF = 1e18;
const int MX = 101;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

string board[MX];
int N,K;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int visited[MX][10];
int cntcmp;
bool done;

void unvisit () {
  FOR(i,MX)
    FOR(j,10)
      visited[i][j] = 0;
}

bool safe (int x, int y) { return x>=0&&x<N&&y>=0&&y<10; }

void dfs (int x, int y, char prev) {
  if(visited[x][y])
    return;
  visited[x][y] = cntcmp;
  FOR(i,4)
    if(safe(x+dx[i],y+dy[i]) && !visited[x+dx[i]][y+dy[i]] && board[x+dx[i]][y+dy[i]]==prev)
      dfs(x+dx[i],y+dy[i],prev);
}

vpii freq (int r) {
  // if connected component's size >= K, returns all elements of the connected component
  // otherwise, return an empty vector because elements of connected component of size < K don't fall
  vpii frq;
  vpii empty;
  FOR(i,N)
    FOR(j,10)
      if(visited[i][j]==r)
        frq.pb(mp(i,j));
  if(sz(frq)>=K) return frq;
  else return empty;
}

void fall (vpii falling) {
  FOR(i,sz(falling)) {
    int x=falling[i].f,y=falling[i].s;
    // makes all elements that are going to fall equal to 0
    board[x][y]='0';
  }
  FOR(col,10) { // gravity on each column
    vector<char> nz; // nonzero values in each col
    FOR(row,N) {
      if(board[row][col]!='0')
        nz.pb(board[row][col]);
    }
    int cur = 0;
    FOR(row,N) {
      if(row<N-sz(nz)) board[row][col] = '0';
      else {
        board[row][col] = nz[cur];
        ++ cur;
      }
    }
  }
}

int32_t main () {
  setIO("mooyomooyo");
  cin >> N >> K;
  FOR(i,N) cin>>board[i];
  while(!done) {
    char colors[9] = {'1','2','3','4','5','6','7','8','9'};
    vpii falling;
    FOR(c,9) {
      unvisit();
      cntcmp = 0;
      FOR(i,N) {
        FOR(j,10) {
          if(!visited[i][j] && board[i][j]==colors[c]) {
            ++ cntcmp;
            dfs(i,j,colors[c]);
          }
        }
      }
      if(cntcmp) {
        FOR1(i,cntcmp+1) {
          vpii frq = freq(i);
          FOR(i,sz(frq)) {
            falling.pb(frq[i]);
          }
        }
      }
    }
    if(sz(falling))
      fall(falling);
    else
      done = true;
  }
  FOR(i,N) cout<<board[i]<<"\n";
}
