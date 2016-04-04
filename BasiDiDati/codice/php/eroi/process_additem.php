<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();
$conn=connect();

$query="select nome from Oggetti;";
$result=mysql_query($query,$conn)
	or die("Query Fallita ".mysql_error($conn));
for ($i=0; $i < mysql_num_rows($result) ; $i++) { 
	$obj=mysql_fetch_row($result);
	if ($_POST['dainserire']==$obj[0]) header('Location: dettaglio.php?nome='.$_GET['nome']);
}


$query=ins_inventario($_GET['nome'],$_POST['dainserire']);
$result=mysql_query($query,$conn)
	or die("Query Fallita ".mysql_error($conn));

header('Location: dettaglio.php?nome='.$_GET['nome']);
?>
