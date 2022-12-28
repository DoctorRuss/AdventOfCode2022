#include <list>
#include <string>
#include <tuple>
#include <vector>
#include <utility>

class Day8
{
public:
	Day8() {};

	void ReadFile(const std::string& a_file);
	int VisibleTreeCount() const;
	int MaximumTreeScore() const;
	
private:
	std::vector<std::vector<int> > m_forest;
};