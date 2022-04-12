package serwlety;

import walidacja.Uzytkownik;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "Logowanie")
public class Logowanie extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();

        String login = request.getParameter("tekst_login");
        String haslo = request.getParameter("tekst_haslo");
        if (Uzytkownik.czyAutoryzowany(login, haslo)) {
            request.setAttribute("user",login);
            request.getRequestDispatcher("witamy.jsp").forward(request, response);
        }
        else {
            request.setAttribute("blad","Niepoprawne atrybuty logowania!");
            request.getRequestDispatcher("logowanie.jsp").forward(request,response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
