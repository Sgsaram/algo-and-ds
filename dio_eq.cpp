// в котором число 'x' имеет наименьшее неотрицательное значение

#include <iostream>

using namespace std;

long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long xp, yp, d = gcdex(b, a % b, xp, yp);
    x = yp;
    y = xp - (a / b) * yp;
    return d;
}

int main() {
    long long a, b, c, g, x, y;
    cin >> a >> b >> c;
    g = gcdex(a, b, x, y);
    if (c % g != 0) {
        cout << "Impossible\n";
        return 0;
    }
    x *= c / g;
    y *= c / g;
    long long t1 = b / g, t2 = a / g, k;
    if (x >= 0) {
        k = x / t1;
        cout << x - k * t1 << " " << y + k * t2;
    } else {
        k = (abs(x) + t1 - 1) / t1;
        cout << x + k * t1 << " " << y - k * t2;
    }
    cout << "\n";
}
