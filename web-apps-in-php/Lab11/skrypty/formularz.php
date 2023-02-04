<?php
function loadContent()
{
    $zawartosc = '<form action="./index.php" method="post">
    <div class="basic-info">
        <div class="info-row"  id="surname-cont"><label for="surname">Nazwisko:</label> <input type="text" name="surname" id="surname"/> </div>
        <div class="info-row" id="age-cont"><label for="age">Wiek:</label><input type="number" name="age" id="age"/></div>
        <div class="info-row"><label for="country" >Państwo:</label> <select name="country" id="country">
            <option value="Polska">Polska</option>
            <option value="Niemcy">Niemcy</option>
            <option value="Wielka Brytania">Wielka Brytania</option>
            <option value="Czechy">Czechy</option>
        </select></div>
        <div class="info-row" id="email-cont"><label for="email">Adres e-mail:</label> <input type="email" name="email" id="email"></div>
    </div>
    
    <h4>Zamawiam tutorial z języka:</h4>
    <div class="buttons" id="service-cont">';

$languages = ["C","CPP","Java","C#","HTML","CSS","XML","PHP","JavaScript"];
for ($i = 0; $i < count($languages); $i++){
    $zawartosc .= "<input type='checkbox' name='languages[]' value='".$languages[$i]."' id='".$languages[$i]."'/> <label for='".$languages[$i]."'>".$languages[$i]."</label>";
}

$zawartosc .= '</div>
    <h4>Sposób zapłaty:</h4>
    <div class="buttons" id="payment-cont">
        <input type="radio" name="payment" value="Master Card" id="eu" /> <label for="eu">eurocard</label>
        <input type="radio" name="payment" value="Visa" id="visa" /> <label for="visa">visa</label>
        <input type="radio" name="payment" value="Przelew" id="transfer" /> <label for="transfer">przelew bankowy</label>
    </div>
    <input type="reset" value="Anuluj" />
    <input type="submit" name="submit" value="Zapisz" />
    <input type="submit" name="submit" value="Pokaż" />
    <input type="submit" name="submit" value="PHP" />
    <input type="submit" name="submit" value="CPP" />
    <input type="submit" name="submit" value="Java" />
    <input type="submit" name="submit" value="Stats" />
</form>
<div id="content"></div>';
    return $zawartosc;
}

$tytul = "<h1>Formularz zamowienia</h1>";
$zawartosc = loadContent();

echo $tytul;
echo $zawartosc;