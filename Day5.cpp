#include "Day5.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <tuple>
#include <vector>

void 
Day5::ReadFile(const std::string& a_file)
{

    std::ifstream filestream(a_file);
    std::string line;

    std::list<std::string> inputStacks;
    while (std::getline(filestream, line))
    {
        if (line == "")
            break;
        inputStacks.push_back(line);
        std::cout << line << std::endl;
    }

    // get number of stacks from last line
    std::string countLine = inputStacks.back();
    inputStacks.pop_back();
    size_t stackCount = std::stoull(countLine.substr(countLine.find_last_not_of(" ")));
    m_stacks.resize(stackCount);

    // split every four chars
    // pop onto front of the relevant stack
    while (!inputStacks.empty()) {
        std::string crateRow = inputStacks.back();
        inputStacks.pop_back();

        for (size_t i = 0; i < stackCount; i++)
        {
            size_t offset = 1 + i * 4;
            char crate = crateRow.at(offset);
            if (crate != ' ')
                m_stacks[i].push_front(crate);
        }
    }

    // save instructions
    while (std::getline(filestream, line))
    {
        m_inputInstructions.push_back(line);
    }
};

//Parse string of form
// move X from a to b
std::tuple<int, int, int>
ParseInstruction(const std::string& a_instruction)
{
    std::istringstream iss(a_instruction);
    std::string temp, count, from, to;
    iss >> temp >> count >> temp >> from >> temp >> to;
    return { std::stoi(count), std::stoi(from), std::stoi(to) };
}

void
Day5::MoveCrates()
{
    std::for_each(m_inputInstructions.begin(), m_inputInstructions.end(),
        [this](const std::string& a_instruction) {
            // move X from a to b
            std::tuple<int, int, int> args = ParseInstruction(a_instruction);
            int count, fromStack, toStack;
            std::tie(count, fromStack, toStack) = args;
            MoveCrates(count, fromStack, toStack);
        });
};

void
Day5::MoveCrates(const int count, const int fromStack, const int toStack)
{
    for (int i = 0; i < count; i++)
    {
        m_stacks[toStack - 1].push_front(m_stacks[fromStack - 1].front());
        m_stacks[fromStack - 1].pop_front();
    }
}

void
Day5::MoveCrates9001()
{
    std::for_each(m_inputInstructions.begin(), m_inputInstructions.end(),
        [this](const std::string& a_instruction) {
            MoveCrates9001(ParseInstruction(a_instruction));
        });
};

void
PushFromListToList(const int count, std::list<char>& from, std::list<char>& to)
{
    for (int i = 0; i < count; i++)
    {
        to.push_front(from.back());
        from.pop_back();
    }
}

void
Day5::MoveCrates9001(const std::tuple<int, int, int>& args)
{
    int count, fromStack, toStack;
    std::tie(count, fromStack, toStack) = args;

    std::list<char> temp;
    for (int i = 0; i < count; i++)
    {
        temp.push_back(m_stacks[fromStack - 1].front());
        m_stacks[fromStack - 1].pop_front();
    }
    PushFromListToList(count, temp, m_stacks[toStack - 1]);
}

std::string 
Day5::GetTopCrates() const 
{
    std::string output;
    std::transform(m_stacks.begin(), m_stacks.end(), std::back_inserter(output),
        [](const std::list<char>& a_list) {
            if (!a_list.empty()) return a_list.front();
        });
    return output;
};