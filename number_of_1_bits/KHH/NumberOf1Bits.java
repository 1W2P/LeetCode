class NumberOf1Bits
{
    public static void main(String [] args) {
        int testCase =   1;
        testCase <<=31;
        System.out.println(hammingWeight(testCase));
    }

    public static int hammingWeight(int n) {
        int count = 0;
        
        for(int i = 31; i >= 0; --i)
        {
            if((n>>>31) == 1)
            {
                ++count ;
            }
            n <<= 1;
        }
        return count;
    }
}