<?php

function ft_split($fstr)
{
    $array = array_filter(explode(" ", $fstr));
    sort($array);
    return $array;
}

?>