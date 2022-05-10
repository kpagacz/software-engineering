<%@ page import="java.io.PrintWriter" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Log in page</title>
</head>
<body>
<h5>Enter login or password</h5>
<form action="login-servlet" method="post">
    login: <input type="text" name="textLogin" width="25">
    password: <input type="password" name="textPasswd" width="20">
    <input type="submit" value="log in">
</form>

<p style="color:red">${loginError}</p>
<p style="color:green">${message}</p>

</body>
</html>