package moj.projekt;

public class Test implements MojInterfejs {
    private int x;

    public Test(int x) {
        this.x = x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getX() {
        return x;
    }

    public static void f(int n) {
        n++;
    }

    @Override
    public boolean g(int y) {
        return y % 2 == 0;
    }

    public static void g(Test t) {
        t.setX(0);
    }

    public static void h(Test t) {
        t = null;
    }

    @Override
    public boolean equals(Object o) {
        return this.x == ((Test)o).x;
    }


}

class Prostokat  { //extends Object
    private static int losowa;
    private int x;
    private int y;

    public Prostokat(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Prostokat(int x) {
       this(x,x);
    }


    public Prostokat() {
        this(5);
    }

    {
        x = 10;
        x = 5;
    }

    static
    {
        losowa = 10;
    }

    public String toString() {
        return "Prostokat: " + x + 'x' + y;
    }

}

class Kwadrat extends Prostokat {
    public Kwadrat(int x) {
        super(x);
    }

    public String toString() {
        return "Kwadrat: " + super.toString();
    }
}
