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
    double N;
    cin >> N;
    double L, R;
    L = 1;
    // 求める数xがN以上になることはないので
    R = N;
    // LとRの差が非常に小さくなった場合にループを終了するようにします
    while (R - L > 1e-9) { // ループの終了条件を改善
        // mid = x
        double mid = (L + R) / 2.0;
        // 与式の左辺
        double value = mid * (mid * mid + 1);
        if (value > N) {
            R = mid;
        } else {
            // Lが以下のように更新されると、整数部分はmid自体で合っている場合にその解をスキップしてしまう可能性があります。
            // L = mid + 1;
            // 答えに小数点も考慮する問題の場合、整数部分はmidで小数点以下を二分探索で求める場合があるのでLもmidに更新し、
            // 答えに小数点は考慮せず整数だけを扱う場合ならその整数を二分探索で求めるためLはmid + 1 で更新する
            L = mid;
        }
    }
    // 小数点以下6桁まで表示する
    cout << fixed << setprecision(6) << L << "\n";
}