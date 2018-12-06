class ReverseBits
{
    public static void main(String [] args)
    {
        int testCase =  1;
        System.out.println(reverseBits(testCase));
    }

    public static int reverseBits(int n) {
        int result = 0;
        int temp = 1;
        n = ~n;
        for(int i = 31; i >= 0; --i)
        {
            if((n<<31) == 0)
            {
                result = result|(temp<<i);
            }
            n >>= 1;
        }
        return result;
    }
}