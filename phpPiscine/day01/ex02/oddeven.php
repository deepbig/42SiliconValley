#!/usr/bin/php
<?php
$stdin = fopen("php://stdin", "r");
while ($stdin && !feof($stdin))
{
    echo "Enter a number: ";
    $val = fgets($stdin);
    if ($val)
    {
        $val = str_replace("\n", "", $val);
        if (is_numeric($val))
        {
            if ($val % 2 == 0)
                echo "The number ".$val." is even\n";
            else
                echo "The number ".$val." is odd\n";
        }
        else
            echo "'".$val."' is not a number\n";
    }
}
fclose($stdin);
echo "\n";
?>
