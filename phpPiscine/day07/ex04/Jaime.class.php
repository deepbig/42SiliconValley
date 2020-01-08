<?php

class Jaime extends Lannister {
    function sleepWith($property) {
        if ($property instanceof Tyrion)
            print("Not even if I'm drunk !" . PHP_EOL);
        if ($property instanceof Sansa)
            print("Let's do this." . PHP_EOL);
        if ($property instanceof Cersei)
            print("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
    }
}

?>