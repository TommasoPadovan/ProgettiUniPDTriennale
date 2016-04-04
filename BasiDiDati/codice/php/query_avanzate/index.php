<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
session_start();
$conn=connect();

page_start('Query Avanzate','../librerie/style.css');
	paragraph('In questa sezione sono presenti query e funzionalit&agrave pi$ugrave specifiche');
	form_start('result.php?query=1','post');
		echo "<b>Query1</b>";
		br();
		echo "Mostra per ";
		$query="select nome from Eroi";
		$hero=mysql_query($query,$conn)
			or die("Query Fallita ".mysql_error($conn));
		$arrHero=array();
		for ($i=0; $i<mysql_num_rows($hero) ; $i++) {
			$a=mysql_fetch_row($hero);
			array_push($arrHero,$a[0]);
		}
		tendina('nome_eroe', $arrHero); 
		echo " il numero di oggetti posseduti ed il loro costo totale";
		br();
		submit('->');	
	form_end();

	hr(1);

	form_start('result.php?query=2','post');
		echo "<b>Query2</b>";
		br();
		echo "Tutti gli oggetti (mostrando nome, costo e descrizione) che hanno effetto attivo, il cui costo di mana sia superiore a ";
		text('CD');
		echo " e CD più lungo di ";
		text('mana');
		br();
		submit('->');	
	form_end();

	hr(1);

	form_start('result.php?query=3','post');
		echo "<b>Query3</b>";
		br();
		echo "Costo totale di mana di \"tutta la rotation di spell\" (=tutte le magie una immediatamente dopo l'altra) di ogni eroe che ha solo spell attive, considerando le spell al massimo livello";
		br();
		submit('->');	
	form_end();

	hr(1);

	form_start('result.php?query=4','post');
		echo "<b>Query4</b>";
		br();
		echo "Eroi la cui spell con CD più alto (a qualsiasi livello) ha CD maggiore dell'oggetto più lento a ricaricarsi posseduto dallo stesso eroe";
		br();
		submit('->');	
	form_end();

	hr(1);

	form_start('result.php?query=5','post');
		echo "<b>Query5</b>";
		br();
		echo "Il negozio che ha venduto ad eroi il cui nome compicia per ";
		text('char');
		echo " il maggior numero di oggetti aventi effetti attivi";
		br();
		submit('->');	
	form_end();

	hr(1);

	form_start('result.php?query=6','post');
		echo "<b>Query6</b>";
		br();
		echo "Eroi, media dei tempi d'attesa delle spell a livello masssimo, solo se i la media di tempi di attesa a livello 1 è più lunga delle spell maxate";
		br();
		submit('->');	
	form_end();


	br(3);
	button_link('../home/home.php', 'Indietro');

page_end();