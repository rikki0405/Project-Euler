/* Project Euler 003: Largest Prime Factor - HackerRank Modified */
#include <iostream>
#include <cmath>        // sqrt()

static unsigned long factor(const unsigned long &n) {
    unsigned long _n = n;
    while (_n % 2 == 0) _n /= 2;
    
    if (_n == 1) return 2;
    
    unsigned long i;
    for (i = 3; i <= sqrt(_n); i += 2) {
        if (_n % i == 0) {
            _n /= i;
            i = 1;
        }
    }
    if (_n > 2) return _n;
    return _n - 2;
}

int main() {
    
    int t;
    std::cin >> t;
    std::cin.ignore();
    
    for (int i = 0; i < t; i++) {
        long check;
        std::cin >> check;
        std::cin.ignore();
        std::cout << factor(check) << std::endl;
    }
    
    return 0;
}
