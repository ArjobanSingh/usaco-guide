#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int LOW  = 0;
const int HIGH = 1000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);

  int x, y;

  cin >> x >> y;

  int ans  = 0;
  int mult = 1;

  int  prev = x;
  bool add  = true;
  while (true) {
    int next = add ? x + mult : x - mult;
    int lo   = min(prev, next);
    int hi   = max(prev, next);

    int diff = hi - lo;
    ans += diff;

    if (y >= lo && y <= hi) {
      // Y lies b/w current lo & hi. Subtract the extra covered distance
      // when y is not at the edge.
      ans -= abs(next - y);
      break;
    }

    add = !add;
    mult *= 2;
    prev = next;
  }

  cout << ans << "\n";
}
