const long mod = 5 * (1 << 25) + 1;
long root = 243;
long root_1 = 114609789;
const long root_pw = 1 << 25;

inline void fft (vector < long > & a, bool invert) {
    int n = (int) a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) {
            j -= bit;
        }
        j += bit;
        if (i < j) {
          swap(a[i], a[j]);
        }
    }
    for (int len = 2; len <= n; len <<= 1) {
        long wlen = invert ? root_1 : root;
        for (long i = len; i < root_pw; i <<= 1)
            wlen = (long) (wlen * 1ll * wlen % mod);
        for (int i = 0; i < n; i += len) {
            long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long u = a[i + j];
                long v = (long) (a[i + j + len / 2] * 1ll * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = (long) (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        long nrev = exp(n, mod-2);
        for (int i = 0; i < n; i++)
          a[i] = (long) (a[i] * 1ll * nrev % mod);
    }
}
