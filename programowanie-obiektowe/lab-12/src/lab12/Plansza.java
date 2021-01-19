package lab12;

public class Plansza {
    // class fields
    private int wys;
    private int szer;
    private Obiekt[][] plansza; // variable object - nie jest tak naprawdę instancją Obiekt = referencja do obiektu

    public Plansza(int wys, int szer) {
        this.wys = wys;
        this.szer = szer;
        plansza = new Obiekt[wys][szer];
    }

    final public void drukuj() {
        for(int i = 0; i < wys; i++) {
            for (int j = 0; j < szer; j++) {
                if (plansza[i][j] != null)
                    plansza[i][j].drukuj();
                else
                    System.out.print('.');
            }
            System.out.println();
        }
        System.out.println();
    }

    public void dodaj(int wiersz, int kolumna, char c) {
        if(wiersz < 0 || kolumna < 0 || wiersz >= this.szer || kolumna >= this.wys)
            return;
        switch (c) {
            case 'A' -> plansza[wiersz][kolumna] = new A();
            case 'B' -> plansza[wiersz][kolumna] = new B();
            case 'C' -> plansza[wiersz][kolumna] = new C();
            case 'D' -> plansza[wiersz][kolumna] = new D();
        }
    }

    public void zamien(int w1, int k1, int w2, int k2) {
        if(w1 >= this.wys || w1 < 0 || k1 >= this.szer || k1 < 0
                || w2 >= this.wys || w2 < 0 || k2 >= this.szer || k2 < 0)
            return;
        Obiekt temp = plansza[w1][k1];
        plansza[w1][k1] = plansza[w2][k2];
        plansza[w2][k2] = temp;
    }

    public void przesun(int w, int k, int dodaj_w, int dodaj_k) {
        if(waliduj_wsp(w, k) && waliduj_wsp(w + dodaj_w, k + dodaj_k)) {
            plansza[w + dodaj_w][k + dodaj_k] = plansza[w][k];
            plansza[w][k] = null;
        }
    }

    private boolean waliduj_wsp(int w, int k) {
        return ((w >= 0) && (w < this.wys) && (k >= 0) && (k < this.szer));
    }
}
