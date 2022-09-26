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
		text << line; // nusiskaitom eilute is failo
	}
	
	cout << "Pradinis tekstas: " << text.str() << endl;

	string s = text.str();

	for (int i = 0; i < s.length(); i++) // paverciam inputa i ascii
	{
		asc << (int)s[i];
	}

	string a = asc.str();
	int n = 0;

	for (int i = 0; i < a.length() - 1; i++) // atliekam ivairius veiksmus skaiciams pakeisti
	{
		a[i] += i * 7;
		if (a[i] > 100) a[i + 1] -= 33;
		else a[i + 1] += 28 * i / 2;
		if (a[i] < 0) a[i] *= -1;

		n++;
		for (int j = 0; j < n; j++)
		{
			a[j] = a[j] * a[i + 1];
			if (a[j] < 0) a[j] *= -1; 
		}

		ch << a[i];
	}
	ch << a[a.length()];

	string p = ch.str();

	cout << endl << "Hex'as: ";
	for (int i = 0; i < p.length(); i++)
	{
		cout << hex << (int)p[i];
	}

	cout << endl;
}