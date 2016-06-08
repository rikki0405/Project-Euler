/* Project Euler #2: Even Fibonacci Numbers  */

#include <iostream>

class Fibonacci {
public:
    
    /* Constructor */
    void Reset() {
        prev = 1;
        cur = 1;
        evens = 0; // count how many even fibonacci numbers we encounter
    }
    
    void Next() {
        long temp = prev + cur;
        prev = cur;
        cur = temp;
        even_check(cur);
    }
    
    long Count(const long &x) {
        /* Check if next fibonacci isn't greater than our x */
        while (x > (prev + cur)) { Next(); }
        return evens;
    }
    
private:
    void even_check(const long &no) { if (no % 2 == 0) { evens = evens + no; } }
    long prev, cur, evens;
};

int main() {

    int t;
    std::cin >> t;
    std::cin.ignore();
    Fibonacci newFib;
    
    for (int i = 0; i < t; i++) {
        long x;
        std::cin >> x;
        std::cin.ignore();
        
        newFib.Reset();
        std::cout << newFib.Count(x) << std::endl;
    }
    
    return 0;
}
