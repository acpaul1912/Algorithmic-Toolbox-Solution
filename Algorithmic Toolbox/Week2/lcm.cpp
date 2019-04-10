#include <iostream>

int gcd_naive(int a, int b) {
   
   if(a==0) {
    return b;
   }

   return gcd_naive(b%a,a);

}

long long lcm_naive(int a, int b) {

  int  gcd  = gcd_naive(a,b);
  return(long long) (a/gcd)* b; 
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}