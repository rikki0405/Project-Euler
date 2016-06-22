/* Project Euler 008: Largest Product in a Series - HackerRank Modified */

#include <iostream>
#include <vector>
#include <algorithm>

static int to_int(const std::string &s) {
    int _to_int;
    _to_int = std::stoi(s);
    return _to_int; }

static std::string sort(const std::string &s) {
    std::vector<char> sort;
    for (int i = 0; i < s.size(); i++) sort.push_back(s.at(i));
    std::sort(sort.begin(), sort.end());
    std::reverse(sort.begin(), sort.end());
    std::string rtn;
    for (int i = 0; i < s.size(); i++) {
        std::string temp;
        temp = sort.at(i);
        rtn.append(temp);
    }
    return rtn;
}

static int product(const int &a) {
    
    int rtn = 1;
    std::string s;
    s = std::to_string(a);
    
    for (int i = 0; i < s.size(); i++) {
        std::string temp;
        temp = s.at(i);
        rtn = rtn * to_int(temp);
    }
    
    return rtn;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    
    for (int i = 0; i < t; i++) { /* Array: max - k - 1, k */
        int n, k; // n: number size - k: series size
        std::cin >> n;
        std::cin >> k;
        std::cin.ignore();
        
        std::string numbers;
        std::cin >> numbers;
        std::cin.ignore();
        
        std::vector<int> series;
        series.push_back(0); // so we output 0 if we don't get a valid series
        std::string temp;
        bool contains_zero = false;
        for (int x = 0; x < numbers.size() - (k - 1); x++) {
            for (int y = x; y < x + k; y++) {
                if (numbers.at(y) == '0') contains_zero = true;
                std::string a;
                a = numbers.at(y);
                temp.append(a);
            }
            if (!contains_zero) {
                series.push_back(product(to_int(sort(temp))));
            }
            temp.clear();
            contains_zero = false;
        }
        
        // Sort vector then reverse
        std::sort(series.begin(), series.end());
        std::reverse(series.begin(), series.end());
        std::cout << series.at(0) << std::endl;
        
    }
    
    return 0;
}