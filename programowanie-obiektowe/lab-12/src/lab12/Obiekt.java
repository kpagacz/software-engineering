package lab12;

public abstract class Obiekt {
    /* abstract void drukuj(); // widocznosc metody tylko w pakiecie */
    /* protected void drukuj(); jak protected w c++
       private void drukuj(); jak private w c++ */
    public abstract void drukuj();
} // nie ma srednika na koncu klasy

class A extends Obiekt {
    public void drukuj() {
        System.out.print('A');
    }
}

class B extends Obiekt {
    public void drukuj() {
        System.out.print('B');
    }
}

class C extends Obiekt {
    public void drukuj() {
        System.out.print('C');
    }
}

class D extends Obiekt {
    public void drukuj() {
        System.out.print('D');
    }
}
