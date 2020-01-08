<?php

if (isset($_POST["login"]) && $_POST["login"] !== NULL && isset($_POST["passwd"]) && $_POST["passwd"] !== NULL && isset($_POST["submit"]) && $_POST["submit"] === "OK") 
{
    if (file_exists('../private') === FALSE)
    {
        mkdir("../private");
        file_put_contents('../private/passwd', null);
    } 
    else if (file_exists('../private/passwd') === FALSE)
        file_put_contents('../private/passwd', null);

    $info = unserialize(file_get_contents('../private/passwd'));
    if ($info)
    {
        $test = 0;
        foreach($info as $key => $value)
        {
            if ($value["login"] === $_POST["login"])
                $test = 1;
        }
    }
    if ($test)
        echo "ERROR\n";
    else 
    {
        $tmp['login'] = $_POST['login'];
        $tmp['passwd'] = hash('whirlpool', $_POST['passwd']);
        $info[] = $tmp;
        file_put_contents('../private/passwd', serialize($info));
        echo "OK\n";
    }
}
else
    echo "ERROR\n";

?>