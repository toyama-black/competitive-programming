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

long long countMultiplesInContinuousSubarrays(const vector<int>& A, int M) {
    int N = A.size();
    vector<long long> prefixSum(N + 1, 0);
    vector<int> count(M, 0);
    long long result = 0;
    
    count[0] = 1;  // 空の部分列も考慮
    
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = (prefixSum[i] + A[i]) % M;
        result += count[prefixSum[i + 1]];
        count[prefixSum[i + 1]]++;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long result = countMultiplesInContinuousSubarrays(A, M);
    cout << result << endl;

    return 0;
}