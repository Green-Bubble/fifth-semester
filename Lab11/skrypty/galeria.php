<?php
$tytul = "<h1>Galeria</h1>";
$zawartosc = "";
//$katalog=filter_input(INPUT_SERVER,'DOCUMENT_ROOT'."/mini");
$counter = 0;
$dc_root = $_SERVER['DOCUMENT_ROOT'];
$katalog="$dc_root/Lab11/mini/";

//var_dump($katalog);
$kat=@opendir($katalog) or die("Nie można otworzyć katalogu");
while ($plik = readdir($kat))
    if($plik != '.' && $plik != '..') {
        $zawartosc .= "<a href='./zdjecia/$plik'><img src='./mini/$plik' alt='$plik'></a>";
        $counter++;
    }
closedir($kat);

//echo '<a href="' . $_GET['pic'] . '.jpg">Zdjęcie</a><br/>';
//echo '<a href="mini-' . $_GET['pic'] . '.jpg"> Miniatura</a><br/><br/>';
$zawartosc .= "<br/>Liczba plików w galerii $counter<br/>";

echo $tytul;
echo $zawartosc;