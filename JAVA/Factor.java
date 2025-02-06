import java.util.Scanner;
public class Factor{
public static int fact(int n) 
{
    if(n==1)
    return 1;
    else
    {
        return n*fact(n-1);
    }
}
public static void main(String a[])
{
    Scanner sc=new Scanner(System.in);
    System.out.println("enter the number");
    int n=sc.nextInt();
    System.out.println("The factorial of " + n + " is: " + fact(n));
    sc.close();
}
}