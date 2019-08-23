#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {  
  std::string s;
  std::multimap<std::string, std::string> memo;

  while (std::cin >> s, s != "#") {
	std::string t{s};
	std::transform(s.begin(), s.end(), t.begin(), tolower);
	std::sort(t.begin(), t.end());
	memo.insert({t, s});
  }

  std::vector<std::string> ananagrams;

  for (auto& p : memo) {
	if (memo.count(p.first) == 1)
	  ananagrams.push_back(p.second);
  }

  std::sort(ananagrams.begin(), ananagrams.end());
  for (auto& an : ananagrams) {
	std::cout << an << '\n'; 
  }

  return 0;
}
