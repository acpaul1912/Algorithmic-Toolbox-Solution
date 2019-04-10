#include <iostream>
#include <vector>
#include <algorithm>


uint64_t MaxPairwiseProduct(const std::vector<int>& numbers) {

    std::vector<int> temp(numbers.begin(),numbers.end()); 
       
    sort(temp.begin(),temp.end());
	int maxsize = temp.size()-1;
    return (uint64_t) temp[maxsize] * temp[maxsize-1];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    
    uint64_t result = MaxPairwiseProduct(numbers);
    std::cout << static_cast<uint64_t> (result) << "\n";
    return 0;
}
