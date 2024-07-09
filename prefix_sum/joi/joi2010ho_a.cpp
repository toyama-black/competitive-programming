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
    int n,m;
    cin >> n >> m;
    vector<int> acc(n+1);
    // 扱いやすいように0-indexedではなく1-indexedにする
    // 宿場町0は存在しない、また宿場町1はスタート地点なので0
    acc[0] = 0, acc[1] = 0;
    // 出発する宿場町
    int now = 1;
    ll ans = 0;
    // 宿場町i-1からiまでの距離を入力し、ついでに累積和を求めていく
    for (int i = 2; i <= n; i++) {
        int syukuba;
        cin >> syukuba;
        acc[i] += acc[i-1] + syukuba;
    }
    // i日目に現時点からtoday個先(符号が+)あるいはtoday個前(符号が-)の宿場町へ移動する
    for (int i = 1; i <= m; i++) {
        int today;
        cin >> today;
        // today個先の宿場町へ移動する
        // 移動距離は (移動先までの累積和 - 移動前までの累積和) % 100000
        if (today > 0) ans += (acc[now + today] - acc[now]) % 100000;
        // today個前の宿場町へ移動する
        // 移動距離は (移動前までの累積和 - 移動先までの累積和) % 100000
        else ans += (acc[now] - acc[now + today]) % 100000;
        // 現時点の宿場町を更新する
        now += today; 
        
    }
    // 出力する際にも10^5で割った余りを求める
    cout << ans % 100000 << "\n";
}