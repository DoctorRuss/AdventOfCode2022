#include <string>
#include <vector>
#include <utility>

class Range
{
public:
	Range(const std::string& a_input);

	bool Overlaps(const Range& a_other) const;
	bool Intersects(const Range& a_other) const;
private:
	int m_lowerBound;
	int m_upperBound;
};

class Day4
{
public:
	Day4() {};

	void ReadFile(const std::string& a_file);

	int OverlapCount() const;
	int IntersectCount() const;

private:
	std::vector<std::pair<Range, Range> > m_ranges;
};