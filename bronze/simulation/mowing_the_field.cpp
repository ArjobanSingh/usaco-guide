#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

string arrToKey(array<int, 2> &coords) {
  return to_string(coords[0]) + ":" + to_string(coords[1]);
}

// Top -> Right -> Bottom -> Left. (X, Y) coords, top & right is +1,
// bottom and left is -1
int dirs[4][2] = {
  { 0,  1},
  { 1,  0},
  { 0, -1},
  {-1,  0}
};

void simulateAndUpdate(array<int, 2> &coords, int num, int dirIdx,
                       unordered_map<string, int> &map, int &ans, int &turn) {
  int *dir = dirs[dirIdx];
  for (int i = 0; i < num; i++) {
    coords[0] += dir[0];
    coords[1] += dir[1];

    string newKey    = arrToKey(coords);
    int    prevValue = map[newKey];
    if (prevValue) { ans = min(ans, turn - prevValue); }
    map[newKey] = turn;
    turn++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);

  int n;
  cin >> n;
  array<int, 2>              coords = {0, 0}; // X, Y
  unordered_map<string, int> map;
  int                        ans = INT_MAX;

  int turn = 1;
  for (int i = 0; i < n; i++) {
    char dir;
    int  num;

    cin >> dir >> num;
    switch (dir) {
      case 'N': simulateAndUpdate(coords, num, 0, map, ans, turn); break;
      case 'E': simulateAndUpdate(coords, num, 1, map, ans, turn); break;
      case 'S': simulateAndUpdate(coords, num, 2, map, ans, turn); break;
      case 'W': simulateAndUpdate(coords, num, 3, map, ans, turn); break;
      default : break;
    }
  }

  if (ans == INT_MAX) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}
