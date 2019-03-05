#include <iostream>
#include <fstream>
#include <string>
//test
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

void print(...)

void sort(...)

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
