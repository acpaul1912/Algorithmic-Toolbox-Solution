#include <iostream>
#include <vector>
using std::vector;


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

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    int rem = get_fibonacci_mode_naive(10) ;
    int first = from % rem ;
    int last = to % rem;

    for (long long i = 0; i <= last ; ++i) {
        if (i >= first) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current % 10;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
