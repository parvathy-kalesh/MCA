class Multi implements Runnable {
    public void run() {
        System.out.println("MULTIPLICATION of 5");
        for (int i = 0; i <= 5; i++) {
            System.out.println("5 * " + i + " = " + (5 * i));
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}

class Fact implements Runnable {
    public void run() {
        System.out.println("FACTORS OF 36");
        int number = 36;
        for (int i = 1; i <= number; i++) {
            if (number % i == 0) {
                System.out.println(i + " is a factor of " + number);
                try {
                    Thread.sleep(500);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

public class Exam {
    public static void main(String[] args) {
        Multi m = new Multi();
        Fact f = new Fact();
        
        Thread t1 = new Thread(m);
        Thread t2 = new Thread(f);
        
        t1.start();
        t2.start();
        
        try {
            t1.join();
            t2.join();
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println("Both threads are finished.");
    }
}
