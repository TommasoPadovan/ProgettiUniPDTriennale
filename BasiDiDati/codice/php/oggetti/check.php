<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
require_once('../librerie/php_lib.php');
require_once('../librerie/query.php');
session_start();

if ($_SESSION['id']=='admin') {
	$conn=connect();

	// controllo che il nome, chiave primaria, non sia gia' presente nel db, altimenti messaggio d'errore e torno al form
	$items=mysql_query('select nome from Oggetti',$conn)
		or die("Query Fallita tette1".mysql_error($conn));

	$arr_items=array();
	for ($i=0; $i<mysql_num_rows($items) ; $i++) { 
		$a=mysql_fetch_row($items);
		array_push($arr_items,$a[0]);
	}

	if (in_array($_POST['nome'], $arr_items)) {
		page_start('Error!','../librerie/style.css');
			paragraph($_POST['nome']." &egrave gi&agrave presente del DB");
			br(2);
			button_link('new.php','<- Indietro');
		page_end();
	}
	else {
		$query=ins_item($_POST['nome'],$_POST['costo'],$_POST['descrizione'],$_POST['tipo'],$_POST['bonus_str'],$_POST['bonus_agl'],$_POST['bonus_int'],$_POST['bonus_atk']);
		$ins=mysql_query($query,$conn)
			or die("Query Fallita tette2".mysql_error($conn));

		$nom=$_POST['nome'];
		if (isset($_POST['main'])) {
			$query="
			insert into Disponibilita
			values (\"$nom\",\"Main Shop\");
			";
			$ins=mysql_query($query,$conn)
				or die("Query Fallita tette3".mysql_error($conn));
		}
		if (isset($_POST['side'])) {
			$query="
			insert into Disponibilita
			values (\"$nom\",\"Side Shop\");
			";
			$ins=mysql_query($query,$conn)
				or die("Query Fallita tette4".mysql_error($conn));
		}
		if (isset($_POST['secret'])) {
			$query="
			insert into Disponibilita
			values (\"$nom\",\"Secret Shop\");
			";
			$ins=mysql_query($query,$conn)
				or die("Query Fallita tette5".mysql_error($conn));
		}

		if (isset($_POST['nome_effetto']) && $_POST['nome_effetto']!='' && $_POST['tipo']='Attivo') {
			$query=ins_eff_attivi($_POST['nome_effetto'],$_POST['descrizione_effetto'],$_POST['CD'],$_POST['mana_cost'],$_POST['nome']);
			$ins=mysql_query($query,$conn)
				or die("Query Fallita tette6".mysql_error($conn));
		}


		page_start('Ok','../librerie/style.css');
			paragraph($_POST['nome']." &egrave stato inserito correttamente nel DB");
			br(2);
			button_link('riep.php','Continua');
		page_end();
	}
}
else {
	forbidden('../librerie/style.css','../home/home.php');
}




?>