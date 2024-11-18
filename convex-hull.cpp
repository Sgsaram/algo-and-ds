struct vec {
    int x, y;

    vec() : x(0), y(0) {}

    vec(int x, int y) : x(x), y(y) {}

    int squared_length() {
        return x * x + y * y;
    }
};

int cross_product(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

vec operator-(vec a, vec b) {
    return vec(a.x - b.x, a.y - b.y);
}

vec operator+(vec a, vec b) {
    return vec(a.x + b.x, a.y + b.y);
}

bool operator==(vec a, vec b) {
    return a.x == b.x && a.y == b.y;
}

bool operator<(vec a, vec b) {
    int z = cross_product(a, b);
    if (z != 0) {
        return z > 0;
    }
    return a.squared_length() < b.squared_length();
}

vector<vec> find_hull(vector<vec> points) {
    int n = (int)points.size();
    vec ps(INF, INF);
    for (auto p : points) {
        if (p.y < ps.y || (p.y == ps.y && p.x < ps.x)) {
            ps = p;
        }
    }
    for (auto &p : points) {
        p = p - ps;
    }
    sort(points.begin(), points.end());
    vector<vec> hull;
    for (int i = 0; i < min((int)2, n); i++) {
        hull.push_back(points[i]);
    }
    for (int i = 2; i < n; i++) {
        while ((int)hull.size() > 1 &&
            cross_product(points[i] - *hull.rbegin(), *(hull.rbegin() + 1) - *hull.rbegin()) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    for (auto &p : hull) {
        p = p + ps;
    }
    return hull;
}
