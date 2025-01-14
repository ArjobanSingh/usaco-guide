#include <iostream>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    const int MOD = 1000000007;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    long long total = 0;

    while (N--)
    {
        long long num;
        cin >> num;

        total += num;
        if (M == 1)
        {
            cout << total % MOD << "\n";
        }
    }

    if (M == 0)
    {
        cout << total % MOD << "\n";
    }
}