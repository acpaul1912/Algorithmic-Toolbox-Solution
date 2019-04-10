#include <iostream>

long long get_fibonacci_mode_naive( long long m) {
    
     long long a = 0, b =1 , c = a+b, i;

     for (i = 0; i < m *m; ++i)
     {
 
         a = b;
         b = c ;
         c= (a+b) % m;
         if(a ==0 && b ==1) 
            return (i+1);
     }
   
 return m+1;
}
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;
    
    int rem = get_fibonacci_mode_naive(10) ;
   // std::cout << rem <<std::endl;
    long long end = n % rem;
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;    
    
    if(end % rem == 0) end = 0, sum = 0;
   // std::cout<< end;
    for (long long i = 0; i <end -1 ; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current % 10;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
