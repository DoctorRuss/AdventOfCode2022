#include "Day2.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <vector>

enum class RockPaperScissors : int
{
    Rock,
    Paper,
    Scissors
};

int 
ScoreRPS(RockPaperScissors rps)
{
    if (rps == RockPaperScissors::Rock) return 1;
    if (rps == RockPaperScissors::Paper) return 2;
    if (rps == RockPaperScissors::Scissors) return 3;
}


RockPaperScissors
ConvertToRPS(const char a_input)
{
    if (a_input == 'X' || a_input == 'A') return RockPaperScissors::Rock;
    if (a_input == 'Y' || a_input == 'B') return RockPaperScissors::Paper;
    if (a_input == 'Z' || a_input == 'C') return RockPaperScissors::Scissors;
}

int 
ScoreRPS(const RockPaperScissors first, const RockPaperScissors second)
{
    if (first == second) return 3;
    if (first == RockPaperScissors::Rock && second == RockPaperScissors::Paper) return 6;
    if (first == RockPaperScissors::Scissors && second == RockPaperScissors::Rock) return 6;
    if (first == RockPaperScissors::Paper && second == RockPaperScissors::Scissors) return 6;
    return 0;

}

RockPaperScissors
GetPredictedOutput(const RockPaperScissors them, const char result)
{
    // draw
    if (result == 'Y') return them;
    // lose
    if (result == 'X') {
        if (them == RockPaperScissors::Rock) return RockPaperScissors::Scissors;
        if (them == RockPaperScissors::Scissors) return RockPaperScissors::Paper;
        else return RockPaperScissors::Rock;
    }
    else // win
    {
        if (them == RockPaperScissors::Paper) return RockPaperScissors::Scissors;
        if (them == RockPaperScissors::Rock) return RockPaperScissors::Paper;
        else return RockPaperScissors::Rock;
    }
}
int
ScorePair(const RockPaperScissors them, const RockPaperScissors us)
{
    return ScoreRPS(us) + ScoreRPS(them, us);
}

int
PredictPair(const char them, const char outcome)
{
    RockPaperScissors rps_them = ConvertToRPS(them);
    RockPaperScissors rps_us = GetPredictedOutput(rps_them, outcome);
    return ScorePair(rps_them, rps_us);
}

int
process_pair(const int a_sum, const std::pair<char, char> themAndUs)
{
    return a_sum + ScorePair(ConvertToRPS(themAndUs.first), ConvertToRPS(themAndUs.second));
}

int
predict_pair(const int a_sum, const std::pair<char, char> themAndUs)
{
    return a_sum + PredictPair(themAndUs.first, themAndUs.second);
}

void 
Day2::ReadFile(const std::string& a_file)
{
    std::ifstream filestream(a_file);

    char a, b;
    while (filestream >> a >> b)
    {
        m_scores.push_back(std::make_pair(a, b));
    }
}

int
Day2::TopScore() const
{
    return std::accumulate(m_scores.begin(), m_scores.end(), 0, process_pair);
};

int
Day2::PredictedOutput() const
{
    return std::accumulate(m_scores.begin(), m_scores.end(), 0, predict_pair);
};