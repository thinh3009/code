#include<iostream>

using namespace std;
template <class p1, class p2>
int tim_max(p1 x, p2 y) {
	if (x > y) {
		return x;
	}
	else if (x < y) {
		return y;
	}
	return y;
}
int main() {
	int a = 5;
	int b = 10;
	cout << "\nso nguyen lon nhat la: " << tim_max(a, b);

	float x = 2.1;
	float y = 3.2;
	cout << "\nso thuc lon nhat la: " << tim_max(x, y)<<endl;
	system("pause");
	return 0;
}
