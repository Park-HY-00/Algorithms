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
	sort(arr, arr + l);
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
	int N, k;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> k;
		V.push_back(k);
	}

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
