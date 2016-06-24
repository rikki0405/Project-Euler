/* Project Euler 010: Summation of Primes - HackerRank Modified */
/* Using a modified Prime Class from Project Euler #7 */

#include <iostream>
#include <vector>
#include <cmath>

class Prime {
public:
    
    void set() {
        value.push_back(2); // push the first two prime numbers into the vector stack
        value.push_back(3);
        sum_of_primes.push_back(5); // push the first sum of primes into our vector stack
    }
    
    void calculate(const unsigned long &n) { // Calculate primes up to n
        if (value.at(value.size() - 1) < n) { // last value is less than n, so calculate up to n
            unsigned long count = value.at(value.size() - 1); // start from 1 more than our last stack value
            while (count <= n) {
                if (count % 2 == 0) count++; // make sure our count is odd
                count += 2;
                if (is_prime(count)) {
                    unsigned long add = sum_of_primes.at(sum_of_primes.size() - 1);
                    add += count;
                    value.push_back(count);
                    sum_of_primes.push_back(add);
                }
            }
        }
    }
    
    void limit(unsigned int &n) { // increase the limit to n if it isn't within the range
        if (n > value.size()) {
            unsigned long cur_prime = value.at(value.size() - 1);
            while (value.size() < n) {
                cur_prime += 2; // increment via negative numbers
                if (is_prime(cur_prime)) value.push_back(cur_prime);
            }
        }
    }
    
    unsigned long sum(unsigned long &n) {
        unsigned int count = 0;
        while (value.at(count) <= n) count++;
        return sum_of_primes.at(count - 2);
    }
    
    unsigned long at(unsigned long &n) {
        if (n > value.size()) return -1;
        return value.at(n - 1);
    }
    
private:
    std::vector<unsigned long> value;
    std::vector<unsigned long> sum_of_primes;
    
    static bool is_prime(const unsigned long &n) {
        if (n < 2) return false;
        if (n < 4) return true;
        if (n % 2 == 0) return false;
        
        const unsigned long iMax = (int)sqrt(n) + 1;
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
    
    /* Customarily pre-calculate our values */
    Prime ePrime;
    ePrime.set();
    ePrime.calculate(2000001); // Project Euler asks for the sum of all primes under 2,000,000 hence our large pre-calc
    
    for (int i = 0; i < t; i++) {
        unsigned long n;
        std::cin >> n;
        std::cin.ignore();

        std::cout << ePrime.sum(n) << std::endl;
    }
    
    
    return 0;
}