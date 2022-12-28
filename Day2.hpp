#include <string>
#include <vector>


class Day2
{
public:
	Day2() {};

	void ReadFile(const std::string& a_file);
	int TopScore() const;
	int PredictedOutput() const;
private:
	std::vector<std::pair<char, char> > m_scores;
};