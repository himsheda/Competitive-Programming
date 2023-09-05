#include <bits/stdc++.h>
using namespace std;

using ll = long long;



map< pair<int, int>, int> mp;

int solve(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2)
        return 1;

    if (x1 > x2 || y1 > y2)
        return 0;

    if (mp.find({x1, y1}) != mp.end())
        return mp[{x1, y1}];

    if (solve(x1, x1 + y1, x2, y2)) {
        mp[{x1, y1}] = 1;
        return 1;
    }

    if (solve(x1 + y1, y1, x2, y2)) {
        mp[{x1, y1}] = 1;
        return 1;
    }

    mp[{x1, y1}] = 0;
    return 0;
}

void find(int x1, int y1, int x2, int y2) {
    int ans = solve(x1, y1, x2, y2);
    if (ans == 1)
        cout << "Yes";
    else
        cout << "No";

    return;
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    find(x1, y1, x2, y2);
    return 0;
}