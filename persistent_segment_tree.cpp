class Pers_seg_tree {
 public:
    explicit Pers_seg_tree(int n) : n(n) {
        versions.push_back(build(0, n));
    }

    void add_version(int version, int pos, int val) {
        versions.push_back(add(versions[version], 0, n, pos, val));
    }

    int get_version(int version, int l, int r) {
        return get(versions[version], 0, n, l, r);
    }

 private:
    struct Node {
        Node *l, *r;
        int s;

        explicit Node(int s) : s(s) {
            l = r = nullptr;
        }

        Node(Node *l, Node *r) : l(l), r(r), s(0) {
            if (l)
                s += l->s;
            if (r)
                s += r->s;
        }
    };

    int n;
    vector<Node *> versions;

    Node *build(int l, int r) {
        if (l + 1 == r) {
            return new Node(0);
        } else {
            int m = (l + r) / 2;
            return new Node(build(l, m), build(m, r));
        }
    }

    Node *add(Node *v, int l, int r, int pos, int val) {
        if (l + 1 == r) {
            return new Node(v->s + val);
        } else {
            int m = (l + r) / 2;
            if (pos < m)
                return new Node(add(v->l, l, m, pos, val), v->r);
            else
                return new Node(v->l, add(v->r, m, r, pos, val));
        }
    }

    int get(Node *v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return v->s;
        } else if (qr <= l || r <= ql) {
            return 0;
        } else {
            int m = (l + r) / 2;
            return get(v->l, l, m, ql, qr) + get(v->r, m, r, ql, qr);
        }
    }
};
