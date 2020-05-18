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
const int MX = 21;
const ld PI = 4*atan((ld)1);

void setIO(string y) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((y+".in").c_str(),"r",stdin);
  freopen((y+".out").c_str(),"w",stdout);
}

struct ok {
  int x1,y1,x2,y2,size;
};

int n;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int tr,br,lc,rc;
char farm[MX][MX];
int visited[MX][MX];
int reg;
vector<ok> v;
int ans;

bool safe (int x, int y) {
  if(x>=tr&&x<=br)
    if(y>=lc&&y<=rc)
      return true;
  return false;
}

void unvisit () {
  FOR(i,MX) {
    FOR(j,MX) {
      visited[i][j] = 0;
    }
  }
}

void dfs (int x, int y, char prev) {
  if(visited[x][y])
    return;
  visited[x][y] = reg;
  FOR(i,4) {
    int newx = x+dx[i];
    int newy = y+dy[i];
    if(safe(newx,newy)&&!visited[newx][newy]) {
      if(farm[newx][newy]==prev) {
        dfs(newx,newy,prev);
      }
    }
  }
}

int32_t main () {
  setIO("where");
  cin >> n;
  FOR(i,n) cin>>farm[i];
  for(int x1=0;x1<n;x1++) {
    for(int y1=0;y1<n;y1++) {
      for(int x2=x1;x2<n;x2++){
        for(int y2=y1;y2<n;y2++){
          // iterating over all rectangles
          // also checking for two colors
          // [x2-x1+1][y2-y1+1];
          vector<char> colors;
          for(int x=x1;x<=x2;++x) {
            for(int y=y1;y<=y2;++y) {
              if(!count(all(colors),farm[x][y]))
                 colors.pb(farm[x][y]);
            }
          }
          if(sz(colors)==2) {
            tr=x1;
            br=x2;
            lc=y1;
            rc=y2;
            reg = 0;
            unvisit();
            int firstColor = -1;
            for(int x=x1;x<=x2;++x)  {
              for(int y=y1;y<=y2;++y) {
                if(!visited[x][y]&&farm[x][y]==colors[0]) {
                  ++ reg;
                  dfs(x,y,colors[0]);
                }
              }
            }
            firstColor = reg;
            reg = 0;
            unvisit();
            int secondColor = -1;
            for(int x=x1;x<=x2;++x)  {
              for(int y=y1;y<=y2;++y) {
                if(!visited[x][y]&&farm[x][y]==colors[1]) {
                  ++ reg;
                  dfs(x,y,colors[1]);
                }
              }
            }
            secondColor = reg;
            bool valid;
            if(firstColor==1&&secondColor>1) valid = true;
            else if(secondColor==1&&firstColor>1) valid = true;
            else valid = false;
            if(valid) {
              int size = (x2-x1+1)*(y2-y1+1);
              v.pb({x1,y1,x2,y2,size}); // valid PCL
            }
          }
        }
      }
    }
  }
  bool invalid[sz(v)];
  FOR(i,sz(v)) invalid[i]=false;
  FOR(i,sz(v)) {
    for(int j=0;j<sz(v);j++) {
      if(i==j) continue;
      int a_x1,a_y1,a_x2,a_y2;
      a_x1=v[i].x1; a_y1=v[i].y1;
      a_x2=v[i].x2; a_y2=v[i].y2;
      int b_x1,b_y1,b_x2,b_y2;
      b_x1=v[j].x1; b_y1=v[j].y1;
      b_x2=v[j].x2; b_y2=v[j].y2;
      if(a_x1>=b_x1&&a_x2<=b_x2) {
        if(a_y1>=b_y1&&a_y2<=b_y2) {
          invalid[i] = true;
        }
      }
    }
  }
  
  FOR(i,sz(v)) {
    if(!invalid[i])
      ++ ans;
  }
  cout << ans << "\n";
  return 0;
}
