#include "Day4.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <vector>

bool isInRange(const int a_test, const int a_lower, const int a_upper)
{
    return a_test >= a_lower && a_test <= a_upper;
}

Range::Range(const std::string& a_string)
    : m_lowerBound(0), m_upperBound(0)
{
    size_t dashSep = a_string.find('-');
    m_lowerBound = std::stoi(a_string.substr(0, dashSep));
    m_upperBound = std::stoi(a_string.substr(dashSep+1));
}

bool
Range::Overlaps(const Range& a_range) const
{
    bool otherInThis = isInRange(a_range.m_lowerBound, m_lowerBound, m_upperBound) && isInRange(a_range.m_upperBound, m_lowerBound, m_upperBound);
    bool thisInOther = isInRange(m_lowerBound, a_range.m_lowerBound, a_range.m_upperBound) && isInRange(m_upperBound, a_range.m_lowerBound, a_range.m_upperBound);
    return otherInThis || thisInOther;
}

bool
Range::Intersects(const Range& a_range) const
{
    bool otherInThis = isInRange(a_range.m_lowerBound, m_lowerBound, m_upperBound) || isInRange(a_range.m_upperBound, m_lowerBound, m_upperBound);
    bool thisInOther = isInRange(m_lowerBound, a_range.m_lowerBound, a_range.m_upperBound) || isInRange(m_upperBound, a_range.m_lowerBound, a_range.m_upperBound);
    return otherInThis || thisInOther;
}

void
Day4::ReadFile(const std::string& a_file)
{
    std::ifstream filestream(a_file);

    std::string line;
    while (std::getline(filestream, line))
    {
        size_t commaSep = line.find(',');
        m_ranges.push_back(std::make_pair(Range(line.substr(0, commaSep)), Range(line.substr(commaSep + 1))));
    }
}

int
Day4::OverlapCount() const
{
    return std::count_if(m_ranges.cbegin(), 
        m_ranges.cend(), 
        [](const std::pair<Range, Range> pair) {return pair.first.Overlaps(pair.second); });
}
int
Day4::IntersectCount() const
{
    return std::count_if(m_ranges.cbegin(),
        m_ranges.cend(),
        [](const std::pair<Range, Range> pair) {return pair.first.Intersects(pair.second); });
}

