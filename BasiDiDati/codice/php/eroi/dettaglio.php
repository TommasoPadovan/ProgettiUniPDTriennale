<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();
$conn=connect();

$_SESSION['to_det_eroi_from_oggetti']='../eroi/dettaglio.php?nome='.$_GET['nome'];  	//campi dell'array di sessione per tornare qui da quelle due
$_SESSION['to_det_hero']='dettaglio.php?nome='.$_GET['nome'];				//pagine distinte



page_start("Dettagli di ".$_GET['nome'],'../librerie/style.css');

	$query='select primary_attribute from Eroi where nome="'.$_GET['nome'].'";';
	$r=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
	$pa=mysql_fetch_row($r);

	switch ($pa[0]) {
		case 'str':
			paragraph($_GET['nome'].' &egrave un eroe <b>Forza</b>: quindi ha molti punti vita, e si pu&ograve rigenerare velocemente.
				Riuscedo cos&igrave a rimanere pi&ugrave a lungo in battaglia.<br>
				Gli Eroi Forza possono avere pi&ugrave ruoli anche se la maggior parte sono Eroi da Corpo a Corpo.');
			break;
		case 'agl':
			paragraph($_GET['nome'].' &egrave un eroe <b>Agilit&agrave</b>.
				Gli Eroi Agilit&agrave sono veloci e scaltri maestri delle armi e delle tecniche di combattimento.<br>
				Questi eroi hanno un\'alta velocit&agrave di attacco e un\'alta Armatura, prendono di mira un nemico con i loro attacchi e specifici oggetti;
				inoltre possiedono anche ottime abilit&agrave per darsi alla fuga. Gli Eroi Agilit&agrave vengono giocati di solito come carry e ganker.');
			break;
		case 'int':
			paragraph($_GET['nome'].' &egrave un eroe <b>Intelligenza</b>.<br>
				Gli Eroi Intelligenza sono maestri delle magie e delle abilit&agrave.<br>
				Rispetto agli altri Eroi hanno molto pi&ugrave Mana e pi&ugrave rigenerazione mana.
				Per questo, per mettere al tappeto i nemici, fanno solitamente affidamento sulle loro Abilit&agrave piuttosto che sugli attacchi fisici.<br>
				Gli Eroi Intelligenza solitamente svolgono ruoli di support, ganker, e pusher.');
			break;
	}

	


	# SPELL
	$query=dett_eroi_spell($_GET['nome']);
	$spell=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
	h(3,'Spell');
	paragraph('Queste sono le <b>spell</b> di '.$_GET['nome'].', ovvero le sue abilità che lo rendono unico all\'interno del gioco.<br>
		Clickare sul nome per ulteriori dettagli');
	magic_table($spell,'dettaglio_spell.php','Nome','spell_name');




	#INVENTARIO														// vanno aggiunti i tastini per mettere/togliere gli oggetti
	br(2);
	h(3,'Inventario');
	paragraph('Gli oggetti fin\'ora acquistati da questo eroe: possono essere al massimo 6 ed ognuno conferisce bonus diversi.<br>
		Qui possiamo vedere l\'inventario completo, i bonus totali degli oggetti stessi, ed il <i>Net Worth</i>,
		ovvero il costo complessivo degli <i>Items</i> posseduti');
	paragraph('Per ulteriori dettagli clickare sul nome; usare "+" e "-" per inserire, rimuovere o cambiare gli oggetti assegnati');

	formattazione_start();
		riga_start();
			$query=items_eroe($_GET['nome']);	//inventario
			$items=mysql_query($query,$conn)
				or die("Query Fallita ".mysql_error($conn));
			$row1=array();					//prima riga
			for ($i=0; $i<3 ; $i++) {
				$x=mysql_fetch_row($items);
				if (isset($x[0])) array_push($row1,'<a href="../oggetti/dettaglio.php?item_name='.$x[0].'&flageroi=on">'.$x[0].'</a> '
						.multi_magic_link('removefrominventory.php',array('markfordeath'=>$x[0],'nome_eroe'=>$_GET['nome']),'[-]',1));
				else array_push($row1,magic_link('add_item.php',$_GET['nome'],'nome',1,'+'));
			}
			$row2=array();					//seconda riga
			for ($i=0; $i<3 ; $i++) { 
				$x=mysql_fetch_row($items);
				if (isset($x[0])) array_push($row2,'<a href="../oggetti/dettaglio.php?item_name='.$x[0].'&flageroi=on">'.$x[0].'</a>'
					.multi_magic_link('removefrominventory.php',array('markfordeath'=>$x[0],'nome_eroe'=>$_GET['nome']),'[-]',1));
				else array_push($row2,magic_link('add_item.php',$_GET['nome'],'nome',1,'+'));
			}

			area_start();
				table_start();
					table_row($row1);
					table_row($row2);
				table_end();
			area_end();

			pad(50);		#poco elegate, ma mette uno spazio bianco tra inventario e bonus stats

			area_start();
				$query=bonus_stats_eroe($_GET['nome']);		# BONUS STATS
				$bonus=mysql_query($query,$conn)
					or die("Query Fallita ".mysql_error($conn));

				table_start();
					table_row(array(' ','<b>Bonus</b>'));
					$col_head=array('<b>Strenght</b>','<b>Agility</b>','<b>Intellect</b>','<b>Attack</b>');
					$r=mysql_fetch_row($bonus);
					for ($i=0; $i <4 ; $i++) { 
						table_row(array($col_head[$i],$r[$i]));
					}
				table_end();
			area_end();

			pad(25);	
			
			area_start();								#Net Worth
				$query=net_worth_eroe($_GET['nome']);
				$net=mysql_query($query,$conn)
					or die("Query Fallita ".mysql_error($conn));
				tabularize($net);
			area_end();
		
		riga_end();
	formattazione_end();


	# STATS 
	br(2);
	$query=stat_eroe($_GET['nome']);
	$stat=mysql_query($query,$conn)
		or die("Query Fallita ".mysql_error($conn));
	$s=mysql_fetch_assoc($stat);
	$tab=array(
		array(' ','<b>Base</b>','<b>Gain</b>'),
		array('<b>Strenght</b>',$s['base_str'],$s['gain_str']),
		array('<b>Agility</b>',$s['base_agl'],$s['gain_agl']),
		array('<b>Intellect</b>',$s['base_int'],$s['gain_int']),
		array('<b>Attack</b>',$s['base_atk'],'##')
	);
	h(3,'Stats');
	paragraph('Le <b>Statische base</b> determinano aspetti dominanti dell\'eroe quali vita massima, armatura e risorse di mana<br>
		ogni volta che il personaggio passa al livello successivo le satatistiche subiscono un aumento pari al <i>gain</i> specifico del campione');
	paragraph('Qui diventa importante l\'attributo primario, in quanto da esso dipende l\'aumento dell\'attacco dell\'eroe.');



	formattazione_start();
		riga_start();
			area_start();
				table_start();				//tavola coi vaori generici
					foreach ($tab as $row) {
						table_row($row);
					}
				table_end();
			area_end();
			area_start(); pad(25); area_end();
			area_start();
				form_start('cambialivello.php','post');
					echo 'Livello Corrente';
					br();
					text('livello',$s['curr_lvl']);
					br(2);
					hidden('nome_eroe',$_GET['nome']);
					submit('Calcola');
				form_end();
			area_end();
			area_start(); pad(25); area_end();
			area_start();
				$strdata=calc_str($_GET['nome']);
				$agldata=calc_agl($_GET['nome']);
				$intdata=calc_int($_GET['nome']);
				$strdata=mysql_query($strdata,$conn)
					or die("Query Fallita ".mysql_error($conn));
				$agldata=mysql_query($agldata,$conn)
					or die("Query Fallita ".mysql_error($conn));
				$intdata=mysql_query($intdata,$conn)
					or die("Query Fallita ".mysql_error($conn));
				tabularize($strdata);
				hr();
				tabularize($agldata);
				hr();
				tabularize($intdata);
			area_end();
			area_start(); pad(25); area_end();
			area_start();
				$atkdata=calc_atk($_GET['nome']);
				$atkdata=mysql_query($atkdata,$conn)
					or die("Query Fallita ".mysql_error($conn));
				tabularize($atkdata);
			area_end();

		riga_end();
	formattazione_end();










	#indietro
	br(2);
	if (isset($_GET['flagitem'])) simple_link($_SESSION['to_det_item'],'Indietro');
	else button_link('riep.php','<- Indietro');


page_end();
?>