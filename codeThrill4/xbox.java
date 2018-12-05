import java.io.*;
import java.util.*;
class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int k=0;k<t;k++)
        {
            int d,a,m,b,x;
            d=sc.nextInt();
            a=sc.nextInt();
            m=sc.nextInt();
            b=sc.nextInt();
            x=sc.nextInt();
            if(d>=x)
            {
                  System.out.println(0);
            }
            else
            {

                  for(int i=1;;i++)
                  {
                        //d=d+a;
                        if(i%m!=0)
                        {
                              d=d+a;
                        }
                        else
                        {
                              d=d+a;
                              if(d>=x)
                              {
                                    System.out.println(i);
                                    break;
                              }
                              d=d+b;
                              if(d>=x)
                              {
                                    System.out.println(i+1);
                                    break;
                              }
                              i=i+1;
                              continue;
                        }
                        if(d>=x)
                          {
                                System.out.println(i);
                                break;
                          }
                        //d=d+a;
                  }
            }
        }

    }
}
