class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        m = dict()

        for n in nums:
            if n not in m:
                m[n] = 1
            else:
                m[n] = m[n] + 1
        
        sorted_dict = dict(sorted(m.items(), key=lambda item: item[1]))
   
        ans = []

        items = list(sorted_dict.items())

        for i in range(len(items) - 1, len(items) - k - 1, -1):
            key, value = items[i]
            ans.append(key)
        
        return ans
