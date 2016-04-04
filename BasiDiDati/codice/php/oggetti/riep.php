<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();
$conn=connect();

page_start('Oggetti','../librerie/style.css');
	$query=$riep_oggetti;

	$all_items=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));

	br(3);
	if ($_SESSION['id']=='admin') {	
		table_start();
			for ($i=0; $i<mysql_num_rows($all_items) ; $i++) { 
				$row=mysql_fetch_assoc($all_items);
				$row[' ']=magic_link('delete.php',$row['Nome'],'item_name',1,'del');
				if ($i==0) table_heading($row);
				magic_row($row,'dettaglio.php','Nome','item_name');
			}
		table_end();

	
		br();
		button_link('new.php','+');
	}
	else {
		magic_table($all_items,'dettaglio.php','Nome','item_name');
	}

	# indietro
	br(3);
	button_link('../home/home.php','<- Indietro');
page_end();



?>