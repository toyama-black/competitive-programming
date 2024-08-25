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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> A[i][j];
    }

    // 列ごとの累積和を格納する配列
    vector<vector<int>> r_cumulativeSum(H, vector<int>(W, 0));

    // 行ごとの累積和を格納する配列
    vector<vector<int>> c_cumulativeSum(H, vector<int>(W, 0));

    // 行ごとの累積和の計算
    for (int j = 0; j < W; ++j) {
        for (int i = 0; i < H; ++i) {
            if (i == 0) {
                r_cumulativeSum[i][j] = A[i][j]; // 最初の行はそのまま
            } else {
                r_cumulativeSum[i][j] = r_cumulativeSum[i - 1][j] + A[i][j]; // 上の行の累積和に現在の要素を加える
            }
        }
    }

    // 列ごとの累積和の計算
    for (int i = 0; i < H; ++i) { // 行をループ
        for (int j = 0; j < W; ++j) { // 列をループ
            if (j == 0) {
                c_cumulativeSum[i][j] = A[i][j]; // 最初の列はそのまま
            } else {
                c_cumulativeSum[i][j] = c_cumulativeSum[i][j - 1] + A[i][j]; // 左の列の累積和に現在の要素を加える
            }
        }
    }

    for (int i = 0; i < H; ++i) { // 行をループ
        for (int j = 0; j < W; ++j) { // 列をループ
            // 行の累積和 + 列の累積和 - A[i][j](A[i][j]は二重に加算されているので)
            cout << r_cumulativeSum[H-1][j] + c_cumulativeSum[i][W-1] - A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}