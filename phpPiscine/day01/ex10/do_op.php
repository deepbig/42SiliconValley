#!/usr/bin/php
<?php

if ($argc != 4)
{
    echo "Incorrect Parameters\n";
    return ;
}

$count = 0;
$array = [];
foreach ($argv as $elem)
{
    if ($count++ != 0)
    {
        $sub = trim($elem);
        array_push($array, $sub);
    }
}
if ($array[1] == '+')
    echo $array[0]+$array[2]."\n";
if ($array[1] == '-')
    echo $array[0]-$array[2]."\n";
if ($array[1] == '*')
    echo $array[0]*$array[2]."\n";
if ($array[1] == '/')
    echo $array[0]/$array[2]."\n";
if ($array[1] == '%')
    echo $array[0]%$array[2]."\n";
?>