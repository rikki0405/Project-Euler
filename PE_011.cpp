/* Project Euler 011: Largest Product in a Grid - HackerRank Modified */

#include <iostream>

int main() {
    int n[20][20];
    unsigned int max = 0;
    
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            std::cin >> n[i][j];
    
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            
            if (x < 17) // Horizontal
                if (max < n[x][y] * n[x+1][y] * n[x+2][y] * n[x+3][y])
                    max = n[x][y] * n[x+1][y] * n[x+2][y] * n[x+3][y];
            
            if (y < 17) // Vertical
                if (max < n[x][y] * n[x][y+1] * n[x][y+2] * n[x][y+3])
                    max = n[x][y] * n[x][y+1] * n[x][y+2] * n[x][y+3];
            
            if (x < 17 && y < 17) { // Diagonals
                if (max < n[x][y+3] * n[x+1][y+2] * n[x+2][y+1] * n[x+3][y])
                    max = n[x][y+3] * n[x+1][y+2] * n[x+2][y+1] * n[x+3][y];
                if (max < n[x+3][y+3] * n[x+2][y+2] * n[x+1][y+1] * n[x][y])
                    max = n[x+3][y+3] * n[x+2][y+2] * n[x+1][y+1] * n[x][y];
            }
        }
    }
    std::cout << max << std::endl;
    
    return 0;
}