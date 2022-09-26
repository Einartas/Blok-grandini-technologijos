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

	stringstream text, asc, ch;

	for (auto& line : data)
	{
		text << line;
	}
	
	cout << "Pradinis tekstas: " << text.str() << endl;

	string s = text.str();

	cout << "Ascii kodas: ";
	for (int i = 0; i < s.length(); i++)
	{
		cout << (int)s[i];
		asc << (int)s[i];
	}
	
	string a = asc.str();

	for (int i = 0; i < a.length() - 1; i++)
	{
		if (a[i] < 50) a[i + 1] = a[i + 1] + 23;
		else if (a[i] > 50) a[i + 1] = a[i + 1] - 23;
		ch << a[i];
	}
	ch << a[a.length()];

	cout << endl << "Po keitimo: " << ch.str() << endl;

	string p = ch.str();
	
	cout << "Ascii po keitimo: ";
	for (int i = 0; i < p.length(); i++)
	{
		cout << (int)p[i];
	}

	cout << endl << "Hex'as: ";
	for (int i = 0; i < p.length(); i++)
	{
		cout << hex << (int)p[i];
	}

	for (int i = 0; i < 10; i++)
	{
		cout << endl;
	}
}