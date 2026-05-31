class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long MASS = mass;

        for (int& m : asteroids) {
            if (MASS < m) {
                return false;
            }
            MASS += m;
        }

        return true;
    }
};