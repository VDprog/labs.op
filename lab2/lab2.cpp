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

void print(team *array, int size) {
	cout << "------------------------------------" << endl;
	for (int i = 0; i < size; i++)
		cout << setw(3) << i + 1 << " | " << setw(21) << array[i].name << " | " << setw(4) << array[i].rating << " |" << endl;
	cout << "------------------------------------" << endl;
}

void sort(team *array, int size) {
	int n = 0;
	for (int i = 1; i < size; i++) {
		for (n= i; n >= 1 && array[n].rating > array[n - 1].rating; n--) {
			swap(array[n], array[n - 1]);
		}
	}
}

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
