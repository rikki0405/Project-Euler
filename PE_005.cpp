/* Project Euler 005: Smallest Multiple */
/* HackerRank modified (asks for test cases, and number multiple) */

#include <iostream>
#include <cmath>

static bool IsPrime(const unsigned int &n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0) return false;
    
    const unsigned int iMax = (int)sqrt(n) + 1;
    unsigned int i;
    for (i = 3; i <= iMax; i += 2)
        if (n % i == 0)
            return false;
    
    return true;
}

bool factor_check(const int &value, const int &n) {
    
    for (int i = 2; i < n; i++) { if (value % i != 0) return false; }
    return true;
}

int brute_calc(const int &n) {
    
    /* First, find all the primes up to n */
    int primes = 1;
    for (int i = 1; i < n; i++) { if (IsPrime(i)) primes = primes * i; }
    
    /* Next, set the last position as zero, 20 divisible */
    while (primes % n != 0) { primes++; }
    
    /* Now, brute calculate until we are satisfied */
    while (!factor_check(primes, n)) { primes = primes + n; }
    
    return primes;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::cin.ignore();
        std::cout << brute_calc(n) << std::endl;
    }
    
    return 0;
}