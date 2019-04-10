#include <iostream>
#include <vector>
#include<map>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  std::map<double,int,std::greater<double>> mKnapSak;

   for(int i = 0; i < weights.size() ; i++) {

        std::pair<double,int> pp ((values[i]/(weights[i] * 1.0)),weights[i]);
        mKnapSak.insert(pp);    
   }

  for(auto m : mKnapSak ) {

      if(m.second <= capacity) {

          value += m.second * m.first; 
          capacity -= m.second;
      }
      else {
          value += capacity * m.first;
          capacity = 0;
      }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
