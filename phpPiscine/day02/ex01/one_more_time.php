#!/usr/bin/php
<?php

if ($argc != 2)
    return ;

$w = array(
    1 => "lundi",
    2 => "mardi",
    3 => "mercredi",
    4 => "jeudi",
    5 => "vendredi",
    6 => "samedi",
    7 => "dimanche");

$m = array(
    1 => "janvier",
    2 => "fevrier",
    3 => "mars",
    4 => "avril",
    5 => "mai",
    6 => "juin",
    7 => "juillet",
    8 => "aout",
    9 => "septembre",
    10 => "octobre",
    11 => "novembre",
    12 => "decembre");

date_default_timezone_set('Europe/Paris');

$date = array_filter(explode(" ", $argv[1]));
$pattern1 = "/^[1-9]$|^0[1-9]$|^[1-2][0-9]$|^3[0-1]$/";
$pattern2 = "/^[0-9]{4}$/";
$pattern3 = "/^([0-1][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]$/";
if (array_search(strtolower($date[0]), $w) === FALSE ||
    array_search(strtolower($date[2]), $m) === FALSE ||
    preg_match($pattern1, $date[1]) === 0 ||
    preg_match($pattern2, $date[3]) === 0 ||
    preg_match($pattern3, $date[4]) === 0 || count($date) != 5)
{
    echo "Wrong Format\n";
    return ;
}
$date[0] = array_search(strtolower($date[0]), $w);
$date[2] = array_search(strtolower($date[2]), $m);
$time = explode(":", $date[4]);
$print = mktime($time[0], $time[1], $time[2], $date[2], $date[1], $date[3]); //if you don't like the answer? please put "-3600" at the end!
if (date("N", $print) == $date[0])
    echo $print."\n";
else 
    echo "Wrong Format\n";
return ;

?>