#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>

using namespace std;

bool file(string failas, vector<string>& data)
{
	ifstream in(failas.c_str());

	if (!in)
	{
		cout << "Tokio failo nera!" << endl;
		return false;
	}

	std::string line;
	while (getline(in, line))
	{
		data.push_back(line);
	}

	in.close();
	return true;
}

int main()
{
	vector<string> data;

	ifstream input("input.txt");
	bool result = file("input.txt", data);

	stringstream text;
	string base;

	base = "E145FF0BE9199C41D2FC0142ABC96B3D7E01D171CB2CC8DCD423CA8D71B52F37";

	for (auto& line : data)
	{
		text << line; 
	}
	
	cout << "Pradinis tekstas: " << text.str() << endl;

	string s = text.str();
	int temp = 0;

	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
			temp = int(base[i]);
			if (temp > 100) temp -= int(s[j]);
			else temp += int(s[j]);
			base[i] = char(temp);
		}

	}

	cout << endl << "after: " << base << endl;
}