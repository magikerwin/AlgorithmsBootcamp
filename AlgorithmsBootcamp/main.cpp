#include <iostream>
//#include "Algorithms-Recursion/recursion.h"
//#include "Algorithms-Recursion/factorial.h"
//#include "Algorithms-Recursion/fibonacci.h"
//#include "Algorithms-Recursion/binarySearch.h"
//#include "Algorithms-Recursion/towerHanoi.h"
//#include "Algorithms-Backtracking/n-queens.h"
#include "Algorithms-Backtracking/graphColoring.h"


int main() {
    const std::vector<std::vector<int>> graphMatrix = {
        {0,1,0,1,0},
        {1,0,1,1,0},
        {0,1,0,1,0},
        {1,1,1,0,1},
        {0,0,0,1,0}
    };
    constexpr int numOfColors = 3;

    graphColoring::GraphColoringProblem problem(graphMatrix, numOfColors);
    problem();

    std::system("pause");
    return 0;

}