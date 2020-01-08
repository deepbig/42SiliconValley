<?php

session_start();
// containst a form allowing to create modify is uername and passworld
if (isset($_GET["login"]) && $_GET["login"] !== NULL && isset($_GET["passwd"]) && $_GET["passwd"] !== NULL && isset($_GET["submit"]) && $_GET["submit"] === "OK")
{
    $_SESSION["login"] = $_GET["login"];
    $_SESSION["passwd"] = $_GET["passwd"];
}

?>
<html><body>
<form action="/index.php" method="get">
    Username: <input type="text" name="login" value="<?php echo $_SESSION["login"]?>" />
    <br />
    Password: <input type="text" name="passwd" value="<?php echo $_SESSION["passwd"]?>" />
    <input type="submit" value="OK" />
</form>
</body></html>