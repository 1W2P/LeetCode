class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        
        # a ==> a,      2^1-1     1, 
        # aa ==> a, aa  2^2-2 =2  1+2 =3
        # aaa ===> a, a, a, aa, aa, aaa =6 2^3-2 3+2+1 = 6
        # aaaa ---> a,a,a,a aa,aa,aa,aaa,aaa,aaaa = 4+3+2+1     
        
        
        if len(set(list(s))) == 1:
            n = len(s)
            up = (2 + (n-1))*n
            down = 2
            result = up/down
            return result
            
        else:
            for i in range(0, len(s)):
                j = i + 1
                while j <= len(s):
                    k = 0
                    flag = 0
                    sub_check = s[i:j]
                    len_sc = len(sub_check)
                    if len_sc == 1:
                        result += 1
#                        print(sub_check, i) 39
                    
                    elif len_sc > 1 and len_sc % 2 == 1:
                        ref = (len_sc-1)/2
                        while k < ref:
                            k += 1
                            if sub_check[ref-k] != sub_check[ref+k]:
                                flag = 1
                                break
                        if flag != 1:
                            result += 1
#                            print(sub_check, i, j)
                    
                    else:
                        
                        ref_left = (len_sc/2)-1
                        ref_right = (len_sc/2)
                    
                        while k < ref_right:
                            if sub_check[ref_left - k] != sub_check[ref_right + k]:
                                flag = 1
                                break    
                            k += 1   

                        if flag != 1:
                            result += 1
 #                       print(sub_check, i, j)   
                    
                    j += 1
            
        return result
