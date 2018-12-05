import java.util.Scanner;
class Person
{
     String name;
     int age,PANno;
     void details()
     {
          Scanner sc=new Scanner(System.in);
          System.out.print("Enter Name: ");
          name=sc.nextLine();
          System.out.print("Enter Age: ");
          age=sc.nextInt();
          System.out.print("Enter PAN no. :");
          PANno=sc.nextInt();
     }
}
class Student extends Person
{
     String name;
     int age;
     double weight;
     void details()
     {
          Scanner sc=new Scanner(System.in);
          System.out.print("Enter Name: ");
          name=sc.nextLine();
          System.out.print("Enter Age: ");
          age=sc.nextInt();
          System.out.print("Enter weight:");
          weight=sc.nextDouble();
     }
}
class Teacher extends Person
{
     double salary;
     String subject;
     void displayDetails()
     {
          System.out.println("NAME: "+name);
          System.out.println("Age: "+age);
          System.out.println("PAN no: "+PANno);
          System.out.println("salary: $"+salary);
          System.out.println("Subject: "+subject);
     }
}
class CollegeStudent extends Student
{
     int year;
     String stream;
     void showDetails()
     {
          System.out.println("NAME: "+name);
          System.out.println("Age: "+age);
          System.out.println("Weight: "+weight);
          System.out.println("Year: "+year);
          System.out.println("Stream: "+stream);
     }
}
public class School
{
     public static void main(String args[])
     {
          Scanner sc=new Scanner(System.in);
          CollegeStudent cstObj=new CollegeStudent();
          Teacher tObj=new Teacher();
          System.out.println("For Student-----");
          System.out.print("Enter stream: ");
          cstObj.stream=sc.nextLine();
          System.out.print("Enter year of admission: ");
          cstObj.year=sc.nextInt();
          cstObj.details();
          cstObj.showDetails();
          sc=new Scanner(System.in);
          System.out.println("For Teacher-----");
          System.out.print("Enter subject: ");
          tObj.subject=sc.nextLine();
          System.out.print("Enter salary: ");
          tObj.salary=sc.nextDouble();
          tObj.details();
          tObj.displayDetails();
     }
}
