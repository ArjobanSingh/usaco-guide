#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

  string s;
  string t;
  cin >> s >> t;

  string ans = "";
  for (size_t i = 0; i < s.length(); i++) {
    ans.push_back(s[i]);
    // check if last t.length() chars of ans matches t. If yes remove them
    if (ans.length() >= t.length() &&
        ans.substr(ans.length() - t.length(), t.length()) == t) {
      ans.resize(ans.size() - t.size());
    }
  }
  cout << ans << "\n";
}
