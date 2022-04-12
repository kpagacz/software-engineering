<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 14.05.2020
  Time: 14:21
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>logowanie do aplikacji</title>
</head>
<p>
<p> <b>Prosze podac login i haslo: </b></p>
<form action="Logowanie" method="post">
    login: <input type="text" name="tekst_login" width="25"/>
    haslo: <input type="password" name="tekst_haslo" width="25"/>
    <input type="submit" value="zaloguj"/>
</form>

<p style="color:red"> ${blad} </p>
</body>
</html>
