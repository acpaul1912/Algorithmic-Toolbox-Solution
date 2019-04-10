#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int i = 1; 
  while(n > 0) {
    
      if( (n - i) >= (i+1)) {
            summands.push_back(i);
            n = n - i;
      }    
      else if ((n - i) == 0){

          summands.push_back(i);
          n =0;
      }

     i++;
    
  }
  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
