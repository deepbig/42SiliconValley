<?php

if ($_SERVER['PHP_AUTH_USER'] === "zaz" && $_SERVER['PHP_AUTH_PW'] === "jaimelespetitsponeys")
{
    $src = base64_encode(file_get_contents("../img/42.png"));
    $size = filesize($src);
    echo "<html><body>\n";
    echo "Hello Zaz<br />\n";
    echo "<img src='data:image/png;base64,$src'>\n";
    echo "</body></html>\n";
} else {
   header("HTTP/1.0 401 Unauthorized");
    $txt = "<html><body>That area is accessible for members only</body></html>\n";
    
    header("WWW-Authenticate: Basic realm=''Member area''");
    $len = mb_strlen($txt);

    header("Server: Apache");
   //header("Content-length: 72");
    header("Content-length: $len");
    header("X-Powered-By: PHP/5.4.26");
   //header("Date: Tue, 26 Mar 2013 09:42:42 GMT");
   //header("Content-Type: text/html");

    echo $txt;
}

?>