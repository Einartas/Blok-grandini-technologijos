#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
#include <random>

using namespace std;

string string_to_hex(const std::string& input) // simboliu konvvertavimas i hex'a
{
	static const char hex_digits[] = "0123456789ABCDEF";

	std::string output;
	output.reserve(input.length() * 2);
	for (unsigned char c : input)
	{
		output.push_back(hex_digits[c >> 4]);
		output.push_back(hex_digits[c & 15]);
	}
	return output;
}

bool file(string failas, vector<string>& data) // failo nuskaitymas
{
	ifstream in(failas.c_str());

	if (!in)
	{
		cout << "Tokio failo nera!" << endl;
		return false;
	}

	string line;
	int n;
	cout << "Nuskaityti visa faila (0), tam tikra skaiciu eiluciu (1): ";
	cin >> n;
	while (n != 0 && n != 1)
	{
		cout << "Neteisinga ivestis! Nuskaityti visa faila (0), tam tikra skaiciu eiluciu (1): ";
		cin >> n;
	}

	if (n == 0)
	{
		while (getline(in, line))
		{
			data.push_back(line);
		}
	}
	else
	{
		cout << "Kiek eiluciu nuskaityti?: ";
		cin >> n;
		while (n < 1)
		{
			cout << "Neteisinga ivestis! Eiluciu skaicius 1..n: ";
			cin >> n;
		}
		for (int i = 0; i < n; i++)
		{
			getline(in, line);
			data.push_back(line);
		}
	}

	in.close();
	return true;
}

void generate(int size, int length) {
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> numb(48, 126);

	stringstream buffer;

	string fileName = to_string(size);
	fileName += "_" + to_string(length) + ".txt";
	std::ofstream rf(fileName);

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < length; j++)
		{
			buffer << (char)numb(mt);
		}
		if (i < size - 1)
			buffer << "\n";
	}

	rf << buffer.str();

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start; // Skirtumas (s)
	std::cout << size << " row size generation time " << diff.count() << " s\n";

	buffer.str("");
	buffer.clear();
	rf.close();
}

//void checkCollision(vector<string>& d)
//{
//	for (int j = 0; j < d.size(); j++)
//	{
//		for (int i = j + 1; i < d.size(); i++)
//		{
//			if (d[j].Hash() == d[i].Hash() && d[j].getRow() != d[i].getRow())
//			{
//				cout << j << " " << d[j].Hash() << "\n" << i << " " << d[i].Hash() << endl;
//				cout << j << " " << d[j].getRow() << "\n" << i << " " << d[i].getRow() << endl;
//			}
//		}
//	}
//}

int main(int argc, char const *argv[])
{
	//generate(100000, 1000);

	int input_type;
	cout << "Ivesti ranka (0), is failo (1): ";
	cin >> input_type;
	while (input_type != 0 && input_type != 1)
	{
		cout << "Neteisinga ivestis! Ivesti ranka (0), is failo (1): ";
		cin >> input_type;
	}

	string s;
	stringstream text;
	if (input_type == 1) // ivestis is failo
	{
		vector<string> data;
		string filename;
		cout << "Iveskite failo pavadinima: ";
		cin >> filename;
		filename = filename + ".txt";
		ifstream input(filename);
		bool result = file(filename, data);

		for (auto& line : data)
		{
			text << line; 
		}

		s = text.str();
	} 
	else // ivestis ranka
	{
		 cout << "Iveskite teksta: ";
		 cin.clear();
		 cin.ignore(256, '\n');
		 getline(cin, s);
	} 

	//cout << "Pradinis tekstas: " << endl << s << endl;

	string hash ="EE9A17A0F3E783EE983B7EFD23324395FE3A8E0563F860EF72D5420B9414FBEC"; // seed'as
	int temp = 0;
	vector<string> check;
	
	auto start = std::chrono::steady_clock::now();
		for (int i = 1; i < 64; i++) // hash'avimas
		{
			for (int j = 0; j < s.size(); j++)
			{
				temp = hash[i];
				temp = temp ^ int(s[j]);
				hash[i] = char(temp);
				hash[i - 1] += i ^ j;
			}
			hash[i] = int(hash[i]) + int(hash[64 - i]);
		}
	auto end = std::chrono::steady_clock::now();

		hash = string_to_hex(hash);
		hash.resize(64);
			cout << hash << endl;
			cout << "Hash'avimas uztruko: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "mcs" << endl;


}