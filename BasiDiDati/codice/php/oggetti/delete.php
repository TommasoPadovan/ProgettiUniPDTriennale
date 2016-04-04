<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();

if ($_SESSION['id']=='admin') {
	$conn=connect();

	$mark_for_death=$_GET['item_name'];

	$query="delete from Oggetti where nome=\"$mark_for_death\"";

	mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));

	page_start('Eliminazione oggetto','../librerie/style.css');
		paragraph('Eliminazione di '.$mark_for_death.' avvenuta con successo');
		br(2);
		button_link('riep.php','Indietro');
	page_end();
}
else {
	forbidden('../librerie/style.css','../home/home.php');
}





?>