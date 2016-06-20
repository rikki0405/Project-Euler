/* Project Euler 007: 10,001st Prime - HackerRank Modified */
/* Class Based approach */

#include <iostream>
#include <vector>
#include <cmath>

class Prime {
public:
    
    void set() {
        value.push_back(2); // push the first two prime numbers into the vector stack
        value.push_back(3);
    }
    
    void limit(unsigned int &n) { // increase the limit to n if it isn't within the range
        if (n > value.size()) {
            
            /* new value is greater than current generated primes, so let's generate new primes */
            unsigned int cur_prime = value.at(value.size() - 1);
            
            while (value.size() < n) {
                cur_prime += 2; // increment via negative numbers
                if (is_prime(cur_prime)) value.push_back(cur_prime);
            }
            
        }
    }
    
    unsigned int at(unsigned int &n) {
        if (n > value.size()) return -1;
        return value.at(n - 1);
    }
    
private:
    std::vector<unsigned int> value;
    
    static bool is_prime(const unsigned int &n) {
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

};

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    
    Prime ePrime;
    ePrime.set();
    
    for (int i = 0; i < t; i++) {
        unsigned int n;
        std::cin >> n;
        std::cin.ignore();
        
        /* limit to check if our stack is big enough */
        ePrime.limit(n);
        std::cout << ePrime.at(n) << std::endl;
    }
    
    
    return 0;
}