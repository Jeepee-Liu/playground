<!DOCTYPE html>
<!--
    If you see this line,
    it means that the server doesn't support ASP either.
    SO SAD!!!
-->
<html>
<body>
Welcome
<%
response.write(request.form("firstname"))
response.write(" " & request.form("lastname"))
response.write("\n" & request.form("email"))
response.write("\n" & request.form("message"))
%>
</body>
</html>
