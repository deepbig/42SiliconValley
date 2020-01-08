<?php

class NightsWatch implements IFighter {

    private $list = array();

    public function recruit($property) {
        if ($property instanceof Ifighter) {
            array_push($this->list, $property);
        }
        // if ($property instanceof JonSnow)
        //     echo "what is should print";
    }

    public function fight() {
        foreach ($this->list as $elem) {
            $elem->fight();
        }
    }
}

?>