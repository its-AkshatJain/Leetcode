class Solution {
public:
    int digitSum(int num) {
        int sum = 0;

        while (num) {
            int digit = num % 10;
            sum += digit;
            num = num / 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> afterSorted(nums);

        auto lambda = [&](int num1, int num2) {
            int num1DigitSum = digitSum(num1);
            int num2DigitSum = digitSum(num2);

            if (num1DigitSum != num2DigitSum) {
                return num1DigitSum < num2DigitSum;
            }

            return num1 < num2;
        };

        sort(nums.begin(), nums.end(), lambda);

        unordered_map<int, int> valToIdx;
        for (int i = 0; i < n; i++) {
            valToIdx[nums[i]] = i;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int currentVal = nums[i];
            int expectedVal = afterSorted[i];

            if (currentVal == expectedVal)
                continue;

            int idx = valToIdx[expectedVal];

            nums[i] = expectedVal;
            nums[idx] = currentVal;

            valToIdx[expectedVal] = i;
            valToIdx[currentVal] = idx;

            swaps++;
        }

        return swaps;
    }
};