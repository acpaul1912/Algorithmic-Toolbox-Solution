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

}

long long get_fibonacci_huge_naive(long long n, long long m) {
    
     long long  a = n % get_fibonacci_mode_naive(m);
     

    if (a <= 1)
        return a;

    int previous = 0;
    int current  = 1;
    int res = 0;

    for (int i = 2; i <= a ; ++i) {
        
         int temp = previous; 
         previous = current;      
         current = temp + previous;         
         current = current % m;
    }

    return current % m ;


    
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
