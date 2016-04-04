<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();
$conn=connect();

page_start($_GET['spell_name'].': dettagli','../librerie/style.css');
	#generali
	$query=det_spell1($_GET['spell_name']);
	$det_spell=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
	tabularize($det_spell);

	#ability, affection, damage type
	br();
	$query=det_spell2($_GET['spell_name']);
	$det_spell=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
	tabularize($det_spell);


	# piercing, ultimate si/no, attiva/passiva
	$query=det_spell3($_GET['spell_name']);
	$det_spell=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
	$d=mysql_fetch_assoc($det_spell);

	br();
	if ($d['piercing']==1) paragraph('Questa spell &egrave in grado di superare l\'<b>immunit&agrave alla magia</b>');
	else paragraph('Questa spell &egrave bloccata dall\'<b>immunit&agrave alla magia</b>');

	if ($d['ultimate']==1) paragraph('Questa spell &egrave l\'<i><b>ultimate</b></i>, la pi&ugrave potente magia nel grimorio dell\'eroe.<br>
		Inoltre essa conta solo di 3 livelli anzich&eacute 4');


	br();
	if ($d['modalita']=='attiva')  {
		paragraph('Questa spell, inoltre deve essere attivata ed a seconda del suo livello le sue caratteristiche principali possono cambiare:');
		$query=det_lvl_spell($_GET['spell_name']);
		$det_lvl_spell=mysql_query($query,$conn)
			or die("Query Fallita ".mysql_error($conn));
		tabularize($det_lvl_spell);
	}
	else paragraph('Questa spell &egrave passiva, il suo livello da bonus avanzati, non trattati in questo DB.');


	# indietro
	br(2);
	simple_link($_SESSION['to_det_hero'],'Indietro');





page_end();



?>