<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();
$conn=connect();

if (1<=$_POST['livello'] && $_POST['livello']<=25) {
	$query=cambia_livello($_POST['nome_eroe'],$_POST['livello']);
	$r=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
}

header('Location: dettaglio.php?nome='.$_POST['nome_eroe']);
?>