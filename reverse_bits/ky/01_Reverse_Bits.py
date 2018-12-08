class Solution:
    # @param n, an integer
    # @return an integer
    
    def reverseBits(self, n):
        tlength = 32
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
        
        for i in range(0, tlength - len(digit_ans)):
            digit_ans.append(0)            
        
        print(digit_ans)
        w_ans = 0
        for i in range(0, tlength):
            w_ans += pow(2,tlength-i-1) * digit_ans[i]
        
        return w_ans
