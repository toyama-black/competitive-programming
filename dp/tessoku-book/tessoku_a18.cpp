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

bool canAchieveSum(const vector<int>& A, int S) {
    // A.size()(配列のサイズが一つ余分) - 1(余分な一つを削除) = dpの行のサイズ(0-index)
    int N = A.size() - 1; // Aは1-indexedなので、Nを調整
    // dpの行および列も1-indexで実装
    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    
    // 初期条件: 和が0になるのは何も選ばない場合
    for (int i = 0; i <= N; ++i) {
        dp[i][0] = true;
    }
    // 以下の実装をすれば全ての組み合わせを試すことができる(実際に書き出してみたり鉄則本を読むとよい)
    // 配列Aの先頭から最大でi個までを使えるとき
    for (int i = 1; i <= N; ++i) {
        // 合計が j であるとする
        for (int j = 1; j <= S; ++j) {
            if (j >= A[i]) {
                // || 論理和（OR)を表すので以下の2つの条件のいずれかが真であればdp[i][j]も真（true）になります。
                // i-1番目までの要素を使って和jを達成できる場合(dp[i-1][j] = true) || i-1番目までの要素を使って和j - A[i]を達成できる(dp[i-1][j - A[i]] = true)、つまりA[i]を加えることで和jを達成できる場合。
                // どちらの条件も偽であるならばdp[i][j]も偽になる
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][S];
}

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N + 1);
    // 1-indexなのでAのサイズが一つ余分である
    for (int i = 1; i <= N; ++i) cin >> A[i];
    
    if (canAchieveSum(A, S)) cout << "Yes" << endl;
    else cout << "No" << endl;
}