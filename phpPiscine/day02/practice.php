#!/usr/bin/php
<?php

// $nb = preg_match("/^t[^0-9]{4}t[a-z]$/", "tto");

// // '/' is just shows it is pattern
// // '^' is meaning it is first character
// // '$' is meaning it is last character 
// // [ ] is meaning ether 'o' or 'i' ;
// // +, * ([ ]char can be found 0 to any number of time)
// // {} specific number of chars.
// // inside [^something] meanings everything but elems inside not work.

// $nb = preg_match("/t([io])t\1/", "titi");

// // ( [ ] ) and \1 will check and match the char used.

// echo "$nb\n";

//////////////////////////////////////////////////

// $name = "key";
// $$name = "val";
// //$($name = "key") = "val";
// echo "$key\n";

///////////////////////////////////////////////

// $tab = file("data.csv");

// foreach ($tab as $elem)
// {
//     echo "$elem";
// }

// // or  file_get_contents

// // fopen, fgets  (this will get line by line)

// $fd = fopen("data.csv", "r");

// while ($line = fgets($fd))
// {
//     echo "$line";
// }

// //fgetcsv

// while ($tab = fgetcsv($fd, 0, ";"))  //by default, the deliminator is ","
// {
//     print_r($tab);
// }

/////////////////////////////////////////////////////

// //eval

// eval("echo 'Hello World\n';");

//////////////////////////////////////////////

// if (0 === "World")  // "===" is calculate in int not str.. so use ===
//     echo "OK\n";
// else
//     echo "KO\n";


// $my_tab = array("zero", "un", "deux");

// if (array_search("zero", $my_tab) !== FALSE)
//     echo "Found\n";


// // Curl

$c = curl_init("e");

$str = curl_exec($c);

echo "$str";

?>