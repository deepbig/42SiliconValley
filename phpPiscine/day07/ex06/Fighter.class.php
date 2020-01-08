<?php

//list of figher
abstract class Fighter {

    public $name;

    public function __construct($name) {
        $this->name = $name;
    }

    abstract function fight($tg);

}


?>