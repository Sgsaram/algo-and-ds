const int MAX_EPOCH = 1e5 + 7;
const double DELTA_TEMP = 0.9999;

mt19937 rnd(179);

double norm_rnd() {
    return (double) rnd() / mt19937::max();
}

int rand_int(int left, int right) {
    return left + (rnd() % (right - left + 1));
}

signed main() {
    double temp = 1;
    for (int epoch = 0; epoch < MAX_EPOCH; epoch++) {
        temp *= DELTA_TEMP;

        /* Do something */
        
        cur_val = func()
        if (cur_val > best_val
            || exp((cur_val - best_val) / temp) > norm_rnd()) {
            best_val = cur_val;
        } else {
        
            /* Do something */
            
        }
    }
}