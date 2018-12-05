
class Video
{
      String title;
      int checked;
      double avgUserRating;
      int rt;
      Video(String t)
      {
            title=t;
            checked=0;
            avgUserRating=0;
            rt=0;
      }
      boolean checking()
      {
            if(checked==1)
                  return false;
            else
                  checked=1;
            return true;
      }
      boolean returned()
      {
            if(checked==0)
                  return false;
            checked=0;
            return true;
      }
      void rating(double rate)
      {
            if(rt==0)
            {
                  avgUserRating=rate;
                  rt++;return;
            }
            avgUserRating=((avgUserRating*rt)+rate)/(rt+1);
            rt++;
            return;
      }
}
