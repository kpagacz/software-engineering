package moj.projekt;

public class Main {

    public static void main(String[] args) {
        int x = 10;
        //wrapper
        Integer x2 = new Integer(10);

        Test.f(x);
        System.out.println(x);

        Test o = new Test(10);
        Test.g(o);
        System.out.println(o.getX());
        System.out.println(o);
        Test.h(o);
        System.out.println(o);
        o = null;

        Test t1 = new Test(10);
        Test t2 = new Test(10);

        if (t1.equals(t2)) {
            System.out.println("Obiekty posiadają te same wartości x");
        }
        else {
            System.out.println("Obiekty nie posiadają tych samych wartości x");
        }

      //  Object ob = new Object();
        Prostokat p = new Prostokat(5,7);
        System.out.println(p);

        Prostokat k = new Kwadrat(5);
        System.out.println(k);
    }
}



/*
C++
void f1(Obiekt o);
void f2(const Obiekt& o);

 */