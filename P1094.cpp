#include<iostream>
#include<algorithm>
using namespace std;

int w, n;
int price[30010];
int ans;

int main() {
	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	sort(price, price + n);
	int i = 0, j = n - 1;
	while (i <=j) {
		if (price[i] + price[j] > w) {
			ans++;
			j--;
		}
		else {
			ans++;
			i++;
			j--;
		}
		if (i == j) {
			ans++;
			break;
		}
	}
	cout << ans;

	return 0;
}#include<iostream>
#include<algorithm>
using namespace std;

int w, n;
int price[30010];
int ans;

int main() {
	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	sort(price, price + n);
	int i = 0, j = n - 1;
	while (i <=j) {
		if (price[i] + price[j] > w) {
			ans++;
			j--;
		}
		else {
			ans++;
			i++;
			j--;
		}
		if (i == j) {
			ans++;
			break;
		}
	}
	cout << ans;

	return 0;
}