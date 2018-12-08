ass Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        
        count_zero = []
        t_length = len(nums)
        
        for ix in range(0, t_length):
            if nums[ix] == 0:
                nums.remove(0)
                nums.extend([0])
                    
        print(nums)
        
       
