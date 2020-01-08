#!/usr/bin/php
<?php

if ($argc < 2)
    return ;
// $argv[1] = trim($argv[1]);
// $array = array_filter(explode(" ", $argv[1]));

// $count = count($array);
// $i = 1;
// foreach ($array as $elem)
// {
//     echo $elem;
//     if ($i++ != $count)
//         echo " ";
// }
// echo "\n";

$pattern = '/[ \t]+/';
echo trim(preg_replace($pattern, " ", $argv[1]))."\n";

?>