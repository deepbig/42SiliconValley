#!/usr/bin/php
<?php

if ($argc < 2)
    exit ();

function grab_image($url,$saveto){
    $ch = curl_init ($url);
    curl_setopt($ch, CURLOPT_HEADER, 0);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_BINARYTRANSFER, 1);
    $raw=curl_exec($ch);
    curl_close ($ch);
    $fp = fopen($saveto,'x');
    fwrite($fp, $raw);
    fclose($fp);
}

// function get_image($url, $html) {
    
// }

function create_folder($url) {
    if (file_exists($url) && is_dir($url))
    {
        echo "Same folder alredy exists! Remove it first!";
        exit ();
    }
    mkdir($url);
}


$c = curl_init($argv[1]);

$str = curl_exec($c);
if ($str === FALSE)
{
    echo "Website does not exist...";
    curl_close($c);
    exit ();
}

curl_close($c);
//get_image($argv[1], $str);
create_folder($argv[1]);
grab_image($argv[1], $argv[1]);

?>
