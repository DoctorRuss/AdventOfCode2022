// AoC2022.cpp : Defines the entry point for the application.
//

#include "AoC2022.h"
#include "Day1.hpp"
#include "Day2.hpp"
#include "Day3.hpp"
#include "Day4.hpp"
#include "Day5.hpp"
#include "Day6.hpp"
#include "Day7.hpp"
#include "Day8.hpp"
#include "Day9.hpp"
#include "Day10.hpp"

int main()
{
    /*
    {
        Day1 day;
        day.ReadFile("C:/r_mills/tinkering/AoC/2022/day1/input.txt");
        std::cout << "Top elf is carrying " << day.SumOfElements(1) << " calories." << std::endl;
        std::cout << "Top three elves are carrying " << day.SumOfElements(3) << " calories." << std::endl;
    }
    {
        Day2 day2;
        day2.ReadFile("C:/r_mills/tinkering/AoC/2022/day2/input.txt");
        std::cout << "Following the first strategy gives " << day2.TopScore() << std::endl;
        std::cout << "Following the second strategy gives " << day2.PredictedOutput() << std::endl;
    }
    {
        Day3 day3;
        day3.ReadFile("C:/r_mills/tinkering/AoC/2022/day3/input.txt");
        std::cout << "Full score is " << day3.ScoreItems() << std::endl;;
        std::cout << "Group score is " << day3.FindGroup() << std::endl;;
    }
    {
        Day4 day4;
        day4.ReadFile("C:/r_mills/tinkering/AoC/2022/day4/input.txt");
        std::cout << "These elves overlap: " << day4.OverlapCount() << std::endl;
        std::cout << "These elves intersect: " << day4.IntersectCount() << std::endl;
    }
    {
        Day5 day5;
        day5.ReadFile("C:/r_mills/tinkering/AoC/2022/day5/input.txt");
        day5.MoveCrates();
        std::cout << "Top Crates are: " << day5.GetTopCrates() << std::endl;
    }
    {
        Day5 day5;
        day5.ReadFile("C:/r_mills/tinkering/AoC/2022/day5/input.txt");
        day5.MoveCrates9001();
        std::cout << "Top Crates are: " << day5.GetTopCrates() << std::endl;
    }
    {
        Day6 day6;
        day6.ReadFile("C:/r_mills/tinkering/AoC/2022/day6/input.txt");
        std::cout << "Markers found after " << day6.GetMarkerCount() << std::endl;
        std::cout << "Message found after " << day6.GetMessageCount() << std::endl;
    }*/
    {
        Day7 day;
        day.ReadFile("C:/r_mills/tinkering/AoC/2022/day7/input.txt");
    }
    {
        Day8 day;
        day.ReadFile("C:/r_mills/tinkering/AoC/2022/day8/input.txt");
        std::cout << "There are " << day.VisibleTreeCount() << " visible trees." << std::endl;
    }
    {
        Day9 day;
        day.ReadFile("C:/r_mills/tinkering/AoC/2022/day9/input.txt");
        //std::cout << "There are " << day.VisibleTreeCount() << " visible trees." << std::endl;
    }
    {
        Day10 day;
        day.ReadFile("C:/r_mills/tinkering/AoC/2022/day10/input.txt");
		
        std::cout << "Sum of strengths is " << day.RunOperationSeriesToValue(20) + day.RunOperationSeriesToValue(60) +
            day.RunOperationSeriesToValue(100) + day.RunOperationSeriesToValue(140) +
            day.RunOperationSeriesToValue(180) + day.RunOperationSeriesToValue(220)
            << std::endl;
    }
    return 0;
}
