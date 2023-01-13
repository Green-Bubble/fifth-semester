<?php
include_once 'Baza.php';
$ob = new Database('test');
if (isset($_POST['id']))
    if ($ob->executeSQL('DELETE FROM strony WHERE id="'.$ob->protect_int($_POST['id']).'"'))
        echo 'Skasowano rekord o id='.$_POST['id'];
    else
        echo 'Nie można skasować rekordu!';
?>