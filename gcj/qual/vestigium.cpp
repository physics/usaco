#include <bits/stdc++.h>

using namespace std;

#define F0R(x,y) for(int x=0;x<y;x++)

int t;

string nest (int tar, int dep) {
  string n = "";
  F0R(i,dep) n += "(";
  n += to_string(tar);
  F0R(i,dep) n += ")";
  return n;
}

int main () {

}
