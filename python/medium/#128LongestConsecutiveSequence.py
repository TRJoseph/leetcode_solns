class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        # when nums is empty
        if not nums:
            return 0
        
        uniqueset = set(nums)

        max_cnt_total = 0
        max_cnt_this_iter = 1

        for num in uniqueset:
            if num-1 not in uniqueset:
                counter = num + 1
                while counter in uniqueset:
                    max_cnt_this_iter += 1
                    counter+=1
                max_cnt_total = max(max_cnt_total, max_cnt_this_iter)
                max_cnt_this_iter = 1

        return max_cnt_total