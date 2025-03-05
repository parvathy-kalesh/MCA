import java.util.Scanner;

interface Printable{
    public void display();
    public void show();
}
interface Computable{
    public double area();
    public double perimeter();
    public double volume();
}
interface Drawable{
    public void draw();
}
class Rectangle implements Printable,Computable,Drawable{
    double length,width;
    Rectangle(double length,double width)
    {
        this.length=length;
        this.width=width;
    }
    public void display() {
        System.out.println("Length: "+length+" Width: "+width);
    
    }
    public void show() {}
    public double area(){
    return length*width;

   }
    public double perimeter(){
    return 2*(length+width);
    }
    public double volume(){
    return -1;
    }
    public void draw() {
    System.out.println("Drawing a rectangle");
    }

}
class Sphere implements Printable,Computable,Drawable{
    double radius;
    Sphere(double radius)
    {
        this.radius=radius;
    }
     public void display() {
        System.out.println("Radius"+radius);
    
    }
     public void show() {}
    public double area(){
    return 4* Math.PI * Math.pow (radius, 2);

}
    public double perimeter(){
    return 2* Math.PI * radius;
    }
    public double volume(){
    return (4/3)* Math.PI*Math.pow(radius, 3);
    }
    public void draw() {
    System.out.println("Drawing a sphere");
    }

}
class RDemo{
    public static void main(String[] args) {
        System.out.println("enter the length and weight of rectangle");
        Scanner sc=new Scanner(System.in);
        double length=sc.nextDouble();
        double width=sc.nextDouble();
        Rectangle r = new Rectangle(length, width);
        r.display();
        r.show();
        System.out.println("Area: " + r.area());
        System.out.println("Perimeter: " + r.perimeter());
        System.out.println("Volume: " + r.volume());
        r.draw();
        System.out.print("\nEnter the radius of the sphere: ");
        double radius = sc.nextDouble();
        
        Sphere s = new Sphere(radius);
        s.display();
        s.show();
        System.out.println("Area: " + s.area());
        System.out.println("Perimeter: " + s.perimeter());
        System.out.println("Volume: " + s.volume());
        s.draw();

        sc.close();
    }
}




    