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

int points(...)

int read(...)

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

void write(...)

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
