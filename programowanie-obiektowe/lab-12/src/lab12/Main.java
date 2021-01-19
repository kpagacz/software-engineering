package lab12;

public class Main {
    public static void main(String[] args) {
	    System.out.println("Hello world!");
	    Plansza p = new Plansza(10, 10);
	    p.dodaj(0, 3, 'A');
	    p.zamien(0,3, 0, 0);
	    p.drukuj();
	    p.przesun(0, 0, 1, 1);
	    p.drukuj();
    }
}
