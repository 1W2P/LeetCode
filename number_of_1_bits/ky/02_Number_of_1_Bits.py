lass Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        bit = 2
        ans = n
        digit_ans = []
        
        while ans > 1:
            if ans % bit == 0:
                digit_ans.append(0)
            else:
                digit_ans.append(1)
                ans -= 1
            ans = ans/bit
        
        digit_ans.append(ans)
        
        w_ans = 0
        for i in range(0, len(digit_ans)):
            w_ans += digit_ans[i]
            
        return w_ans
