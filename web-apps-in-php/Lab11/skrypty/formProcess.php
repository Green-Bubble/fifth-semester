<?php
$dc_root = $_SERVER['DOCUMENT_ROOT'];
include_once("$dc_root/universal/classes/database.php");
include_once("$dc_root/Lab11/skrypty/functions.php");
require_once("$dc_root/universal/env.php");

$bd = new Database("clients");

$zawartosc = "";

if(filter_input(INPUT_POST,"submit")){
    $choice = filter_input(INPUT_POST,"submit");
    switch($choice){
        case "Zapisz":
            $data = validate();
            $sql = "insert into clients values (NULL,'".$data['surname']."','".$data['age']."','".
            $data['country']."','".$data['email']."','".implode(",",$data['languages'])."','".$data['payment']."');";
            
            if(!$bd->executeSQL($sql)){
                echo "Wstawienie nieudane!</br>";
                echo "Should be: INSERT INTO clients VALUES (NULL, 'Marcin', '21', 'Polska','mail@pollub.edu.pl', 'C#,CPP', 'Przelew');</br>";
                echo $sql;
            }
            break;
        case "Pokaż":
            $zawartosc .= showSelectTable($bd->getSelectArray("select Nazwisko,Zamowienie,Wiek from clients"));
            break;
        case "PHP":
            $zawartosc .= showSelectTable($bd->getSelectArray("select Nazwisko,Zamowienie from clients where Zamowienie regexp 'PHP'"));
            break;
        case "CPP":
            $zawartosc .= showSelectTable($bd->getSelectArray("select Nazwisko,Zamowienie from clients where Zamowienie regexp 'CPP'"));
            break;
        case "Java":
            $zawartosc .= showSelectTable($bd->getSelectArray("select Nazwisko,Zamowienie from clients where Zamowienie regexp 'Java'"));
            break;
        case "Stats":

            $zawartosc .= "<p>Liczba wszystkich zamówień: ".count($bd->getSelectArray("select Nazwisko from clients"))."</p>";
            $zawartosc .= "<p>Liczba zamówień wiek < 18: ".count($bd->getSelectArray("select Nazwisko from clients where Wiek < 18"))."</p>";
            $zawartosc .= "<p>Liczba zamówień wiek > 49: ".count($bd->getSelectArray("select Nazwisko from clients where Wiek > 49"))."</p>";
            
            break;
    }
}

echo $zawartosc;