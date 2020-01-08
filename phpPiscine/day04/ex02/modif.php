<?php

if (isset($_POST["login"]) && $_POST["login"] !== NULL && isset($_POST["oldpw"]) && isset($_POST["newpw"]) && $_POST["newpw"] !== NULL && isset($_POST["submit"]) && $_POST["submit"] === "OK") 
{
    if (file_exists('../private/passwd') === FALSE)
    {
        echo "ERROR\n";
        return ;
    }


    $info = unserialize(file_get_contents('../private/passwd'));
    if ($info)
    {
        $test = 0;
        foreach($info as $key => $value)
        {
            if ($value["login"] === $_POST["login"] && $value["passwd"] === hash('whirlpool', $_POST['oldpw']))
            {
                $test = 1;
                $info[$key]['passwd'] = hash('whirlpool', $_POST['newpw']);
            }
        }
    }
    else
    {
        echo "ERROR\n";
        return ;
    }
    if ($test)
    {
        file_put_contents('../private/passwd', serialize($info));
        echo "OK\n";
    } 
    else
    {
        echo "ERROR\n";
        return ;
    }

}
else
    echo "ERROR\n";

?>