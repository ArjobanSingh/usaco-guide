#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);

  int m, n, k;

  cin >> m >> n >> k;

  vector<vector<char>> grid(m, vector<char>(n, 'X'));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) { cin >> grid[i][j]; }
  }

  for (int i = 0; i < m; i++) {
    // repeat i, k times
    for (int ri = 0; ri < k; ri++) {
      for (int j = 0; j < n; j++) {
        // repeat j, k times
        for (int rj = 0; rj < k; rj++) { cout << grid[i][j]; }
      }
      cout << "\n";
    }
  }
}
