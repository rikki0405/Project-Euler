/* Project Euler 009: Special Pythagorean Triplet - HackerRank Modified */

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    
    for (int i = 0; i < t; i++) {
        int x;
        std::cin >> x;
        std::cin.ignore();
        
        int a = 0, b = 0, c = 0;
        int max = 0;
        bool found = false;
        for (a = 1; a < x / 3; a++) {
            b = ( (((x - a) * (x - a)) - (a*a)) / (2 * (x - a)) );
            c = x - b - a;
            if (((a*a)+(b*b)==(c*c) && b > 0 && c > 0 && (a * b * c > max))) {
                found = true;
                max = a * b * c;
            }
        }
        if (!found) {
            std::cout << "-1" << std::endl;
        } else {
            std::cout << max << std::endl;
        }
    }
    return 0;
}