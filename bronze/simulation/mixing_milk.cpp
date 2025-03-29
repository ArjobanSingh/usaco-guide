#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int N        = 3; // The number of buckets (which is 3)
const int TURN_NUM = 100;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  vector<int> capacity(N);
  vector<int> buckets(N);

  for (int i = 0; i < N; i++) { cin >> capacity[i] >> buckets[i]; }

  int b1 = 0;
  int b2 = 1;
  for (int i = 0; i < TURN_NUM; i++) {
    int b1Milk = buckets[b1];
    int b2Milk = buckets[b2];

    // updated milk volume in bucket 2
    buckets[b2] = min(capacity[b2], b1Milk + b2Milk);
    int poured  = buckets[b2] - b2Milk;
    buckets[b1] = b1Milk - poured;

    b1 = (b1 + 1) % N;
    b2 = (b2 + 1) % N;
  }

  for (const auto &b : buckets) { cout << b << "\n"; }
}
