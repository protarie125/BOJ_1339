#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll N;
map<char, ll> dict{};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
  for (auto i = 0; i < N; ++i) {
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    auto b = 1;
    for (auto j = 0; j < s.length(); ++j) {
      dict[s[j]] += b;
      b *= 10;
    }
  }

  vl vec{};
  for (const auto& [k, v] : dict) {
    vec.push_back(v);
  }

  sort(vec.rbegin(), vec.rend());
  ll ans = 0;
  ll k = 9;
  for (const auto& x : vec) {
    ans += x * k;
    --k;
  }

  cout << ans;

  return 0;
}