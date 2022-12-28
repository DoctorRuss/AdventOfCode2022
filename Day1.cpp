#include "Day1.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <vector>


void 
Day1::ReadFile(const std::string& a_file)
{
    std::ifstream instream(a_file);

    std::string line;
    
    int thisElf(0);
    while (std::getline(instream, line))
    {
        std::istringstream iss(line);
        int a(0);
        if ((iss >> a)) {
            thisElf += a;
        }
        else {
            m_elves.push_back(thisElf); thisElf = 0;
        }
    }
    std::sort(m_elves.begin(), m_elves.end(), [](int a, int b) {return a > b; });
}

int
Day1::SumOfElements(const int a_count) const {
    return std::accumulate(m_elves.begin(), m_elves.begin() + a_count, 0);
}