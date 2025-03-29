#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

// This implements a two-pointer approach to compare speeds in two segment
// arrays. The algorithm iterates through both arrays until one is fully
// traversed. At each step, it compares the speed of the current segments and
// updates the maximum difference. The pointer corresponding to the segment that
// is fully traversed moves forward, while the remaining distance of the other
// segment is reduced accordingly.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);

  int m, n;

  cin >> m >> n;

  vector<int> s1(m);
  vector<int> speed1(m);

  vector<int> s2(n);
  vector<int> speed2(n);

  for (int i = 0; i < m; i++) { cin >> s1[i] >> speed1[i]; }
  for (int i = 0; i < n; i++) { cin >> s2[i] >> speed2[i]; }

  int i = 0, j = 0;
  int ans = 0;

  while (i < m && j < n) {
    int spd1 = speed1[i];
    int spd2 = speed2[j];

    ans = max(ans, spd2 - spd1);

    int dist1 = s1[i];
    int dist2 = s2[j];

    if (dist1 < dist2) {
      i++;
      s2[j] -= dist1;
    } else if (dist1 > dist2) {
      j++;
      s1[i] -= dist2;
    } else {
      i++;
      j++;
    }
  }

  cout << ans << "\n";
}
