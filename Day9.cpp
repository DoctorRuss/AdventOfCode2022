#include "Day9.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <vector>

void
Day9::ReadFile(const std::string& a_file)
{
    std::ifstream filestream(a_file);

    std::string line;
    
	std::tuple<int, int> head{0,0};
	std::tuple<int, int> tail{0,0};
	std::set<std::tuple<int, int> > locations;
	locations.insert({0,0});
    while (std::getline(filestream, line))
    {
        // parse input file to find trees
        char direction;
		int spaces, prevXH, prevXT, prevYH, prevYT;
		//std::cout << line << std::endl;
        std::istringstream iss(line);
        iss >> direction >> spaces;
        std::tie(prevXH, prevYH) = head;
        std::tie(prevXT, prevYT) = tail;
		int tailXOffset(prevXH - prevXT);
		int tailYOffset(prevYH - prevYT);
		int tailSpaces(spaces);
		if (direction == 'R') {
			if (tailXOffset == 0) tailSpaces--;
			if (tailXOffset == -1)
			{
				tailSpaces-= 2;
				tailSpaces = std::max(0, tailSpaces);
			}
			
			if (tailYOffset != 0 && tailSpaces > 0) { prevYT = prevYH;}
			for (int t = 1; t <= tailSpaces; t++)
			{
                locations.insert({ prevXT + t, prevYT });
			}
		    prevXH += spaces;
			prevXT += tailSpaces;
		} else if (direction == 'L') {
			if (tailXOffset == 0) tailSpaces--;
			if (tailXOffset == 1)
			{
				tailSpaces-= 2;
				tailSpaces = std::max(0, tailSpaces);
			}
			
			if (tailYOffset != 0 && tailSpaces > 0) { prevYT = prevYH;}
			for (int t = 1; t <= tailSpaces; t++)
			{
                locations.insert({ prevXT - t, prevYT });
			}
		    prevXH -= spaces;
			prevXT -= tailSpaces;
		} else if (direction == 'U') {
			if (tailYOffset == 0) tailSpaces--;
			if (tailYOffset == -1)
			{
				tailSpaces-= 2;
				tailSpaces = std::max(0, tailSpaces);
			}
			
			if (tailXOffset != 0 && tailSpaces > 0) { prevXT = prevXH;}
			for (int t = 1; t <= tailSpaces; t++)
			{
                locations.insert({ prevXT , prevYT +t});
			}
			prevYH += spaces;
			prevYT += tailSpaces;
		} else if (direction == 'D') {
			if (tailYOffset == 0) tailSpaces--;
			if (tailYOffset == 1)
			{
				tailSpaces-= 2;
				tailSpaces = std::max(0, tailSpaces);
			}
			if (tailXOffset != 0 && tailSpaces > 0) { prevXT = prevXH;}
			for (int t = 1; t <= tailSpaces; t++)
			{
                locations.insert({ prevXT , prevYT -t});
			}
			prevYH -= spaces;
			prevYT -= tailSpaces;
		} 
		head = {prevXH, prevYH};
		tail = {prevXT, prevYT};
		//std::cout << "HEAD: " << prevXH << ", " << prevYH << std::endl;
		//std::cout << "TAIL: " << prevXT << ", " << prevYT << std::endl;
		for (auto iter = locations.begin(); iter != locations.end(); iter++)
		{
			int xLoc, yLoc;
			std::tie(xLoc, yLoc) = *iter;
			//std::cout << "LOCATION: " << xLoc << ", " << yLoc << std::endl;	
		}
    }
	std::cout << "Location count is " << locations.size() << std::endl;
}

