<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();
$conn=connect();

page_start('Aggiungi Ogetto', '../librerie/style.css');
	$query='select nome from Oggetti;';
	$result=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));

	$arrCoppieRadio=array();
	for ($i=0; $i<mysql_num_rows($result) ; $i++) {
		$row=mysql_fetch_row($result);
		$arrCoppieRadio[$row[0]]=$row[0];
	}

	form_start('process_additem.php?nome='.$_GET['nome'],'post');
		paragraph('scegli l\'oggetto da inserire');
		radiobutton('dainserire',$arrCoppieRadio);
		submit('avanti');
	form_end();
page_end();


?>