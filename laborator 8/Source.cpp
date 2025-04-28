#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Compare {
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2)
	{
		if (p1.second < p2.second)
			return true; 
		if (p1.second > p2.second)
			return false;
		if (p1.first > p2.first)
			return true;
		return false;
	}
};

bool separator(char c) {
	if (c == ' ' || c == ',' || c == '?' || c == '!' || c == '.')
		return true;
	return false;
}

int main() {
	string myString;
	ifstream myFile("input.txt");
	if (!myFile) {
		printf("error la deschideerea fisierului: input.txt");
		return 0;
	}
	if (!getline(myFile, myString)) {
		printf("error la citirea din fiseier: input.txt");
		return 0;
	}

	printf("Sirul de caractere citit este : % s\n", myString.c_str());

	for (int i = 0; i < myString.size(); i++)
		myString[i] = tolower(myString[i]);

	map<string, int> myMap;
	int pos = 0;
	while (pos < myString.size()) {
		while (pos < myString.size() && separator(myString[pos]))
			pos++;
		if (pos >= myString.size())
			break;
		int start = pos;
		while (pos < myString.size() && !separator(myString[pos]))
			pos++;
		string cuvant = myString.substr(start, pos - start);
		if (!cuvant.empty())
			myMap[cuvant]++;
	}


	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
	for (auto mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++)
		myQueue.push(pair<string, int>(mapIterator->first, mapIterator->second));
	
	while (!myQueue.empty())
	{
		printf("%s => %d\n", myQueue.top().first.c_str(), myQueue.top().second);
		myQueue.pop();
	}
}
