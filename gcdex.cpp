#include <iostream>

using namespace std;

int gcdex(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int xp, yp, d = gcdex(b, a % b, xp, yp);
    x = yp;
    y = xp - (a / b) * yp;
    return d;
}

int main() {
    int a, n, g, x, _y;
    cin >> a >> n;
    g = gcdex(a, n, x, _y);
    if (g != 1) {
        cout << "0\n";
        return 0;
    }
    cout << (x % n + n) % n << "\n";
}
