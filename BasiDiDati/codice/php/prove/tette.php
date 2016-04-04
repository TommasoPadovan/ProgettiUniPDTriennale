<?php
require_once('../librerie/html_lib.php');

page_start("Tette Grosse","../librerie/style.css");
$host='127.0.0.1';
$user='root';
$psw='';
$conn=mysql_connect($host,$user,$psw)
	or die($_SERVER['PHP_SELF']."connessione fallita!");

$DBname='DotaDB';
mysql_select_db($DBname);

$query="select * from Eroi";

$eroi=mysql_query($query,$conn)
	or die("query fallita".mysql_error($conn));

tabularize($eroi);

page_end();
 ?>



