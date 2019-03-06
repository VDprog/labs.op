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
	return points(a, b);
}
int read(team * (&array))
{
	ifstream Input("premier_league.csv");
	int top = 0, a, b, p;
	string buff;

	Input >> top;
	array = new team[top];
	getline(Input, buff);
	top = 0;

	while (Input.good())
	{
		getline(Input, buff, ',');
		p = buff.find(":");
		while (p == -1)
		{
			array[top].name.push_back(buff);
			getline(Input, buff, ',');
			p = buff.find(":");
			cout << "zero" << endl;
		}
		
		cout << "first" << endl;
		array[top].rating += rating(buff);
		for (int i = 1; i <= 8; i++)
		{
			cout << "first" << endl;
			getline(Input, buff, ',');
			array[top].rating += rating(buff);
		}
		getline(Input, buff, '\n');
		array[top].rating += rating(buff);
		top++;
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
