#!/usr/bin/php
<?php

if ($argc < 2)
{
    echo "Wrong Format! Please use this format: './magnifying_glass.php <your_file_name>'.\n";
    return ;
} else if (file_exists($argv[1]) == FALSE)
{
    echo "File does not exist! Please check your file name!\n";
    return ;
}

$tab = file($argv[1]);
$array = "";

foreach ($tab as $elem)
{
    $array .= $elem;
}

$pattern1 = "/(<a )(.*?)(>)(.*)(<\/a>)/s";

$new = preg_replace_callback($pattern1, function($matches) 
{
    $matches[0] = preg_replace_callback("/(title=\")(.*?)(\")/", function($matches)
    {
        return $matches[1].strtoupper($matches[2]).$matches[3];
    }, $matches[0]);
    $matches[0] = preg_replace_callback("/(>)(.*?)(<)/s", function($matches)
    {
        return $matches[1].strtoupper($matches[2]).$matches[3];
    }, $matches[0]);
    return ($matches[0]);
}, $array);
echo $new;

?>