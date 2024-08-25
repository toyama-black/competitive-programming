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
#include <iostream>
#include <vector>
#include <string>

using namespace std;


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
    // 部屋iまでの所要時間と経路を管理
    vector<int> dp_time(N+1);
    vector<int> dp_prev(N+1); // 直前の部屋を記録
    // 部屋0は存在しない、また部屋1はスタート地点なので所要時間は0分
    dp_time[0] = 0, dp_time[1] = 0;
    // 部屋0,1の前の部屋はそれぞれ存在しないので-1とする
    dp_prev[0] = -1, dp_prev[1] = -1;
    for (int i = 2; i <= N; i++) {
        if (i == 2) {
            dp_time[i] = dp_time[i-1] + A[i];
            // 部屋1から部屋2へ移動したことになる
            dp_prev[i] = i-1;
        } else {
            if (dp_time[i-1] + A[i] < dp_time[i-2] + B[i]) {
                dp_time[i] = dp_time[i-1] + A[i];
                // 部屋i-1から部屋iへ移動したことになる
                dp_prev[i] = i-1;
            } else {
                dp_time[i] = dp_time[i-2] + B[i];
                // 部屋i-2から部屋iへ移動したことになる
                dp_prev[i] = i-2;
            }
        }
    }

    // 経路の復元
    vector<int> route;
    // i(初期値N)を配列routeに格納する、そのあとiの値をdp_prev[i]に更新し再びiをrouteに格納する...これを終了条件になるまで繰り返す
    // i = 1（部屋1)になりiをrouteに格納したあと、dp_prev[1] = -1（終了条件）に更新され、for文が終了する
    for (int i = N; i != -1; i = dp_prev[i]) {
        route.push_back(i);
    }
    // あとはrouteを逆順にすれば最短距離での部屋の移動経路が完成する
    reverse(route.begin(), route.end());

    // 経路の出力
    cout << route.size() << endl;
    for (size_t i = 0; i < route.size(); ++i) {
        if (i > 0) cout << " ";
        cout << route[i];
    }
    cout << endl;
}