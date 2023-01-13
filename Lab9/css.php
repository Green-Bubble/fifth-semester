<form action="css.php" method="post">
 <textarea name="tekst"></textarea><br />
 <input type="submit" name="wyslij" value="Wyślij" />
</form>
<div>
<?php
 if (filter_input(INPUT_POST,'wyslij'))
 echo ($_POST['tekst'])."</br>";
 echo htmlspecialchars($_POST['tekst'])."</br>";
 echo strip_tags($_POST['tekst'])."</br>";
 echo filter_input(INPUT_POST,'tekst',FILTER_SANITIZE_FULL_SPECIAL_CHARS,FILTER_SANITIZE_STRING)."</br>";
?>
</div>