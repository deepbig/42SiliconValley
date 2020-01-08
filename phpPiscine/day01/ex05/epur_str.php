#!/usr/bin/php
<?php

if ($argc != 2)
{
    return ;
}
$array = array_filter(explode(" ", $argv[1]));

$str = "";
foreach ($array as $elem)
{
    $str = $str.$elem." ";
}

$str = trim($str, " ");
echo "$str\n";
?>