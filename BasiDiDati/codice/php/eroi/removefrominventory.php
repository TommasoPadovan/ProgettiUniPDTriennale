<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();
$conn=connect();

$query=remove_item_from_inv($_GET['nome_eroe'],$_GET['markfordeath']) ;
$r=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));

header('Location: dettaglio.php?nome='.$_GET['nome_eroe']);

?>