#include "Day8.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <vector>

void
Day8::ReadFile(const std::string& a_file)
{
    std::ifstream filestream(a_file);

    std::string line;
    
    while (std::getline(filestream, line))
    {
        // parse input file to find trees
        std::vector<int> trees;
        std::transform(line.begin(), line.end(), std::back_inserter(trees), [](char c) {return c - '0'; });
		m_forest.push_back(trees);
    }
	
}

int
Day8::VisibleTreeCount() const
{
    // check for number of visible trees
    std::set<std::tuple<int, int> > visibleTrees;
    std::vector<int> northHeights(m_forest[0].size(), -1);
    for (int i = 0; i < m_forest.size(); i++)
    {
        std::vector<int> trees = m_forest[i];
        // check visibility from left
        int maxHeight(-1);
        for (int j = 0; j < trees.size(); j++) {
            if (trees[j] > maxHeight) {
                visibleTrees.insert({ i,j });
                maxHeight = trees[j];
            }
        // check visibility from north
            if (trees[j] > northHeights[j]) {
                visibleTrees.insert({ i,j });
                northHeights[j] = trees[j];
            }
        }
        // check visibility from right
        maxHeight = -1;
        for (int j = trees.size() - 1; j >= 0; j--) {
            if (trees[j] > maxHeight) {
                visibleTrees.insert({ i,j });
                maxHeight = trees[j];
            }
        }
    }
    std::vector<int> southHeights(m_forest[0].size(), -1);
    for (int i = m_forest.size() - 1; i >=0; i--)
    {
        std::vector<int> trees = m_forest[i];
        // check visibility from south
        for (int j = 0; j < trees.size(); j++) {
            // check visibility from north
            if (trees[j] > southHeights[j]) {
                visibleTrees.insert({ i,j });
                southHeights[j] = trees[j];
            }
        }
    }
    return visibleTrees.size();
}

int 
Day8::MaximumTreeScore() const
{
	std::map<std::tuple<int, int>, int > treeScores;
	return 0;
}