#!/usr/bin/php
<?php

if ($argc != 2)
{
    echo "Incorrect Parameters\n";
    return ;
}

$array = [];

if (stripos($argv[1], '+') != NULL)
    $sub = explode('+', $argv[1]);
else if (stripos($argv[1], '-') != NULL)
    $sub = explode('-', $argv[1]);
else if (stripos($argv[1], '*') != NULL)
    $sub = explode('*', $argv[1]);
else if (stripos($argv[1], '/') != NULL)
    $sub = explode('/', $argv[1]);
else if (stripos($argv[1], '%') != NULL)
    $sub = explode('%', $argv[1]);
else
{
    echo "Syntax Error\n";
    return ;
}

foreach ($sub as $elem)
{
    array_push($array, trim($elem));
}

foreach ($array as $elem)
{
    if (is_numeric($elem) == FALSE)
    {
        echo "Syntax Error\n";
        return ;
    }
}

if (stripos($argv[1], '+') != NULL)
    echo $array[0] + $array[1];
else if (stripos($argv[1], '-') != NULL)
    echo $array[0] - $array[1];
else if (stripos($argv[1], '*') != NULL)
    echo $array[0] * $array[1];
else if (stripos($argv[1], '/') != NULL)
    echo $array[0] / $array[1];
else if (stripos($argv[1], '%') != NULL)
    echo $array[0] % $array[1];
else
    echo "Syntax Error";
echo "\n";
?>