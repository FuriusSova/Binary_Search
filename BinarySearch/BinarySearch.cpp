#include <cmath>
#include <iostream>
using namespace std;

int fset(int arr[])
{
	int k = (rand() % 900) + 1;
	cout << k << endl;
	for (int n = 0; n <= k; n++) {
		arr[n] = (rand() % 11000) + 9000;
	};
	return k;
}

void fchek(int arr[], int size) {
	for (int n = 0; n < size; n++) {
		cout << arr[n] << " " << n << " ";
		if (n == 17) {
			if (arr[n] % 3 == 0) {
				cout << "+" << endl;
			}
			else {
				cout << "-" << endl;
			};
		}
		else {
			cout << endl;
		};
	};
};

int main()
{
	int arr[900];
	int size = fset(arr);
	fchek(arr, size);
}

