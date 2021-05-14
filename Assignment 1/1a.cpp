/*input
10
1 1 2 3 3 4 4 1 1 9
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << count(a, a + n, a[0]) << '\n';
	return 0;
}