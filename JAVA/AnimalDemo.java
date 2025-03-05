class Animal {
    private String species;
    int age;
    float weight;
    protected String color;

    public Animal(String species, int age, float weight, String color) {
        this.species = species;
        this.age = age;
        this.weight = weight;
        this.color = color;
    }

    public void display() {
        System.out.println(age + " years " + weight + " kg " + species + " in " + color);
    }

    class Dog extends Animal {
        private String name;
        private String owner;

        public Dog(String name, String owner, String species, int age, float weight, String color) {
            super(species, age, weight, color);
            this.name = name;
            this.owner = owner;
        }

        @Override
        public void display() {
            System.out.println(name + " owned by " + owner);
        }
    }

    class Cat extends Animal {
        int taillength;
        String eyecolor;
        String name;

        public Cat(String name, String owner, String species, int age, float weight, String color, int taillength, String eyecolor) {
            super(species, age, weight, color);
            this.taillength = taillength;
            this.eyecolor = eyecolor;
            this.name = name;
        }

        @Override
        public void display() {
            System.out.println("Name: " + name + ", Tail Length: " + taillength + " cm, Eye Color: " + eyecolor);
        }
    }
}

public class AnimalDemo {
    public static void main(String[] args) {
        Animal a;

        Animal animal = new Animal("Generic Animal", 0, 0, "none");

       
        a = animal.new Dog("Mammal", "Mary", "Dog", 2, 12, "blue");
        a.display();

       
        a = animal.new Cat("Mammal", "Mary", "Cat", 2, 12, "blue", 25, "green");
        a.display();
    }
}
