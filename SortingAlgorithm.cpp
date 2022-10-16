#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Quick Sort */
void sort(vector<int>::iterator arr, vector<int>::iterator end)
{
	int l = 0, r = (end - arr) - 1;
	if (l >= r)
		return;
	int mid = arr[(l + r) / 2];
	// Select the middle value of vector as pivot
	while (l <= r)
	{
		while (arr[l] < mid)
			++l;
		while (mid < arr[r])
			--r;
		if (l <= r)
		{
			swap(arr[l++], arr[r--]);
		}
	}
	sort(arr, arr + l); // Call the sort function recursively
	sort(arr + l, end);
}

void arrayPrint(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

vector<int> &readFile()
{
	vector<int> &V = *(new vector<int>());
	ifstream File;
	File.open("Sample Data.txt");
	string arr_as_String;
	while (getline(File, arr_as_String, ','))
	{
		V.push_back(stoi(arr_as_String));
	}
	// cout << "n : " << V.size() << endl;

	return V;
}

int main(void)
{
	vector<int> arr = readFile();
	// arrayPrint(arr);
	sort(arr.begin(), arr.end());
	arrayPrint(arr);

	return 0;
}