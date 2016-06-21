/* Project Euler 003: Largest Prime Factor - HackerRank Modified - Yesh_02 Approach */
#include <iostream>
#include <cmath>

long factorize(const long &n) {
    
    /* Step 1: if the given N is even, repeatedly divide by 2 */
    long factor_n = n;
    while (factor_n % 2 == 0) { factor_n = factor_n / 2; }
    
    /* Step 2: if N = 1, return 2 */
    if (factor_n == 1) { return 2; }
    
    /* Step 3: start with i=3, and check if the N is divisible by i. Increment i by 2. Run loop till sqrt of N */
    long i = 3;
    while (i != sqrt(factor_n)) {
        if (n % i == 0) {
            factor_n = n;
            break;
        } else {
            i = i + 2;
        }
    }
    
    /* Step 3: if N > 2, return N. Else return i */
    if (factor_n > 2) { return factor_n; }
    return i;
}

int main() {
    
    int n;
    std::cin >> n;
    std::cin.ignore();
    
    for (int i = 0; i < n; i++) {
        long check;
        std::cin >> check;
        std::cin.ignore();
        std::cout << factorize(n) << std::endl;
    }
    
    return 0;
}
