<?php
//if i have to check the elem, I can use end(). but it is not allowed function. Therefore, I guess it is not required part.

switch ($_GET["action"]) {
    case "set":
        if (isset($_GET["name"]) && isset($_GET["value"]))  
            setcookie($_GET["name"], $_GET["value"], time() + 3600);
        break;
    case "get":
        if (isset($_COOKIE[$_GET["name"]]))
            echo $_COOKIE[$_GET["name"]]."\n";
        break;
    case "del":
        if (isset($_GET["name"]))
            setcookie($_GET["name"], "", 0);
        break;

}

?>