class Zoo {
    String name;
    String[] encl;

    public Zoo(String name, String[] encl) {
        this.name = name;
        this.encl = encl;
    }

    public void display1() {
        System.out.println(name);
        for (String x : encl) {
            System.out.println(x);
        }
    }

    class Enclosure {
        String name;
        String[] animals;
        String type;

        // Corrected constructor (removed void)
        public Enclosure(String n, String t, String[] a) {
            name = n;
            type = t;
            animals = a;
        }

        public void display2() {
            System.out.println(name + " " + type);
            for (String x : animals) {
                System.out.println(x);
            }
        }
    }

    static class ZooInfo {
        String add;
        int phno;

    
        public ZooInfo(String a, int p) {
            add = a;
            phno = p;
        }

        public void display3() {
            System.out.println(add + " " + phno);
        }
    }
}

public class ZooDemo {
    public static void main(String[] args) {
        String encl[] = { "area1", "area2", "area3" };
        String animals[] = { "zebra", "bear" };

 
        Zoo z = new Zoo("tvmzoo", encl);

       
        Zoo.Enclosure en = z.new Enclosure("outanimal", "outdoor", animals);
        en.display2();

  
        Zoo.ZooInfo info = new Zoo.ZooInfo("abclane", 90000);
        info.display3();
    }
}
