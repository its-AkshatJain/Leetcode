class Solution {
public:
    static constexpr long long MOD = 1'000'000'007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long a = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + a * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        for (int x = 0; x < m; x++) {
            int Dx = x;
            int Ux = m + x;

            for (int y = 0; y < x; y++) {
                int Uy = m + y;
                T[Uy][Dx] = 1;
            }

            for (int y = x + 1; y < m; y++) {
                int Dy = y;
                T[Dy][Ux] = 1;
            }
        }

        Matrix P = power(T, n - 1);

        vector<long long> init(S, 1);

        long long ans = 0;

        for (int i = 0; i < S; i++) {
            long long cur = 0;

            for (int j = 0; j < S; j++) {
                cur = (cur + P[i][j] * init[j]) % MOD;
            }

            ans = (ans + cur) % MOD;
        }

        return (int)ans;
    }
};