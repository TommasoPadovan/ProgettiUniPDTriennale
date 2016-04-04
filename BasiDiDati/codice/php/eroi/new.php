<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();

if ($_SESSION['id']=='admin') {
	$conn=connect();
	page_start('Nuovo Eroe','../librerie/style.css');
		button_link('../home/home.php','<- Indietro');
		br(2);
		form_start('check.php','post');
			# nome, attributo primario, bio
			formattazione_start();
				riga_start();
					area_start();
						label_text('nomeEroe','Nome');
					area_end();
					pad(50);
					area_start();
						label('pr_atr','Attributo Primario'); br();
						tendina('pr_atr',array('str','agl','int'));
					area_end();
				riga_end();
			formattazione_end();
			br();
			label('bio','Descrizione'); br();
			textarea(10,100,'bio');
			
			hr();
			hr();

			# tabella inserimento statistiche
			h(3,'Stats');
			$arrTitoliRows=array('Strenght','Agility','Intellect','Attack');
			$arrTitoliCols=array(' ','<b>Base</b>','<b>Gain</b>');
			$arrTabella=array($arrTitoliCols);
			for ($i=0; $i<3 ; $i++) { 
				$arrToPush=array(
					b($arrTitoliRows[$i],1),
					textarea(1,3,'b_'.$arrTitoliRows[$i],'',1),
					textarea(1,3,'g_'.$arrTitoliRows[$i],'',1),
				);
				array_push($arrTabella, $arrToPush);
			}
			array_push($arrTabella, array(b('Attack',1),textarea(1,3,'b_Attack','',1),' '));
			table_start();
				foreach ($arrTabella as $value) {
					table_row($value);
				}
			table_end();

			hr();
			hr();

			# spells
			h(3,'Spells');
			$arrTasto=array('q','w','e','r','d','f');
			paragraph("Inserire qui le spell corrispondenti al tasto, in caso l'eroe in questione non ne possieda alcune, lasciare bianco");
			foreach ($arrTasto as $k) {
				h(2,$k);
				#nome,descrizione
				formattazione_start();
					riga_start();
						area_start();
							label_text($k.'_nomeSpell','Nome');
						area_end();
						pad(25);
						area_start();
							label($k.'_descrizione','Descrizione'); br();
							textarea(5,60,$k.'_descrizione');
						area_end();
					riga_end();
				formattazione_end();

				#dettagli generali
				formattazione_start();
					$p=10; //spazio tra le tendine
					riga_start();
						area_start();	#attiva/passiva
							label($k.'_modalita','Modalit&agrave'); br();
							tendina($k.'_modalita',array('Attiva','Passiva'));
						area_end();
						pad($p);
						area_start();	# ability type
							label($k.'_ability_type','Tipo Abilit&agrave'); br();
							tendina($k.'_ability_type',array('Unit Target','Point Target','Area Target','No Target','Channeled','Toggle','Passive'));
						area_end();
						pad($p);
						area_start();	#affection
							label($k.'_affection','Affezione'); br();
							tendina($k.'_affection',array('Self','Enemies','Allies','Units','Heroes'));
						area_end();
						pad($p);
						area_start();	# tipo di danno
							label($k.'_damage_type','Tipo di Danno'); br();
							tendina($k.'_damage_type',array('- - -','Fisico','Magico','Puro'));
						area_end();
						pad($p);
						area_start();	# piercing
							label($k.'_piercing','Piercing'); br();
							tendina($k.'_piercing',array('No','Yes'));
						area_end();
					riga_end();
				formattazione_end();
				
				hidden($k.'_tasto',$k);
				if ($k=='r') hidden($k.'_ultimate',1);
				else hidden($k.'_ultimate',0);


				#dettagli livelli
				paragraph('Dettagli dei livelli (nel caso di spell passiva, lasciare in bianco)');
				if ($k=='r') $n_lvl=3;
				else $n_lvl=4;
				$arrTitoliCols=array('<b>Livello</b>','<b>CD</b>','<b>Mana</b>','<b>Danno</b>');
				$arrTabella=array($arrTitoliCols);
				for ($i=1; $i<=$n_lvl ; $i++) { 
					$arrToPush=array(
						b($i,1),
						textarea(1,3,$k.'_'.$i.'_CD','',1),
						textarea(1,3,$k.'_'.$i.'_Mana','',1),
						textarea(1,3,$k.'_'.$i.'_Danno','',1),
					);
					array_push($arrTabella,$arrToPush);
				}
				
				table_start();
					foreach ($arrTabella as $val) {
						table_row($val);
					}
				table_end();

				hr();

			}

			submit("Avanti");




		form_end();
	page_end();
}
else {
	forbidden('../librerie/style.css','../home/home.php');
}



?>