#include <list>
#include <string>
#include <tuple>
#include <vector>
#include <utility>

class Day5
{
public:
	Day5() {};

	void ReadFile(const std::string& a_file);

	void MoveCrates();
	void MoveCrates9001();
	std::string GetTopCrates() const;

	

private:
	void MoveCrates(const int count, const int fromStack, const int toStack);
	void MoveCrates9001(const std::tuple<int, int, int>& args);
	std::vector<std::list<char> > m_stacks;
	std::list<std::string> m_inputInstructions;
};