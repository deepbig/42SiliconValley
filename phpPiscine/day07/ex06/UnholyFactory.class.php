<?php

class UnholyFactory {
    
    private $list_army = array();

    public function absorb($property) {
        if ($property instanceof Fighter) {
            if ($this->already_add($property) == True) {
                print ("(Factory already absorbed a fighter of type " . $property->name . ")" . PHP_EOL);
            } else {
                array_push($this->list_army, $property);
                print ("(Factory absorbed a fighter of type " . $property->name . ")" . PHP_EOL);
            }
        } else {
            print ("(Factory can't absorb this, it's not a figher)" . PHP_EOL);
        }
    }

    private function already_add($check) {
        foreach ($this->list_army as $elem) {
            if ($elem == $check)
                return True;
        }
        return False;
    }

    public function fabricate($fighter) {
        foreach ($this->list_army as $elem) {
            if ($elem->name == $fighter) {
                print ("(Factory fabricates a fighter of type " . $fighter . ")" . PHP_EOL);
                return $elem;
            }
        }
        print ("(Factory hasn't absorbed any fighter of type " . $fighter . ")" . PHP_EOL);
        return ;
    }
}

?>