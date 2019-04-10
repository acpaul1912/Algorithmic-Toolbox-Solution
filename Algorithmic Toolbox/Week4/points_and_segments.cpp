#include <iostream>
#include <map>
#include<vector>
#include<algorithm>
using std::vector;


std::vector<int> fast_count_segments(std::vector<int> &starts,
                                     std::vector<int> &ends,
                                     const std::vector<int>& points) {
    std::vector<int> cnt(points.size());
    std::vector<std::pair<int, int>> pairs(points.size());

    for (auto i = 0u; i != points.size(); ++i) {
        pairs[i] = std::make_pair(points[i], i);
    }
    std::sort(starts.begin(), starts.end());
    std::sort(ends.begin(), ends.end());
    std::sort(pairs.begin(), pairs.end());
    int coverage = 0;
    auto it_start = starts.begin();
    auto it_end = ends.begin();
    for (auto& x : pairs) {

        while (it_start != starts.end() && *it_start <= x.first) {
            ++it_start;
            ++coverage;
        }
        while (it_end != ends.end() && *it_end < x.first) {
            ++it_end;
            --coverage;
        }
        cnt[x.second] = coverage;     
    }
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
          



          cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
