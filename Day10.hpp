#include <string>
#include <utility>
#include <vector>

class Day10
{
public:
	Day10() {};

	void ReadFile(const std::string& a_file);
	void Run() const;
	std::pair<int, int> ParseOperation(const std::string& a_operation) const;
	std::pair<int, int> RunOperation(const std::string& a_operation, const std::pair<int, int>& a_cycleAndStrength) const;
	std::pair<int, int> RunOperationSeries(const std::vector<std::string>& a_operations, const std::pair<int, int>& a_cycleAndStrength) const;
	int RunOperationSeriesToValue(const int a_limit) const;
private:
	std::vector<std::string> m_operations;
};
