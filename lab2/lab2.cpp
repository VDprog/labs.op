#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct team
{
	string name;
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
int read(team * (&array))
{
	ifstream Input("premier_league.csv");
	int top = 0, a, b;
	string buff;

	Input >> top;
	array = new team[top];
	getline(Input, array[0].name);
	top = 0;

	while (Input.good())
	{
		getline(Input, buff, ',');
		array[top].name = buff;
		for (int i = 1; i <= 9; i++)
		{
			getline(Input, buff, ':');
			a = stoi(buff);
			getline(Input, buff, ',');
			b = stoi(buff);
			array[top].rating += points(a, b);
		}
		getline(Input, buff, ':');
		a = stoi(buff);
		getline(Input, buff, '\n');
		b = stoi(buff);
		array[top].rating += points(a, b);
		top++;
	}
	Input.close();
	return top;
}

void print(...)

void sort(...)

void write(team *array, int size)
{
	ofstream Output("result.csv");
	for (int i = 0; i < size; i++)
		Output << array[i].name << "," << array[i].rating << "\n";
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