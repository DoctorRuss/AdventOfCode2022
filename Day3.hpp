#include <string>
#include <vector>
#include <utility>

class Day3
{
public:
	Day3() {};

	void ReadFile(const std::string& a_file);

	std::vector<std::pair<std::string, std::string> > CompartmentaliseRucksacks()const;
	std::vector<std::string> FindItems() const;
	int ScoreItems() const;
	int FindGroup() const;

	std::vector<std::string> FindGroups() const;

private:
	std::vector<std::string> m_rucksacks;
};