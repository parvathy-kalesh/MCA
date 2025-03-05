import java.util.Scanner;  

class Student {
    int rollno;
    String name;
    int marks;
    static int Count = 0;  // Keep this static to track the total number of students

    public Student() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the roll no:");
        rollno = sc.nextInt();
        sc.nextLine(); // To consume the newline character
        System.out.println("Enter the name:");
        name = sc.nextLine();
        System.out.println("Enter the marks:");
        marks = sc.nextInt();
        Count++;  // Increment Count when a new student is created
    }

    public void display() {
        System.out.println(name + ", " + rollno + ", " + marks);
    }

    public static void sortStudent(Student s[]) {
        int n = Student.Count;  // Use Student.Count to get the number of students
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i].marks < s[j].marks) {
                    Student temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    }
}

public class StudentDemo {
    public static void main(String[] args) {
        Student s[] = new Student[5];
        for (int i = 0; i < 3; i++) {
            s[i] = new Student();  // Create student objects
        }

        Student.sortStudent(s);  // Sort students based on marks

        for (int i = 0; i < 3; i++) {
            s[i].display();  // Display student details
        }
    }
}

