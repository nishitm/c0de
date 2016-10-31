// Problem::Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.

int maxProduct(vector<int>& nums) {

       int n = nums.size();
        if (n == 0)
            return 0;

        int max_product = nums[0];
        int cur_max = nums[0];
        int cur_min = nums[0];
        int tmp1;
        int tmp2;

        for (int i = 1; i < n; i++)
        {
            tmp1 = cur_max * nums[i];
            tmp2 = cur_min * nums[i];

            cur_max = max(tmp2,max(tmp1, nums[i]));
            cur_min = min(tmp1,min(tmp2, nums[i]));
            max_product = max(max_product, cur_max);
        }

        return max_product;

    }
