#include <iostream>

using namespace std;

void Swap (int16_t &x, int16_t &y) {
	auto Temp = x;
	x = y;
	y = Temp;
}

void Swap (double &x, double &y) {
	auto Temp = x;
	x = y;
	y = Temp;
}

void Swap (char &x, char &y) {
	auto Temp = x;
	x = y;
	y = Temp;
}

void bsort (int16_t *begin, int16_t *end, auto sort_func) {
	size_t arr_size = end - begin;
	cout<<arr_size<<endl;
	for (auto j = 0; j < arr_size; ++j) {
		for (auto i = 1; i < arr_size - j; ++i) {
			if (sort_func (*(begin + i), *(begin + i - 1))) {
				Swap (*(begin + i), *(begin + i - 1));
			}
		}
	}
}

void bsort (double *begin, double *end, auto sort_func) {
	size_t arr_size = end - begin;
	cout<<arr_size<<endl;
	for (auto j = 0; j < arr_size; ++j) {
		for (auto i = 1; i < arr_size - j; ++i) {
			if (sort_func (*(begin + i), *(begin + i - 1))) {
				Swap (*(begin + i), *(begin + i - 1));
			}
		}
	}
}

void bsort (char *begin, char *end, auto sort_func) {
	size_t arr_size = end - begin - 1;
	for (auto j = 0; j < arr_size; ++j) {
		for (auto i = 1; i < arr_size - j; ++i) {
			if (sort_func (*(begin + i), *(begin + i - 1))) {
				Swap (*(begin + i), *(begin + i - 1));
			}
		}
	}
}

int main () {
	
	double Array_To_Sort[] = {6, 7, -1, 4, 5, 0, 6, 123.9, 0, 9, 1, 33, 8, -9, 6, 7, -2, 4, 5, 0, -90.1, 9, 1, 3, 8, -9};
	char char_arr[] = "Hello_1239_World!";
		for (auto  y : char_arr) cout << y << ' ';
	bsort (begin(char_arr), end(char_arr), [](char x, char y) -> bool {
		if (x >= '0' && x <= '9' || y >= '0' && y <= '9') {return x > y;} return (x < y);});
		for (auto  y : char_arr) cout << y << ' ';
	return 0;
}


