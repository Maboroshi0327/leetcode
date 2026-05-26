int missingNumber(int *nums, int numsSize) {
    int result = 0;

    for (int i = 0; i < numsSize; i++)
        result ^= nums[i] ^ (i + 1);

    return result;
}
