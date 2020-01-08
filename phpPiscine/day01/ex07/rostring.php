#!/usr/bin/php
<?php
if ($argc < 2)
    return ;
$argv[1] = trim($argv[1]);
$array = array_filter(explode(" ", $argv[1]));
$count = count($array);
$i = 0;
foreach($array as $elem)
{
    if ($i != 0)
        echo "$elem ";
    $i++;
}
if ($i == $count)
    echo "$array[0]\n";
?>