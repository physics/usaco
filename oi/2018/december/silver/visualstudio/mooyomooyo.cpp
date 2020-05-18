#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
#include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <bit>
#include <compare>
#include <concepts>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
// #include <syncstream>
#include <version>
#endif

using namespace std;

#define int long long

typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;

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
const ld PI = 4 * atan((ld)1);

void setIO(string y) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((y + ".in").c_str(), "r", stdin);
	freopen((y + ".out").c_str(), "w", stdout);
}

string board[MX];
int N, K;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int visited[MX][10];
int cntcmp;
bool done;

void unvisit() {
	FOR(i, MX)
		FOR(j, 10)
		visited[i][j] = 0;
}

bool safe(int x, int y) { return x >= 0 && x<N&&y >= 0 && y<10; }

void dfs(int x, int y, char prev) {
	if (visited[x][y])
		return;
	visited[x][y] = cntcmp;
	FOR(i, 4)
		if (safe(x + dx[i], y + dy[i]) && !visited[x + dx[i]][y + dy[i]] && board[x + dx[i]][y + dy[i]] == prev)
			dfs(x + dx[i], y + dy[i], prev);
}

vpii freq(int r) {
	vpii frq;
	vpii empty;
	FOR(i, N)
		FOR(j, 10)
		if (visited[i][j] == r)
			frq.pb(mp(i, j));
	if (sz(frq) >= K) return frq;
	else return empty;
}

void fall(vpii falling) {
	FOR(i, sz(falling)) {
		int x = falling[i].f, y = falling[i].s;
		board[x][y] = '0';
	}
	FOR(col, 10) { // gravity on each column
		vector<char> nz; // nonzero values in each col
		FOR(row, N) {
			if (board[row][col] != '0')
				nz.pb(board[row][col]);
		}
		int cur = 0;
		FOR(row, N) {
			if (row<N - sz(nz)) board[row][col] = '0';
			else {
				board[row][col] = nz[cur];
				++cur;
			}
		}
	}
}

int32_t main() {
	//setIO("mooyomooyo");
	cin >> N >> K;
	FOR(i, N) cin >> board[i];
	FOR(i, N) {
		FOR(j, 10)
			cout << board[i][j];
		cout << "\n";
	}
	int iter = 1;
	while (!done) {
		cout << iter++ << "\n";
		char colors[9] = { '1','2','3','4','5','6','7','8','9' };
		vpii falling;
		FOR(c, 9) {
			unvisit();
			int cntcmp = 0;
			cout << cntcmp << "\n";
			FOR(i, N) {
				FOR(j, 10) {
					if (!visited[i][j] && board[i][j] == colors[c]) {
						++cntcmp;
						dfs(i, j, colors[c]);
					}
				}
			}
			if (cntcmp) {
				cout << cntcmp << "\n";
				FOR1(i, cntcmp + 1) {
					vpii frq = freq(i);
					FOR(i, sz(frq)) {
						falling.pb(frq[i]);
					}
				}
			}
		}
		if (sz(falling)) {
			fall(falling);
		}
		else {
			done = true;
		}
	}
	FOR(i, N) cout << board[i] << "\n";
}
