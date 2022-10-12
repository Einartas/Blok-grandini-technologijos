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

void generate(int size) {
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> numb(48, 126);
	std::uniform_int_distribution<int> rnd(100, 100);

	stringstream buffer;

	string fileName = to_string(size);
	fileName += ".txt";
	std::ofstream rf(fileName);

	auto start = std::chrono::high_resolution_clock::now();
	int length;
	string smth;
	for (int i = 0; i < size; i++)
	{
		length = rnd(mt);
		smth.clear();
		for (int j = 0; j < length; j++)
		{
			smth += (char)numb(mt);
		}
		buffer << smth;
		if (i < size - 1)
			buffer << "\n";
		std::uniform_int_distribution<int> change(0, length - 1);
		smth.at(change(mt)) = '/';
		buffer << smth;
		i++;
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

double compare(string first, string second)
{
	double percent;
	int same = 0;
	for (int i = 0; i < first.size(); i++)
	{
		if (first.at(i) == second.at(i))
			same++;
	}
	percent = ((double)same / first.size()) * 100;
	return percent;
}

string hexToBin(string hexdec)
{
	long int i = 0;
	string binary;
	while (hexdec[i]) {

		switch (hexdec[i]) {
		case '0':
			binary += "0000";
			break;
		case '1':
			binary += "0001";
			break;
		case '2':
			binary += "0010";
			break;
		case '3':
			binary += "0011";
			break;
		case '4':
			binary += "0100";
			break;
		case '5':
			binary += "0101";
			break;
		case '6':
			binary += "0110";
			break;
		case '7':
			binary += "0111";
			break;
		case '8':
			binary += "1000";
			break;
		case '9':
			binary += "1001";
			break;
		case 'A':
		case 'a':
			binary += "1010";
			break;
		case 'B':
		case 'b':
			binary += "1011";
			break;
		case 'C':
		case 'c':
			binary += "1100";
			break;
		case 'D':
		case 'd':
			binary += "1101";
			break;
		case 'E':
		case 'e':
			binary += "1110";
			break;
		case 'F':
		case 'f':
			binary += "1111";
			break;
		}
		i++;
	}
	return binary;
}

int main(int argc, char const* argv[])
{
	//generate(100000, 1000); // random simboliu eilutes
	//generate(100000); // skiriasi 1 simbolis

	int input_type;
	cout << "Ivesti ranka (0), is failo (1): ";
	cin >> input_type;
	while (input_type != 0 && input_type != 1)
	{
		cout << "Neteisinga ivestis! Ivesti ranka (0), is failo (1): ";
		cin >> input_type;
	}

	int lines = 0;
	string s;
	stringstream text;
	vector<string> col;
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
			col.push_back(line);
			lines++;
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

	string hash = "EE9A17A0F3E783EE983B7EFD23324395FE3A8E0563F860EF72D5420B9414FBEC"; // seed'as
	int temp = 0;

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
	//cout << "Hash'avimas uztruko: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "mcs" << endl;

	// hash'avimas is vektoriaus kiekvienos eilutes atskirai
	/*temp = 0;
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			for (int x = 0; x < col[i][col[i].size()]; x++)
			{
				temp = hash[i];
				temp = temp ^ int(col[i][x]);
				hash[i] = char(temp);
				hash[i - 1] += i ^ j;
			}
			hash[j] = int(hash[j]) + int(hash[64 - j]);
		}
		hash = string_to_hex(hash);
		hash.resize(64);
		col[i] = hash;
	}
	cout << lines;*/

	// koliziju tikrinimas
	//int collision = 0;
	//for (int i = 0; i < lines; i++)
	//{
	//	for (int j = 0; j < lines; j++)
	//	{
	//		if (col[i] == col[j] && i != j) collision++;
	//	}
	//}
	//cout << endl << "Collision skaicius: " << collision << endl;

	// panasumas HEX
	vector<double> percent;
	//	for (int i = 0; i < col.size(); i++) {
	//	    percent.push_back(compare(col.at(i), col.at(i+1)));
	//	    i++;
	//	}
	//	sort(percent.begin(), percent.end());
		double sum = 0;
	//	for (auto& el : percent) {
	//	    sum += el;
	//	}
	//	cout << "HEXADECIMAL" << endl;
	//	cout << "minimum similarity: " << percent.at(0) << "%" << endl;
	//	cout << "average similarity: " << sum / percent.size() << "%" << endl;
	//	cout << "maximum similarity: " << percent.at(percent.size() - 1) << "%" << endl;

	 // panasumas BINARY
	/*	percent.clear();
		for (int i = 0; i < col.size(); i++) {
		    percent.push_back(compare(hexToBin(col.at(i)), hexToBin(col.at(i+1))));
		    i++;
		}
		sort(percent.begin(), percent.end());
		sum = 0;
		for (auto& el : percent) {
		    sum += el;
		}
		cout << "BINARY" << endl;
		cout << "minimum similarity: " << percent.at(0) << "%" << endl;
		cout << "average similarity: " << sum / percent.size() << "%" << endl;
		cout << "maximum similarity: " << percent.at(percent.size() - 1) << "%" << endl;
		hexToBin(col.at(0));*/
}