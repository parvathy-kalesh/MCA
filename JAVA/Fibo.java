import java.util.Scanner;

public class Fibo {
    public static void fiba(int n) {
        int a = 0, b = 1;
        System.out.println(a);
        if (n > 1) {
            System.out.println(b);
        }
        for (int i = 2; i < n; i++) {  
            int c = a + b;
            System.out.println(c);
            a = b;
            b = c;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of terms: ");
        int n = sc.nextInt();
        if (n <= 0) {
            System.out.println("Please enter a positive integer.");
        } else {
            fiba(n);
        }
        sc.close();
    }
}
