#include <iostream>
#include <random>
#include <string>
#include <map>
#include <ctime>
using namespace std;


int main() {
	int Choice;
	cout << "Choose your way : 1 for random_device Random, 2 for simple calculation" << endl;
	cin >> Choice;
	if (Choice == 1) {
		random_device Random;
		std::map<int, int> hist;
		std::uniform_int_distribution<int> dist(2, 9);
		for (int i = 0; i < 1000000; i++) {
		++hist[dist(Random)];
		//	std::cout << dist(Random) << ' ';
		}
		std::cout << '\n';
		for (auto p : hist) {
		std::cout << p.first << " : " << std::string(p.second / 10000, '*') << '\n';
		}
	}
	else {
		int rando;
		int mass[8] = { 0 };
		srand(time(NULL));
		for (int i = 0; i < 1000000; i++) {
			rando = (rand() % 8) + 2;
			if (rando % 2 == 0)
			{
				mass[0]++;
				if (rando % 4 == 0)
				{
					mass[2]++;
					if (rando % 8 == 0)
						mass[6]++;
				}
			}
			if (rando % 3 == 0)
			{
				mass[1]++;
				if (rando % 9 == 0)
					mass[7]++;
			}
			if (rando % 5 == 0)
				mass[3]++;
			if (rando % 6 == 0)
				mass[4]++;
			if (rando % 7 == 0)
				mass[5]++;
			//	cout << rando << ' ';
		}
		//cout << '\n';
		int i;
		for (i = 0; i < 8; i++)
		{
			cout << i + 2 << ":";
			//	cout << mass[i] << ' ';
			mass[i] = mass[i] / 10000;
			for (int j = 0; j < mass[i]; j++)
				cout << '*';
			cout << '\n';
		}
	}
	system("pause");
	return 0;
}
