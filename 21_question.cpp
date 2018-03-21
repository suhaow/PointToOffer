#include <iostream>
#include <vector>
using namespace std;

void ReOrder(vector<int>& arr) {
	if (arr.size() == 0)
		return;

	int begin = 0;
	int end = arr.size() - 1;
	while (begin < end) {

		while (begin < end && (arr[begin] & 0x1) != 0)
			++begin;
		while (begin < end && (arr[end] & 0x1) == 0)
			--end;

		if (begin < end)
			swap(arr[begin], arr[end]);
	}
}

int main() {
	vector<int> arr;
	for (int i = 1; i <= 10; ++i) {
		arr.push_back(i);
	}

	ReOrder(arr);

	for (int i = 0; i<arr.size(); ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}
