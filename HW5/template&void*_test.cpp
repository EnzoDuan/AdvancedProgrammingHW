#include <iostream>
#include <string>
using namespace std;

template <class T>
inline T const max1(T const s[], int size) {
	T _max; 
	for (int i = 0; i < size - 1; i++)
		_max = s[i] > s[i + 1] ? s[i] : s[i+1];
	return _max;
}

int cmp(const void*element_1, const void*element_2) {
	return *((int *)element_1) - *((int *)element_2);
}

int max2(const void *s, int size, int memberSize, int (*cmp)(const void*, const void*)) {
	int maxIndex = 0;
	char *temp = (char *)s;
	for (int i = 0; i < size; i++) {
		if (cmp(temp + maxIndex * memberSize, temp + i * memberSize) < 0)
			maxIndex = i;
	}
	return maxIndex;
}

int main() {
	string S[] = { "father","son" };
	char C[] = { "abcdefg" };
	int I[] = { 1,2,3,4,5,6,7 };
	float F[] = { 1.0, 2.3, 100.5, 10.54 };
	int size1 = sizeof(S)/sizeof(string);
	int size2 = sizeof(C) / sizeof(char) - 1;
	int size3 = sizeof(I) / sizeof(int);
	int size4 = sizeof(F) / sizeof(float);
	/* Using template. */
	string ans1 = max1(S, size1);
	char ans2 = max1(C, size2);
	int ans3 = max1(I, size3);
	float ans4 = max1(F, size4);
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	cout << ans4 << endl;
	/* Using general pointer. */
	int ans5 = max2(S, size1, sizeof(string), cmp);
	int ans6 = max2(C, size2, sizeof(char), cmp);
	int ans7 = max2(I, size3, sizeof(int), cmp);
	int ans8 = max2(F, size4, sizeof(float), cmp);
	cout << S[ans5] << endl;
	cout << C[ans6] << endl;
	cout << I[ans7] << endl;
	cout << F[ans8] << endl;
	return 0;
}