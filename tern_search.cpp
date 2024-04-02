for (int it = 0; it < 400; it++) {
        m1 = (2 * l + r) / 3;
        m2 = (l + 2 * r) / 3;
        if (func(m1) < func(m2))
            r = m2;
        else
            l = m1;
    }
    
// убывает, потом возрастает