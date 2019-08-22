#pragma once

#include <iostream>
#include <vector>

namespace graphColoring {
class GraphColoringProblem {
    std::vector<std::vector<int>> graphMatrix;
    int numOfColors;
    std::vector<int> colors;

  public:
    GraphColoringProblem(const std::vector<std::vector<int>> &graph, int _numOfColors)
        : graphMatrix(graph)
        , numOfColors(_numOfColors) {
        colors.resize(graphMatrix.size());
    }

    // solve the coloring problem
    void operator()() {
        if (solve(0))
            showResult();
        else
            std::cout << "No solution with the given parameters" << std::endl;
    }

  private:
    // function to assign colors recursively
    bool solve(size_t nodeIndex) {
        if (nodeIndex == graphMatrix.size())
            return true;

        // try all colors (every color has an index)
        for (int colorIndex = 1; colorIndex <= numOfColors; colorIndex++) {
            if (isColorValid(nodeIndex, colorIndex)) {
                colors[nodeIndex] = colorIndex;
                // try to find the color for the next node
                if (solve(nodeIndex + 1))
                    return true;
            }
        }
        // backtrack: maybe we have to change the color of the previous node
        return false;
    }

    // function to check if it's valid to allot that color to vertex
    bool isColorValid(size_t nodeIndex, size_t colorIndex) {
        for (size_t i = 0; i < graphMatrix.size(); i++) {
            // check adjacent nodes (where matrix value is 1) AND whether they have the same color or not
            if (graphMatrix[nodeIndex][i] == 1 && colorIndex == colors[i]) {
                return false;
            }
        }
        return true;
    }

    void showResult() {
        for (size_t i = 0; i < graphMatrix.size(); i++) {
            std::cout << "Node " << (i + 1) << " has color index: " << colors[i] << std::endl;
        }
        std::cout << std::endl;
    }
};
}

// [sample.cpp]
// const std::vector<std::vector<int>> graphMatrix = {
//   {0,1,0,1,0},
//   {1,0,1,1,0},
//   {0,1,0,1,0},
//   {1,1,1,0,1},
//   {0,0,0,1,0}
// };
// constexpr int numOfColors = 3;
// graphColoring::GraphColoringProblem problem(graphMatrix, numOfColors);
// problem();