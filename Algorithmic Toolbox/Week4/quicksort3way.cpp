#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using std::vector;
using std::swap;

std::pair<int,int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int low = l;
  int high = r ;    

  int mid = low ;
  while(mid <= high) {

      if(a[mid] < x ) {

        swap (a[low++], a[mid++]);
      }
      else if(a[mid] == x )
        mid++;
      else if(a[mid] > x) {
        swap(a[high--] , a[mid]);
      }
    }

   return std::make_pair(low,mid);
 }


void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  std::pair<int,int> pair = partition3(a, l, r);

  randomized_quick_sort(a, l, pair.first);
  randomized_quick_sort(a, pair.second,r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
