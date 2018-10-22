vector < lli > factorize(lli x) {
    // Returns prime factors of x
    vector < lli > primes;
    for (lli i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            primes.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x != 1) {
        primes.push_back(x);
    }
    return primes;
}

inline bool test_primitive_root(lli a, lli m) {
    // Is 'a' a primitive root of modulus 'm'?
    // m must be of the form 2^k * x + 1
    lli exp = m - 1;
    lli val = power(a, exp, m);
    if (val != 1) {
        return false;
    }
    vector < lli > factors = factorize(exp);
    for (lli f: factors) {
        lli cur = exp / f;
        val = power(a, cur, m);
        if (val == 1) {
            return false;
        }
    }
    return true;
}

inline lli find_primitive_root(lli m) {
    // Find primitive root of the modulus 'm'.
    // m must be of the form 2^k * x + 1
    for (lli i = 2; ; i++) {
        if (test_primitive_root(i, m)) {
            return i;
        }
    }
}
