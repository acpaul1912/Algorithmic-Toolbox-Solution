#include <iostream>
#include <vector>
using std::min;
using std::vector;
int get_change(int m) {

  vector<int> change(m+5);

  change[0] = 0;
  change[1] = 1; 
  change[2] = 2;
  change[3] = 1;
  change[4] = 1;

  for(int i = 5 ; i <= m ; i++) {

  	int min1 = min((change[i-4]+ change[4]), (change[i-3] + change[3]));
  	change[i] = min( (change[i-1] + change[1]) , min1);
  }
  //write your code here
  return change[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
