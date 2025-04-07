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
  // auto start = chrono::high_resolution_clock::now();

  while (true) {
    string newStr = "";
    size_t tIdx   = 0;
    size_t i      = 0;

    // cout << "here " << s.length() << "\n";
    while (i < s.length()) {
      if (t[tIdx] != s[i]) {
        // didn't match, start comparing again from cur_start's idx + 1.
        size_t startIdx = i - tIdx;
        newStr.push_back(s[startIdx]);
        i    = startIdx + 1;
        tIdx = 0;
      } else if (tIdx == t.length() - 1) {
        // matched whole substring;
        tIdx = 0;
        i++;
      } else if (i == s.length() - 1) {
        // not matched completely but, main string is exhausted
        // so push all chars which we didn't push till now.
        for (size_t j = i - tIdx; j <= i; j++) { newStr.push_back(s[j]); }
        tIdx = 0;
        i++;
      } else {
        // matched but not completely yet.
        i++;
        tIdx++;
      }
    }

    if (s.length() == newStr.length()) { break; }
    s = newStr;
  }

  // auto end      = chrono::high_resolution_clock::now();
  // auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  // std::cout << "Execution time: " << duration.count() << " ms\n";

  cout << s << "\n";
}
