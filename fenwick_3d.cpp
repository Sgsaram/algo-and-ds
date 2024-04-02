#include <bits/stdc++.h>
using namespace std;

int c[129][129][129];
int n;

void increase(int, int, int, int);
int sum(int, int, int, int, int, int);
int sum(int, int, int);


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int key;
    int x1, x2, y1, y2, z1, z2, delta;

    while (true) {
        cin >> key;
        if (key == 1) {
            cin >> x1 >> y1 >> z1 >> delta;
            increase(x1, y1, z1, delta);
        }
        else if (key == 2) {
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << sum(x1, y1, z1, x2, y2, z2) << "\n";
        }

        else break;
    }
}

void increase(int x1, int y1, int z1, int delta) {
    for (int i = x1; i < n; i |= (i + 1)) {
        for (int j = y1; j < n; j |= (j + 1)) {
            for (int l = z1; l < n; l |= (l + 1))
                c[i][j][l] += delta;
        }
    }
}

int sum(int x1, int y1, int z1, int x2, int y2, int z2) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if (z1 > z2) swap(z1, z2);
    return sum(x2, y2, z2)
         - sum(x1 - 1, y2, z2)
         - sum(x2, y1 - 1, z2)
         - sum(x2, y2, z1 - 1)
         + sum(x1 - 1, y1 - 1, z2)
         + sum(x1 - 1, y2, z1 - 1)
         + sum(x2, y1 - 1, z1 - 1)
         - sum(x1 - 1, y1 - 1, z1 - 1);
}

int sum(int x1, int y1, int z1) {
    if (x1 < 0 || y1 < 0 || z1 < 0) {
        return 0;
    }
    int result = 0;

    for (int i = x1; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y1; j >= 0; j = (j & (j + 1)) - 1) {
            for (int l = z1; l >= 0; l = (l & (l + 1)) - 1)
                result += c[i][j][l];
        }
    }

    return result;
}
