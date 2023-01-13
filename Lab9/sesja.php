<?php
    session_start();
    if (!isset($_SESSION['our_own']))
    {
        session_regenerate_id();
        $_SESSION['our_own'] = true;
    }
    echo 'ID: '.session_id().'<br />';
    if (isset($_GET['PHPSESSID']))
        echo 'PHPSESSID: '.$_GET['PHPSESSID'].'<br />';
?>