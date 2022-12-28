#include <string>
#include <vector>

class Day1
{
public:
	Day1() {};

	void ReadFile(const std::string& a_file);
	int SumOfElements(const int a_count) const;
private:
	std::vector<int> m_elves;
};
