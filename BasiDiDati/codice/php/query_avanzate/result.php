<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/advanced_query.php');
session_start();
$conn=connect();

switch ($_GET['query']) {
	case '1':
		$query=query1($_POST['nome_eroe']);
		break;
	case '2':
		$query=query2($_POST['CD'], $_POST['mana']);
		break;
	case '3':
		$query=query3();
		break;
	case '4':
		$query=query4();
		break;
	case '5':
		$query=query5($_POST['char']);
		break;
	case '6':
		$query=query6();
		break;
	default:
		$query=null;
		break;
}

$result=mysql_query($query,$conn)
	or die("Query Fallita ".mysql_error($conn));



page_start('Query '.$_GET['query'],'../librerie/style.css');
	echo ('<pre>'.$query.'</pre>');
	tabularize($result);
	br(2);
	button_link('index.php','Indietro');
page_end();



?>