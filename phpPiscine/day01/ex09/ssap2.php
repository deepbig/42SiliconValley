#!/usr/bin/php
<?php
function ssap2_sort($x, $y) {
    $i = 0;
    $guide = "abcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~";
    while ($i < strlen($x) || $i < strlen($y))
    {
        $x_index = stripos($guide, $x[$i]);
        $y_index = stripos($guide, $y[$i]);
        if ($x_index < $y_index)
            return (-1);
        else if ($x_index > $y_index)
            return (1);
        else
            $i++;
    }
    if ($x == $y)
        return 0;
    else if ($x < $y)
        return -1;
    else
        return 1;
}

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

usort($res, "ssap2_sort");
//natcasesort($res);
foreach ($res as $elem)
{
    echo "$elem\n";
}
?>