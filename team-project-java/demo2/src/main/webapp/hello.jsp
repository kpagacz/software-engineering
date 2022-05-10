<%--
  Created by IntelliJ IDEA.
  User: user
  Date: 23.04.2022
  Time: 22:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Welcome!</title>
</head>
<body>
<%
    session = request.getSession(false);
    if (session.getAttribute("user")==null) {
        response.sendRedirect("index.jsp");
    }
%>

Hello <b><i>${sessionScope.user}</i></b>
<br>
<a href="logout-servlet"><i>logout</i></a>
<br><br>
Very confidental content of the page!
</body>
</html>
