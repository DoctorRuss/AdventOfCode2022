#include <list>
#include <string>
#include <tuple>
#include <vector>
#include <utility>

class Day6
{
public:
	Day6() {};

	void ReadFile(const std::string& a_file);

	int GetMarkerCount() const;
	int GetMessageCount() const;


private:
	bool AreAllCharsTheSame(const int offset, const int a_count) const;
	int FindRepeats(const int a_count) const;
	std::string m_datastream;
};