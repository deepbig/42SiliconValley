#!/usr/bin/php
<?php

if ($argc != 2)
    return ;
$count = 0;
$total = 0;
$array = [];
$fd = fopen("php://stdin", "r");
while ($tab = fgetcsv($fd, 0, ";"))
{
    if ($argv[1] === "moyenne")
    {
        if($tab[2] !== "moulinette" && is_numeric($tab[1])) {
            $total += $tab[1];
            $count++;
        }
    }
    $array[] = $tab;
}
if ($argv[1] === "moyenne")
{
    echo ($total / $count)."\n";
    return ;
}

sort($array);
$check = $array[1];
$total = 0;
$count = 0;
$pass = 0;
if ($argv[1] === "moyenne_user")
{
    foreach ($array as $elem)
    {
        if ($pass++ != 0)
        {
            if ($elem[0] === $check[0])
            {
                if (is_numeric($elem[1]) && $elem[2] !== "moulinette")
                {
                    $total += $elem[1];
                    $count++;
                }
            }
            else {

                echo $check[0].":".($total/$count)."\n";
                if (is_numeric($elem[1]))
                    $total = $elem[1];
                else 
                    $total = 0;
                $count = 0;
                $check[0] = $elem[0];
                $check[1] = $elem[1];
                $check[2] = $elem[2];
            }
        }
    }
    echo $check[0].":".($total/$count)."\n";
}
else if ($argv[1] === "ecart_moulinette")
{
    $check = $array[1];
    $total = 0;
    $count = 0;
    $pass = 0;
    $mou_score = 0;
    foreach ($array as $elem)
    {
        if ($pass++ != 0)
        {
            if ($elem[0] === $check[0])
            {
                if (is_numeric($elem[1]) && $elem[2] !== "moulinette")
                {
                    $total += $elem[1];
                    $count++;
                }
                else if ($elem[2] === "moulinette")
                {
                    $mou_score = $elem[1];
                }
            }
            else {
                echo $check[0].":".($total/$count - $mou_score)."\n";
                if (is_numeric($elem[1]))
                    $total = $elem[1];
                else 
                    $total = 0;
                $count = 0;
                $check[0] = $elem[0];
                $check[1] = $elem[1];
                $check[2] = $elem[2];
            }
        }
    }
    echo $check[0].":".($total/$count - $mou_score)."\n";
}
else
    return ;
?>
