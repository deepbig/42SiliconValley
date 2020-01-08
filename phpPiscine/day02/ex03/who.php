#!/usr/bin/php
<?php

// $tab = file("/var/run/utmpx");

// print_r($tab);

$file = fopen("/var/run/utmpx", "r"); 
while ($utmpx = fread($file, 628)){ 
$unpack = array_filter(unpack("a256a/a4b/a32c/id/ie/I1f/", $utmpx));
$array[] = $unpack;
}

$i = 0;

date_default_timezone_set('America/Los_Angeles');
foreach ($array as $elem)
{
    if ($i > 1)
    {
        echo str_pad(trim($elem['a']), 9, " ").str_pad(trim($elem['c']), 9, " ");
        
        echo date("M", $elem['f'])." ".date("d", $elem['f'])." ".date("H:i", $elem['f']);

        echo "\n"; 
    }
    $i++;
}
//print_r(array_filter($array));
//print_r($array);
?>