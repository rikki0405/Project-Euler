/* Project Euler 004: Highest Palindrome Product - HackerRank Modified */

#include <iostream>
#include <vector>
#include <algorithm>

static unsigned int int_reverse(const unsigned int &n) {
    int num = n, rev = 0;
    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num = num / 10;
    }
    return rev;
}

static bool is_palindrome(const unsigned int &n) {
    if (n == int_reverse(n)) return true;
    return false;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    
    /* Push all 3-digit-multiple Palindromes into our vector */
    std::vector<int> palindromes;
    
    for (int x = 100; x < 999; x++) {
        for (int y = x + 1; y < 999; y++) {
            int prod = x * y;
            if (prod % 11 == 0)  // multiple of 11 are palindrome numbers, ignore others
                if (is_palindrome(prod)) palindromes.push_back(prod);
        }
    }
    
    /* Sort our Vector and Erase duplicates */
    std::sort(palindromes.begin(), palindromes.end());
    palindromes.erase(std::unique(palindromes.begin(), palindromes.end()), palindromes.end());
    
    for (int i = 0; i < t; i++) {
        int n, x = 0;
        std::cin >> n;
        std::cin.ignore();
        
        /* Search our Vector and output */
        while (n > palindromes.at(x)) x++;
        std::cout << palindromes.at(x - 1) << std::endl;
    }
    
    
    return 0;
}