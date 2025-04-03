#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);

  int n;

  cin >> n;

  vector<int> ans(26);
  for (int i = 0; i < n; i++) {
    string word1;
    string word2;

    cin >> word1;
    cin >> word2;

    vector<int> tempA(26);
    for (int j = 0; j < word1.size(); j++) { tempA[word1[j] - 'a']++; }

    vector<int> tempB(26);
    for (int k = 0; k < word2.size(); k++) { tempB[word2[k] - 'a']++; }

    for (int l = 0; l < 26; l++) { ans[l] += max(tempA[l], tempB[l]); }
  }

  for (int i = 0; i < ans.size(); i++) { cout << ans[i] << "\n"; }
}
