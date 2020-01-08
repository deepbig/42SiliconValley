#!/usr/bin/php
<?php
if ($argc < 2)
    return ;
$count = 0;
$res = [];
foreach ($argv as $elem)
{
    if ($count++ != 0)
    {
        $sub = array_filter(explode(" ", $elem));
        foreach ($sub as $elem2)
        {
            array_push($res, $elem2);
        }
    }
}
sort($res);
foreach ($res as $elem)
{
    echo "$elem\n";
}
?>