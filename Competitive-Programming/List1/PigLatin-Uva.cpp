#include <bits/stdc++.h>

using namespace std;

char vowels[] = {'a','A','e','E','i','I','o','O','u','U'};

bool isVowel(char c){
	for(int i = 0; i < 10; ++i)
		if(c == vowels[i])
			return true;
	return false;
}

bool isConsonant(char c){
	if(isalpha(c) and not(isVowel(c)))
		return true;
	return false;
}

int main(){
	string s;
	while(getline(cin, s)){
		bool begin=true, space=true, vowel=false, consonant=false;
		char printLater;

		for(int i = 0; i < s.size(); ++i){
			if(begin){
				space=true;
				begin=false;
				vowel=isVowel(s[i]);
				consonant=isConsonant(s[i]);

				if(consonant){
					printLater = s[i];
					continue;
				}
			}
			if(s[i] == ' ' or (not(isVowel(s[i])) and not(isConsonant(s[i])))){
				space=false;
				begin=true;

				if(vowel)
					printf("ay");
				else if(consonant)
					printf("%cay", printLater);
			}
			printf("%c", s[i]);
		}
		printf("\n");
	}

	return 0;
}