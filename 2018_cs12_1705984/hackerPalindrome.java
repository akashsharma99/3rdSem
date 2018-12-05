import java.util.Scanner;
class Solution {

    static int palindromeIndex(String st) {
        if(isPalindrome(st))
            return -1;
        for(int i=0;i<st.length();i++)
        {
            String sub;
            if(i==0)
                sub=st.substring(1);
            else if(i==st.length()-1)
                sub=st.substring(0,st.length()-1);
            else
                sub=st.substring(0,i)+st.substring(i+1);
            if(isPalindrome(sub))
                return i;
        }
        return -1;
    }
    static boolean isPalindrome(String st)
    {
        for(int i=st.length()-1,j=0;i>j;i--,j++)
        {
            if(st.charAt(i)!=st.charAt(j))
                return false;
        }
        return true;
    }
    public static void main(String args[])
    {
          Scanner sc=new Scanner(System.in);
          System.out.println(isPalindrome(sc.nextLine()));
    }
}
