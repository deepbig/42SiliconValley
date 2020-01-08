<?php

class Tyrion extends Lannister {
    function sleepWith($property) {
        if ($property instanceof Jaime || $property instanceof Cersei)
            print("Not even if I'm drunk !" . PHP_EOL);
        if ($property instanceof Sansa)
            print("Let's do this." . PHP_EOL);
    }
}

?>