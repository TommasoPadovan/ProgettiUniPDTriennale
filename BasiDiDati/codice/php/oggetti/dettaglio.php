<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();
$conn=connect();

$_SESSION['to_det_item']='../oggetti/dettaglio.php?item_name='.$_GET['item_name'];

page_start('Dettagli di '.$_GET['item_name'],'../librerie/style.css');

	#generale
	$query=det_oggetto1($_GET['item_name']);
	$det_item=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
	br();
	tabularize($det_item);

	#passivo/attivo + bonus
	br(2);
	$query=det_oggetto2($_GET['item_name']);
	$det_item=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
	$d=mysql_fetch_assoc($det_item);
	$query=disp_oggetto($_GET['item_name']);
	$disp_item=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));


	paragraph("L'oggetto &egrave di tipo <b>".$d['tipo'].'</b>');

	$str= '&Egrave disponibile presso: ';
	for ($i=0; $i<mysql_num_rows($disp_item) ; $i++) { 
		$di=mysql_fetch_row($disp_item);
		$str=$str.$di[0].', ';
	}
	$str=substr($str,0,strlen($str)-2);
	paragraph($str);

	br();

	if ($d['tipo']=='Attivo') {
		$query=eff_attivi($_GET['item_name']);
		$effettoAttivo=mysql_query($query,$conn)
			or die("Query Fallita ".mysql_error($conn));
	}

	if (isset($d['bonus_str']) or isset($d['bouns_agl']) or isset($d['bonus_int']) or isset($d['bonus_atk'])) {
		paragraph('Inoltre garantisce i seguenti bonus:');
		formattazione_start(); riga_start();
			area_start();
				table_start();
					table_row(array('<b>Strenght</b>',$d['bonus_str']));
					table_row(array('<b>Agility</b>',$d['bonus_agl']));
					table_row(array('<b>Intelligence</b>',$d['bonus_int']));
					table_row(array('<b>Attack</b>',$d['bonus_atk']));
				table_end();
			area_end();
			if ($d['tipo']=='Attivo') {
				area_start(); pad(25); area_end();
				area_start();
					formattazione_start();
						riga_start(); area_start();
							b('Effetto Attivo');
						area_end(); riga_end();
						riga_start(); area_start();
							tabularize($effettoAttivo);
						area_end(); riga_end();
					formattazione_end();
				area_end();
			}

		riga_end(); formattazione_end();
	}
	else paragraph('Non da alcun bonus base');


	#eroi che ce l'hanno
	br();
	paragraph("Eroi che hanno nell'inventario un <i>".$_GET['item_name'].'</i>');
	$query=hero_has($_GET['item_name']);
	$heroes=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
	if (mysql_num_rows($heroes)<=0) {
		echo '<i>Nessuno</i>';
	} else {
		table_start();
			for ($i=0; $i<mysql_num_rows($heroes) ; $i++) { 
				echo '<tr>';
				$h=mysql_fetch_row($heroes);
				echo '<td>';
				simple_link('../eroi/dettaglio.php?nome='.$h[0].'&flagitem=on',$h[0]);			//è praticamente un doppio magic link
				echo '</td></tr>';
			}
		table_end();
	}

	br(2);
	if (isset($_GET['flageroi'])) simple_link($_SESSION['to_det_eroi_from_oggetti'],'Indietro');
	else button_link('riep.php','<- Indietro');


page_end();


?>