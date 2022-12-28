#include "Day3.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <vector>


void
Day3::ReadFile(const std::string& a_file)
{
    std::ifstream filestream(a_file);

    std::string line;
    while (std::getline(filestream, line))
    {
        m_rucksacks.push_back(line);
    }
}

std::pair<std::string, std::string>
Compartmentalise(const std::string& a_string)
{
    const std::size_t len = a_string.length();
    return std::make_pair(a_string.substr(0, len / 2), a_string.substr(len / 2));
}



std::string
FindItemString(const std::string& a_first, const std::string& a_second)
{
    std::string matches;
    for (const char c : a_first) {
        if (a_second.find_first_of(c) != std::string::npos) {
            matches += c;;
        }
    }
    return matches;
}

std::string
FindItem(const std::pair<std::string, std::string>& a_compartments)
{
    return FindItemString(a_compartments.first, a_compartments.second);
}

std::vector<std::pair<std::string, std::string> >
Day3::CompartmentaliseRucksacks() const
{
    std::vector<std::pair<std::string, std::string> > output;
    std::transform(m_rucksacks.begin(), m_rucksacks.end(), std::back_inserter(output), Compartmentalise);
    return output;
}

std::vector<std::string>
Day3::FindItems() const
{
    std::vector<std::string> output;
    std::vector<std::pair<std::string, std::string> > compartments = CompartmentaliseRucksacks();
    std::transform(compartments.begin(), compartments.end(), std::back_inserter(output), FindItem);
    return output;
}

int ScoreItem(const std::string& str)
{
    const char c = str[0];
    if (c >= 97 && c <= 122) return c - 96;
    if (c >= 65 && c <= 90) return c - 38;
    return 0;
}

int 
Day3::ScoreItems() const
{
    std::vector<std::string> items = FindItems();
    std::vector<int> scores;

    std::transform(items.begin(), items.end(), std::back_inserter(scores), ScoreItem);
    return std::accumulate(scores.cbegin(), scores.cend(), 0);
}

std::vector<std::string>
Day3::FindGroups() const
{

    std::vector<std::string> matches;
    for (std::vector<std::string>::const_iterator vec = m_rucksacks.begin(); vec < m_rucksacks.end(); vec += 3) {
        matches.push_back(FindItemString(FindItemString(*vec, *(vec + 1)), *(vec + 2)));
    }
    return matches;

}

int
Day3::FindGroup() const
{
    std::vector<std::string> matches = FindGroups();
    std::vector<int> scores;

    std::transform(matches.begin(), matches.end(), std::back_inserter(scores), ScoreItem);
    return std::accumulate(scores.cbegin(), scores.cend(), 0);
}