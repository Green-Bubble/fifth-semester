<?php
include_once '../universal/classes/database.php';
$ob = new Database('test');
if (isset($_POST['id']))
{
 echo 'Wybrany:<br />';
 $id=$ob->protect_string($_POST['id']);
 echo 'SQL: SELECT tytul FROM strony WHERE id="'.$id.'";<br />';
 echo $ob->executeSQL('SELECT id,tytul FROM strony WHERE id="'.$id.'";',array('id','tytul'));
}

else
{
 echo '<form action="sql.php" method="post">';
 echo 'Wpisz numer ID do pokazania: <input type="text" name="id">';
 echo '<input type="submit" value="Uruchom"><br />';
 echo 'Wszystkie:<br />';
 echo $ob->executeSQL('SELECT id,tytul FROM strony;',array('id','tytul'));
}
?>