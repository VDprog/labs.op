#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct team
{
	vector<string> name;
	int rating;
	team()
	{
		rating = 0;
	}
};

int points(int a, int b)
{
	if (a > b)
		return 3;
	if (a == b)
		return 1;
	return 0;
}
int rating(string buff)
{
	int p = buff.find(":"), a, b;
	a = stoi(buff.substr(0, p));
	b = stoi(buff.substr(p + 1, buff.size() - 1));
	// cout << a << " " << b;
	return points(a, b);
}
int read(team * (&array))
{
	ifstream Input("premier_league.csv");
	int top = 0;
	int p, s;
	string buff;

	Input >> top;
	array = new team[top];
	getline(Input, buff);
	top = 0;

	while (Input.good())
	{
		Input.ignore(1);					// ignore one symbol
		getline(Input, buff, '\n');			// read one line

		p = buff.find('"');
		do
		{
			array[top].name.push_back(buff.substr(s, p - s));
			s = p + 3;
			p = buff.find('"', s);
		}
		while (p != -1);

		s--;
		p = buff.find(',', s);
		do
		{
			array[top].rating += rating(buff.substr(s, p - s));
			s = p + 1;
			p = buff.find(',', s);
		}
		while (p != -1);
		top++;
		s = 0;
		p = 0;
	}
	Input.close();
	return top;
}

void print(team *array, int size) {
	cout << "------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < array[i].name.size(); j++)
		{
			cout << setw(3) << i + 1 + j << " | " << setw(21) << array[i].name[j] << " | " << setw(4) << array[i].rating << " |" << endl;
		}
	}
	cout << "------------------------------------" << endl;
}

void sort(team *array, int size) {
	int n = 0;
	for (int i = 1; i < size; i++) {
		for (n = i; n >= 1 && array[n].rating > array[n - 1].rating; n--) {
			swap(array[n], array[n - 1]);
		}
	}
}

void write(team *array, int size)
{
	ofstream Output("result.csv");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < array[i].name.size(); j++)
		{
			Output << array[i].name[j] << "," << array[i].rating << "\n";
		}
	}
	Output.close();
}

int main()
{
	team *array;
	int size;

	size = read(array);
	print(array, size);

	sort(array, size);
	print(array, size);
	write(array, size);

	return 0;
}