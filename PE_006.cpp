/* Project Euler 006: Sum Square Difference 
   HackerRank Modified: allow test cases and custom lengths */


#include <iostream>


long square_sums(const int &n) {
    long sum = 0;
    for (int i = 0; i < n + 1; i++) { sum = sum + (i * i); }
    return sum;
}

long sum_of_the_squares(const int &n) {
    long sum = 0;
    for (int i = 0; i < n + 1; i++) { sum = sum + i; }
    return sum * sum;
}

int main() {
    
    int t;
    std::cin >> t;
    std::cin.ignore();
    
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::cin.ignore();
        
        std::cout << sum_of_the_squares(n) - square_sums(n) << std::endl;
    }
    
    
    return 0;
}