/* Project Euler #3: Largest Prime Factor  
   NOTE: Needs optimizing to reduce calculation runtime,  but it does correctly function */
   
#include <iostream>
#include <cmath>

bool IsPrime(const unsigned int &n) {
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

bool IsDivisible(const unsigned int &n, const unsigned int &orig) {
    if (orig % n == 0) { return true; }
    return false;
}

bool Check(const unsigned int &n, const unsigned int &orig) {
    if (IsDivisible(n, orig)) {
        if (IsPrime(n)) {
            return true;
        }
    }
    return false;
}

void largest_prime(const unsigned int &n) {
    
    unsigned int temp = n;
    while (!Check(temp, n)) { if (temp > n) break; temp--; } // decrementing 1 each loop results in long runtimes in large numbers
    std::cout << temp << std::endl;                          // will need to optimize this smarter
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    
    for (int i = 0; i < n; i++) {
        unsigned int x;
        std::cin >> x;
        std::cin.ignore();
        
        largest_prime(x);
    }
    return 0;
}
