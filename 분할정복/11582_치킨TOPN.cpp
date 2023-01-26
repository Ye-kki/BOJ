#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, k;
vector<int> arr;
vector<int> arr2;

void merge(int left, int right) {
	if ((right - left) > (N / k)) return;

	int mid = (left + right) / 2;

	int i = left; //왼쪽 값들의 인덱스
	int j = mid + 1; //오른쪽 값들의 인덱스
	int k = left; //arr2의 인덱스

	while (i <= mid && j <= right) {//합병과정
		if (arr[i] <= arr[j]) arr2[k++] = arr[i++];
		else arr2[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;
	while (k <= right) arr2[k++] = arr[tmp++]; //작은 값들 정렬 후 나머지 합병

	for (int i = left; i <= right; i++) arr[i] = arr2[i]; //원래 정렬에 복사
}

void partition(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	arr2.resize(N);

	cin >> k;

	partition(0, N - 1);

	for (int i = 0; i < N; i++) cout << arr2[i] << ' ';
}