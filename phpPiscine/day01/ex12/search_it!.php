#!/usr/bin/php
<?php

if ($argc < 3)
    return ;

$count = 0;
$array = [];
foreach ($argv as $elem)
{
    if ($count > 1)
    {
        $sub = explode(":", $elem);
        if (count($sub) != 2)
            exit();
        foreach ($sub as $elem2)
        {
            $elem2 = trim($elem2);
            array_push($array, $elem2);
        }
    }
    $count++;
}
$count = 0;
$res = -1;
$argv[1] = trim($argv[1]);
foreach ($array as $elem3)
{
    if ($count % 2 == 0)
    {
        if ($elem3 == $argv[1])
        {
            $res = -1 + $count + 2;
        }
    }
    $count++;
}
if ($res == -1)
    exit();
echo $array[$res]."\n";

?>