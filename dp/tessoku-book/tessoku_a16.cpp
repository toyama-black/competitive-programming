#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int inf = INT_MAX / 2;
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string_view>
#include <type_traits>
 
#ifdef LOCAL
#  include <debug_print.hpp>
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif
 
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N+1), B(N+1);
    for (int i = 1; i <= N; i++) {
        // A[0], A[1]は存在しない
        if (i < 2) continue;
        else cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        // B[0], B[1], B[2]は存在しない
        if (i < 3) continue;
        else cin >> B[i];
    }
    // 部屋iまでの所要時間を管理
    vector<int> dp(N+1);
    // 部屋0は存在しない、また部屋1はスタート地点なので所要時間は0分
    dp[0] = 0, dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (i == 2) dp[i] = A[i];
        else dp[i] = min(dp[i-1] + A[i], dp[i-2] + B[i]);
    }
    cout << dp[N] << endl;
}