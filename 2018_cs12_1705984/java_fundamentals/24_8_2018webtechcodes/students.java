import java.util.Scanner;
class Student
{
  String name,branch;
  int rollNo,semester,mark[]=new int[2];
  char grade;
  Student()
  {
    name="N/A";
    branch="N/A";
    rollNo=0;
    semester=0;
    mark[0]=0;
    mark[1]=0;
    grade='?';
  }
  Student(String n,String b,int r,int sem,int mk[],char gd)
  {
    name=n;
    branch=b;
    rollNo=r;
    semester=sem;
    mark[0]=mk[0];
    mark[1]=mk[1];
    grade=gd;
  }
  void show()
  {
    System.out.println("Name: "+name);
    System.out.println("Branch: "+branch);
    System.out.println("Roll no: "+rollNo);
    System.out.println("Semester: "+semester);
    System.out.println("Marks in two subjects: "+mark[0]+","+mark[1]);
    System.out.println("Grade: "+grade);
  }
}
class StudentDemo
{
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    Student arr[]=new Student[5];
    String n,b;
    int roll,sem,mk[]=new int[2];
    char gd;
    System.out.println("Enter details of 5 students: ");
    for(int i=0;i<2;i++)
    {
      System.out.println("Student "+(i+1)+":-");
      System.out.print("Name: ");
      n=sc.nextLine();
      System.out.print("Branch: ");
      b=sc.nextLine();
      System.out.print("Roll no: ");
      roll=sc.nextInt();
      System.out.print("Semester: ");
      sem=sc.nextInt();
      System.out.print("Marks in two subjects: ");
      mk[0]=sc.nextInt();
      mk[1]=sc.nextInt();
      sc.nextLine();
      System.out.print("Grade: ");
      gd=sc.nextLine().charAt(0);
      arr[i]=new Student(n,b,roll,sem,mk,gd);
    }
    System.out.println("\nThe entered details are:\n");
    for(int i=0;i<2;i++)
    {
      System.out.println("\nStudent "+(i+1)+" :");
      arr[i].show();
    }
  }
}
