#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#define endl '\n'
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
typedef long long ll;

void solve()
{
    deque<char> l1, l2;
    char c;
    while (cin.get(c) && c != '\n') {
        l1.push_back(c);
    }
    while (cin.get(c) && c != '\n') {
        l2.push_back(c);
    }
    while (!l1.empty() && !l2.empty() && l1.front() == l2.front()) {
        l1.pop_front();
        l2.pop_front();
    }
    while (!l1.empty() && !l2.empty() && l1.back() == l2.back()) {
        l1.pop_back();
        l2.pop_back();
    }
    cout << sz(l2) << endl;

}
int main() {
    int t = 1;
  //  cin >> t;
    while (t--)
        solve();

}