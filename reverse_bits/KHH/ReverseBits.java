class ReverseBits
{
    public static void main(String [] args)
    {
        int testCase =  1;
        System.out.println(reverseBits(testCase));
    }

    public static int reverseBits(int n) {
        int result = 0;
        int bit = 1;

        for(int i = 31; i >= 0; --i)
        {
            if((n&1) == 1)
            {
                result = result|(bit << i);
            }
            n >>= 1;
        }
        return result;
    }
}