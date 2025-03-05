import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Menu {

    private static ArrayList<String> names = new ArrayList<>();
  
    public static void addName() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the name to add: ");
        String name = sc.nextLine();
        names.add(name);
        System.out.println("'" + name + "' has been added.");
    }

 
    public static void removeName() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the name to remove: ");
        String name = sc.nextLine();
        if (names.contains(name)) {
            names.remove(name);
            System.out.println("'" + name + "' has been removed.");
        } else {
            System.out.println("'" + name + "' not found.");
        }
    }

    public static void searchName() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the name to search for: ");
        String name = sc.nextLine();
        if (names.contains(name)) {
            System.out.println("'" + name + "' is found.");
        } else {
            System.out.println("'" + name + "' not found.");
        }
    }


    public static void sortNames() {
        Collections.sort(names);
        System.out.println("Names have been sorted.");
    }

    public static void displayNames() {
        if (!names.isEmpty()) {
            System.out.println("List of names:");
            for (String name : names) {
                System.out.println(name);
            }
        } else {
            System.out.println("The list is empty.");
        }
    }

 
    public static void menu() {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Add Name");
            System.out.println("2. Remove Name");
            System.out.println("3. Search for Name");
            System.out.println("4. Sort Names");
            System.out.println("5. Display Names");
            System.out.println("6. Exit");

            System.out.print("Enter your choice (1-6): ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    addName();
                    break;
                case 2:
                    removeName();
                    break;
                case 3:
                    searchName();
                    break;
                case 4:
                    sortNames();
                    break;
                case 5:
                    displayNames();
                    break;
                case 6:
                    System.out.println("Exiting the program.");
                    return;
                default:
                    System.out.println("Invalid choice, please try again.");
                  }
        }
    }

    public static void main(String[] args) {
        menu();
    }
}
   
