import java.util.*;

class Person {
    String name;
    String gender;
    String phoneno;
}

interface Showable {
    void show();
}

class Student extends Person implements Showable {
    String course;
    int score;

    public Student(String name, String gender, String phoneno, String course, int score) {
        this.name = name;
        this.gender = gender;
        this.phoneno = phoneno;
        this.course = course;
        this.score = score;
    }

    public void show() {
        System.out.println("Name: " + name + " Gender: " + gender + " Phone No: " + phoneno + " Course: " + course + " Score: " + score);
    }
}

class PGStudent extends Student {
    String researchArea;
    String guide;

    public PGStudent(String name, String gender, String phoneno, String course, int score, String researchArea, String guide) {
        super(name, gender, phoneno, course, score);
        this.researchArea = researchArea;
        this.guide = guide;
    }

    public void show() {
        super.show();
        System.out.println("Research Area: " + researchArea + " Guide: " + guide);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of PG students: ");
        int n = sc.nextInt();
        sc.nextLine();  // Consume newline left-over after nextInt()

        List<PGStudent> pgStudents = new ArrayList<>();

        // Taking input for n PG students
        for (int i = 0; i < n; i++) {
            System.out.println("Enter details of PG student " + (i + 1));

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("Gender: ");
            String gender = sc.nextLine();

            System.out.print("Phone No: ");
            String phoneno = sc.nextLine();

            System.out.print("Course: ");
            String course = sc.nextLine();

            System.out.print("Score: ");
            int score = sc.nextInt();
            sc.nextLine(); // Consume the newline character

            System.out.print("Research Area: ");
            String researchArea = sc.nextLine();

            System.out.print("Guide: ");
            String guide = sc.nextLine();

            PGStudent pg = new PGStudent(name, gender, phoneno, course, score, researchArea, guide);
            pgStudents.add(pg);
        }

        // Sorting by score (Descending order)
        pgStudents.sort((pg1, pg2) -> Integer.compare(pg2.score, pg1.score));
        System.out.println("\nPG students sorted by score (Descending order):");
        for (PGStudent pg : pgStudents) {
            pg.show();
        }

        // Sorting by research area (Alphabetically)
        pgStudents.sort((pg1, pg2) -> pg1.researchArea.compareTo(pg2.researchArea));
        System.out.println("\nPG students sorted by research area (Alphabetical order):");
        for (PGStudent pg : pgStudents) {
            pg.show();
        }

        sc.close();
    }

