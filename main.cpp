#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<int> res{-1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  int n;
  cin >> n;

  vector<tuple<int, int, int>> input;
  while (n--) {
    int a, b, g;
    cin >> a >> b >> g;

    input.push_back(make_tuple(a - 1, b - 1, g - 1));
  }

  int result = 0;
  for (int i = 0; i < 3; i++) {
    vector<bool> shells(3, false);
    shells[i] = true;

    int inner_sum = 0;
    for (const auto &t : input) {
      int a, b, g;
      tie(a, b, g) = t;

      swap(shells[a], shells[b]);

      if (shells[g]) { inner_sum++; }
    }

    result = max(result, inner_sum);
  }

  cout << result << "\n";
}
