#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int rowSize   = 3;
const int colSize   = 3;
const int boardSize = rowSize * colSize;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);

  vector<char> board(boardSize);
  for (int i = 0; i < boardSize; i++) { cin >> board[i]; }

  set<char>              indWinners;
  set<tuple<char, char>> teamWinners;

  // check for rows
  for (int row = 0; row < rowSize; row++) {
    set<char> items;
    for (int col = 0; col < colSize; col++) {
      int index = col + row * colSize;
      items.insert(board[index]);
    }

    size_t size = items.size();
    if (size == 1) {
      for (char win : items) { indWinners.insert(win); }
    } else if (size == 2) {
      vector<char> chars(items.begin(), items.end());
      sort(chars.begin(), chars.end());
      teamWinners.insert(make_pair(chars[0], chars[1]));
    }
  }

  // check for cols
  for (int col = 0; col < colSize; col++) {
    set<char> items;
    for (int row = 0; row < rowSize; row++) {
      int index = col + row * rowSize;
      items.insert(board[index]);
    }

    size_t size = items.size();
    if (size == 1) {
      for (char win : items) { indWinners.insert(win); }
    } else if (size == 2) {
      vector<char> chars(items.begin(), items.end());
      sort(chars.begin(), chars.end());
      teamWinners.insert(make_pair(chars[0], chars[1]));
    }
  }

  // check for left diagonal
  set<char> items;
  items.insert(board[0]);
  items.insert(board[4]);
  items.insert(board[8]);

  size_t size = items.size();
  if (size == 1) {
    for (char win : items) { indWinners.insert(win); }
  } else if (size == 2) {
    vector<char> chars(items.begin(), items.end());
    sort(chars.begin(), chars.end());
    teamWinners.insert(make_pair(chars[0], chars[1]));
  }

  // check for right diagonal
  items.clear();
  items.insert(board[2]);
  items.insert(board[4]);
  items.insert(board[6]);

  size = items.size();
  if (size == 1) {
    for (char win : items) { indWinners.insert(win); }
  } else if (size == 2) {
    vector<char> chars(items.begin(), items.end());
    sort(chars.begin(), chars.end());
    teamWinners.insert(make_pair(chars[0], chars[1]));
  }

  cout << indWinners.size() << "\n";
  cout << teamWinners.size() << "\n";
}
