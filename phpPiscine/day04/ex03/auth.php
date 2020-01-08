<?php
function auth($login, $passwd) {
    if (!$login || !$passwd)
        return false;
    $info = unserialize(file_get_contents('../private/passwd'));
    if ($info) {
        foreach ($info as $k => $v) {
            if ($v['login'] === $login && $v['passwd'] === hash('whirlpool', $passwd))
                return true;
        }
    }
    return false;
}
?>
