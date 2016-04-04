<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();
$conn=connect();

page_start('Eroi','../librerie/style.css');
	paragraph('Questi sono gli eroi presenti nel database.');
	paragraph('click sul nome per vedere i dettagli');

	$query=$riep_eroi;
	$all_heroes=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));

	if ($_SESSION['id']=='admin') {
		table_start();
			for ($i=0; $i<mysql_num_rows($all_heroes) ; $i++) { 
				$row=mysql_fetch_assoc($all_heroes);
				$row[' ']=magic_link('delete.php',$row['Nome'],'nome',1,'del');
				if ($i==0) table_heading($row);
				magic_row($row,'dettaglio.php','Nome','nome');
			}
		table_end();

		br();
		button_link('new.php',' + ');
	}
	else {
		# tabella magica riep eroi
		br(3);
		magic_table($all_heroes,'dettaglio.php','Nome','nome');
	}

	# indietro
	br(3);
	button_link('../home/home.php','<- Indietro');


page_end();




?>