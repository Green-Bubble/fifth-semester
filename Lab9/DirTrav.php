<?php
function download($patch = '.')
{
    $katalog = @dir($patch) or die ('Brak dostępu do katalogu.');
    while ($plik_kat = $katalog->read())
    if(is_file($patch.'/'.$plik_kat))
        echo '<a href="'.$patch.'/'.$plik_kat.'">'.$plik_kat.'</a><br />';
    elseif (is_dir($patch.'/'.$plik_kat)) {
        echo '<a href="DirTrav.php?patch='.$patch.'/'.$plik_kat.'">'.$plik_kat.'</a>
        <br />';
    }
        $katalog->close();
}
if (!isset($_GET['patch']))
    download();
else
    download(str_replace('..','',$_GET['patch']));
?>