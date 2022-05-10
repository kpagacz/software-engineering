package com.example.demo2;

import DBService.BDKlasa;
import DBService.Validation;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet(name = "LoginServlet", value = "/login-servlet")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String login = request.getParameter("textLogin");
        String passwd = request.getParameter("textPasswd");

        if (Validation.isAuthorized(login, passwd)) {
            try {
                BDKlasa.polaczBD();
            } catch (SQLException e) {
                e.printStackTrace();
            } catch (ClassNotFoundException e) {
                throw new RuntimeException(e);
            }
            HttpSession session = request.getSession(false);
            session.setAttribute("user", login);
            request.getRequestDispatcher("hello.jsp").forward(request, response);
        }
        else {
            request.setAttribute("loginError","Invalid user/password!");
            request.getRequestDispatcher("index.jsp").forward(request, response);
        }



    }
}
