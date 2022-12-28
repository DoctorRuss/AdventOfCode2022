#include "Day6.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <list>

void
Day6::ReadFile(const std::string& a_file)
{
    std::ifstream filestream(a_file);
    std::getline(filestream, m_datastream);
}

bool
Day6::AreAllCharsTheSame(const int offset, const int a_count) const
{
    // find first place
    auto firstIter = m_datastream.begin();
    std::advance(firstIter, offset);

    // check remaining
    for (int i = 0; i < a_count; i++) {
        auto thisFirst = firstIter;
        std::advance(thisFirst, i);
        auto secondIter = thisFirst;
        for (int j = i + 1; j < a_count; j++) {
            secondIter = std::next(secondIter);
            if (*thisFirst == *secondIter) return false;
        }
    }
    return true;
}

int
Day6::FindRepeats(const int a_count) const
{
    for (int i = 0; i < m_datastream.size() - a_count; i++)
    {
        if (AreAllCharsTheSame(i, a_count)) return i + a_count;
    }
    return m_datastream.size();
}

int
Day6::GetMarkerCount() const
{
    return FindRepeats(4);
}

int
Day6::GetMessageCount() const
{
    return FindRepeats(14);
}