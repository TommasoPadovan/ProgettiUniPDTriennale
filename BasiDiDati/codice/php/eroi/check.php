<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();

if ($_SESSION['id']=='admin') {
	$conn=connect();

	//controllo che non sia già presente nel db
	$objects=mysql_query('select nome from Eroi',$conn)
		or die("Query Fallita ".mysql_error($conn));

	$arr_objects=array();
	for ($i=0; $i<mysql_num_rows($objects) ; $i++) { 
		$a=mysql_fetch_row($objects);
		array_push($arr_objects,$a[0]);
	}

	if (in_array($_POST['nomeEroe'], $arr_objects)) {
		page_start('Error!','../librerie/style.css');
			paragraph($_POST['nomeEroe']." &egrave gi&agrave presente del DB");
			br(2);
			button_link('new.php','<- Indietro');
		page_end();
	} else {
		//inserisco l'eroe
		$query=ins_hero(
			$_POST['nomeEroe'],
			$_POST['pr_atr'],
			$_POST['bio'],
			$_POST['b_Strenght'],
			$_POST['b_Agility'],
			$_POST['b_Intellect'],
			$_POST['b_Attack'],
			$_POST['g_Strenght'],
			$_POST['g_Agility'],
			$_POST['g_Intellect']);
		$ins=mysql_query($query,$conn)
			or die("Query Fallita ".mysql_error($conn));

		//gestione spell
		$arrSlotSpell=array('q','w','e','r','d','f');
		foreach ($arrSlotSpell as $k) {
			if (isset($_POST[$k.'_nomeSpell']) && $_POST[$k.'_nomeSpell']!='') {
				//cose generali spell
				$query=ins_spell(
					$_POST[$k.'_nomeSpell'],
					$_POST[$k.'_tasto'],
					$_POST[$k.'_descrizione'],
					$_POST[$k.'_ability_type'],
					$_POST[$k.'_affection'],
					$_POST[$k.'_damage_type'],
					$_POST[$k.'_piercing'],
					$_POST[$k.'_ultimate'],
					$_POST[$k.'_modalita'],
					$_POST['nomeEroe']);
				$ins=mysql_query($query,$conn)
					or die("Query Fallita ".mysql_error($conn));

				//dettagli per livello
				if ($_POST[$k.'_ultimate']) $n_lvl=3;
				else $n_lvl=4;
				for ($i=1; $i<=$n_lvl ; $i++) {
					$query=ins_spell_detail(
						$_POST[$k.'_nomeSpell'],
						$i,
						$_POST[$k.'_'.$i.'_CD'],
						$_POST[$k.'_'.$i.'_Mana'],
						$_POST[$k.'_'.$i.'_Danno']);
					$ins=mysql_query($query,$conn)
						or die("Query Fallita ".mysql_error($conn));
				}

			}
		}

		page_start('Ok','../librerie/style.css');
			paragraph($_POST['nomeEroe']." &egrave stato inserito correttamente nel DB");
			br(2);
			button_link('riep.php','Continua');
		page_end();

	}

	
}
else {
	forbidden('../librerie/style.css'.'../home/home.php');
}




?>