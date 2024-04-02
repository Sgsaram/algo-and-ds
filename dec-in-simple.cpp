#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            cout << i << " ";
            n /= i;
        } else
            i++;
    }
    cout << n << "\n";
}