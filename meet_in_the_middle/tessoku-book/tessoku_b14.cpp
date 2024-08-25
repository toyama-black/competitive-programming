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
    int N, K;
    cin >> N >> K;
    vector<int> A(N); // 0-indexで宣言
    for (int i = 0; i < N; i++) cin >> A[i]; // 0-indexで入力を受け取る

    // 配列 P を作成
    vector<int> P;
    // ビット全探索を用いて、全ての可能な部分集合の和を格納することで、配列Pのサイズを適切に設定します。
    for (int bit = 0; bit < (1 << (N / 2)); bit++) {
        int sum = 0;
        for (int i = 0; i < N / 2; i++) {
            // 論理積 (AND) (2つのビットを比較し、両方のビットが1の場合にのみ結果が1になり、それ以外の場合は0になります。)である部分和を求めていく
            if (bit & (1 << i)) sum += A[i]; // 0-indexでアクセス
        }
        // 最終的にある部分和が決定され、それを配列Pに格納する
        P.push_back(sum);
    }

    // 配列 Q を作成
    vector<int> Q;
    // 配列Pと同じく配列Qのサイズを適切に設定します。
    for (int bit = 0; bit < (1 << (N - N / 2)); bit++) {
        int sum = 0;
        for (int i = 0; i < (N - N / 2); i++) {
            // A[N/2+i]について
            // 配列Aの半分(N/2)を加算することで配列Aの右側（後半部分)をindexで求められる
            if (bit & (1 << i)) sum += A[N / 2 + i]; // 0-indexでアクセス
        }
        Q.push_back(sum);
    }

    // 配列 P と Q を昇順にソート
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());

    // 二分探索
    for (int i = 0; i < P.size(); i++) {
        int target = K - P[i];
        // その値自体が存在するか確認し、その有無をbool型で返す
        if (binary_search(Q.begin(), Q.end(), target)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // 見つからなかった場合
    cout << "No" << endl;
    return 0;
}