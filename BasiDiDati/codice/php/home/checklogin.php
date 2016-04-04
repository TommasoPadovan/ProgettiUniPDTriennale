<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');

if (isset($_GET['guest'])) {
	session_start();

	$_SESSION['host']='127.0.0.1';
	$_SESSION['user']='root';
	$_SESSION['psw']='';
	$_SESSION['dbname']='DotaDB';
	$_SESSION['id']='guest';

	page_start("DotaDB - Guest","../librerie/style.css");
		paragraph("Benvenuto ospite");
		paragraph("Hai privilegi limitati, pertanto puoi consultare ogni pagina del db, ma non modificare, cancellare ne inserire nulla");
		br(2);
			
		button_link('home.php','Continua ->');
	page_end();
}
else {
	if ($_POST['login']=='admin' && $_POST['psw']=='admin') {
		session_start();

		$_SESSION['host']='127.0.0.1';
		$_SESSION['user']='root';
		$_SESSION['psw']='';
		$_SESSION['dbname']='DotaDB';
		$_SESSION['id']='admin';

		page_start("DotaDB","../librerie/style.css");
			paragraph("Identificazione avvenuta con successo...");
			br(2);
			
			button_link('home.php','Continua ->');
		page_end();
	}
	else {
		page_start("DotaDB","../librerie/style.css");
			paragraph("Username o Password errati.");
			br(2);
			button_link('../login.php','<- Torna al Login');
		page_end();
	}
}



?>