// 5.5-2-2.cpp 

#include <iostream>

using namespace std;

template <class T>
class table {
public:
	T** arr;
	int size;

public:
	table(int a, int b) {
		if (a < 1 || b < 1) throw runtime_error("unavailable size");

		size = a;
		arr = new T * [size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new T[b];
		};
	}

	T* operator[](const int i) {
		if (i < 0 || i >= size) throw runtime_error("unavailable index");

		return arr[i];
	}

	const T* operator[](const int i) const {
		if (i < 0 || i >= size) throw runtime_error("unavailable index");

		return arr[i];
	}

	~table()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] arr[i];
		};
		delete[] arr;
	}

	table(const table&) = delete;
	table& operator=(const table&) = delete;
};

int main() {
	try {
		table<double> test(2, 3);

		test[0][0] = 4.2;
		cout << test[0][0]; // РІС‹РІРѕРґРёС‚ 4
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
}