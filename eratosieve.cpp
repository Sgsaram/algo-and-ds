#include <iostream>
#include <vector>

using namespace std;

const int N = 1e8;

int main() {
    vector<bool> is_prime(N + 1, true);
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i])
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
    }
    int n, i = 2;
    cin >> n;
    while (i <= N && n) {
        if (is_prime[i])
            n--;
        i++;
    }
    cout << i - 1 << "\n";
}