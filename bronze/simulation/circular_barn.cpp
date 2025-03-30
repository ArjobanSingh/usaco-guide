#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int simulate(int startIdx, vector<int> &cows, int cowsSum, int n) {
  int idx = (startIdx + 1) % n;

  int ans = 0;
  while (true) {
    if (idx == startIdx) { break; }
    ans += cowsSum;
    cowsSum -= cows[idx];

    idx = (idx + 1) % n;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  int n;

  cin >> n;

  vector<int> cows(n);
  int         sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> cows[i];
    sum += cows[i];
  }

  int ans = INT_MAX;

  for (int i = 0; i < n; i++) {
    ans = min(ans, simulate(i, cows, sum - cows[i], n));
  }

  cout << ans << "\n";
}
