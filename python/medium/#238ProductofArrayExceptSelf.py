class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        left_arr = [1]
        right_arr = [1]
        
        arr_len = len(nums)

        leftProd = 1
        for i in range(1, arr_len):
            leftProd *= nums[i-1]
            left_arr.append(leftProd)
        
        rightProd = 1 
        for i in range(arr_len-2, -1, -1):
            rightProd *= nums[i+1]
            right_arr.append(rightProd)

        ans_arr = []
        right_len = arr_len - 1
        for i in range(0, len(left_arr)):
            ans_arr.append(left_arr[i] * right_arr[right_len - i])

        return ans_arr