#include "Day10.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <vector>


void 
Day10::ReadFile(const std::string& a_file)
{
    std::ifstream instream(a_file);

    std::string line;

    while (std::getline(instream, line))
    {
        m_operations.push_back(line);
    }
}

void
Day10::Run() const {
}

std::pair<int, int> 
Day10::ParseOperation(const std::string& a_operation) const
{
    if (a_operation == "noop")
        return std::pair<int, int>{1,0};
    std::istringstream iss(a_operation);
    std::string opname;
    int a(0);
    if ((iss >> opname >> a) && (opname == "addx")) {
        return std::pair<int, int>{2, a};
    }
    return std::pair<int, int>{0, 0};
}

std::pair<int, int>
Day10::RunOperation(const std::string& a_operation, const std::pair<int, int>& a_cycleAndStrength) const
{
    std::pair<int, int> thisOp = ParseOperation(a_operation);
    return std::make_pair(a_cycleAndStrength.first + thisOp.first, a_cycleAndStrength.second + thisOp.second);
}

std::pair<int, int>
Day10::RunOperationSeries(const std::vector<std::string>& a_operations, const std::pair<int, int>& a_cycleAndStrength) const
{
    std::pair<int, int> state = a_cycleAndStrength;

    for (const std::string& a_operation : a_operations) {
        state = RunOperation(a_operation, state);
    };
    return state;
}

int
Day10::RunOperationSeriesToValue(const int a_limit) const
{
    std::pair<int, int> state{ 0,1 };

    for (const std::string& a_operation : m_operations) {
        std::pair<int, int> thisOp = ParseOperation(a_operation);
        if (state.first + thisOp.first >= a_limit) break;
        state = RunOperation(a_operation, state);
    };
    return state.second * a_limit;
}