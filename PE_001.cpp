/* Project Euler 001: Multiples of 3 and 5  
   HackerRank Modified: Test Cases and Custom Input */

#include <iostream>
#include <iomanip>

int main() {
    
    /* Number of test cases */
    int t = 0;
    std::cin >> t;
    std::cin.ignore();
    
    for (int i = 0; i < t; i++) {
        
        long sum = 0.0;
        long n = 0;
        std::cin >> n;
        std::cin.ignore();
        
        /* n / 2 (2a + (n - 1) d) <- summation formula */
        
        /* Add the numbers divisible by 3 */
        long double max = (n - 1) / 3;
        sum = sum + ((max / 2) * ( (2 * 3) + ((max - 1) * 3) ) );
        
        /* Add the numbers divisible by 5 */
        max = (n - 1) / 5;
        sum = sum + ((max / 2) * ( (2 * 5) + ((max - 1) * 5) ) );
        
        /* Minus the numbers divisible by 15 (remove doubles) */
        if (n > 15) {
            max = (n - 1) / 15;
            sum = sum - ((max / 2) * ( (2 * 15) + ((max - 1) * 15) ) );
        }
        
        std::cout << sum << std::endl;
    }
    
    return 0;
}

