/*
	Guilherme Resende - 2018
	This is Boyer-Moore-Horspool Algorithm for finding a 
	matching on a string. The code below works in cases where 
	both, the string and the pattern, are composed only by lowercase 
	letters.
	The algorithm return wheter there is a matching or not with time 
	complexity of O(mn) where the 'm' is pattern's length and 'n' is 
	the length of the text.
*/
using namespace std;

#define SIZE 30
int badMatch[SIZE];

void createBadMatch(string pattern){
	for(int i = 0; i < SIZE; i++)
		badMatch[i] = pattern.size();

	for(int i = 0; i < pattern.size()-1; ++i){
		char c = pattern[i];
		badMatch[c-'a'] = min(badMatch[c-'a'], ((int)pattern.size()-i-1));
	}
}

bool BMH(string pattern, string s){
	int index = pattern.size()-1, count = 0;

	for(int sIndex = index, pIndex = index; sIndex < s.size(); ){
		char sChar = s[sIndex], pChar = pattern[pIndex];
		if(sChar == pChar)
			count += 1, sIndex -= 1, pIndex -= 1;
		else{
			count = 0;
			index += badMatch[s[index]-'a'];
			sIndex = index;
			pIndex = pattern.size()-1;
		}

		if(count == pattern.size())
			break;
	}

	return (count == pattern.size()) ? true : false;
}