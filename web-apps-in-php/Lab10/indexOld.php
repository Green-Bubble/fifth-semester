<?php
require_once("../universal/classes/website.php");
$strona_akt = new Website();
//sprawdź co wybrał użytkownik:
if (filter_input(INPUT_GET, 'strona')) {
    $strona = filter_input(INPUT_GET, 'strona');
    switch ($strona) {
        case 'galeria':
            $strona = 'galeria';
            break;
        case 'formularz':
            $strona = 'formularz';
            break;
        case 'onas':
            $strona = 'onas';
            break;
        default:
            $strona = 'glowna'; 
    }
} else {
 $strona = "glowna";
}

$plik = "scripts/" . $strona . ".php";
//var_dump($plik);
if (file_exists($plik)) {
 require_once($plik);
 $strona_akt->set_title($tytul);
 $strona_akt->set_content($zawartosc);
 $strona_akt->show();
}