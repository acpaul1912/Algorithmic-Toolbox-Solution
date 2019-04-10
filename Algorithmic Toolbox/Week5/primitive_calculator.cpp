#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {

  std::vector<int> min_operataion(n+1);
  std::vector<int> sequence(n+1);
    
  min_operataion[1] = 0;
  sequence[1] = 0;


  for(int i = 2; i <=n ;i++) {


    min_operataion[i] = min_operataion[i-1] +1;
    sequence[i] = i-1;

    if(i%3 == 0) {

        if(min_operataion[i/3] < min_operataion[i]) {

          min_operataion[i] = min_operataion[i/3] +1;

          sequence[i] = i/3;
        }
    }
    if(i%2 ==0) {

      if(min_operataion[i/2] < min_operataion[i]) {

        min_operataion[i] = min_operataion[i/2] +1;
        sequence[i] = i/2;
      }

    }
  }

  std::vector<int> v;

  for(int i = n; i!=0; i= sequence[i]) {

    v.push_back(i);

  } 

  reverse(v.begin(), v.end());
  return v;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
