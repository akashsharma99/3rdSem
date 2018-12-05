class Person
{
      String name;
      int age,pan;
      void details()
      {
            name="Akash Sharma";
            age=19;
            System.out.println("Name: "+name);
            System.out.println("age: "+age);
      }
}
class Student extends Person
{
      double weight;
      void studentDetails()
      {
            details();
            weight=75.5;
            System.out.println("Weight: "+weight);
      }
}
class Teacher extends Person
{
      int salary=50000;
      String subject="Maths";
      void displayDetails()
      {
            details();
            pan=123456;
            System.out.println("Pan: "+pan);
            System.out.println("Salary: "+salary);
            System.out.println("Subject: "+subject);
      }
}
class CollegeStudent extends Student
{
      int year=2017;
      String stream="CSE";
      void showDetails()
      {
            studentDetails();
            System.out.println("Year of admission: "+year);
            System.out.println("Stream: "+stream);
      }
}
class test2
{
      public static void main(String args[])
      {
            Person ob1=new Person();
            System.out.println("Using object of Person class:");
            ob1.details();
            System.out.println("\nUsing object of Student class:");
            Student ob2=new Student();
            ob2.studentDetails();
            System.out.println("\nUsing object of CollegeStudent class:");
            CollegeStudent ob3=new CollegeStudent();
            ob3.showDetails();
            System.out.println("\nUsing object of Teacher class:");
            Teacher ob4=new Teacher();
            ob4.displayDetails();

      }
}
