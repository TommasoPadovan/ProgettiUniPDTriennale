<?php
# pagina iniziale
require_once('../librerie/html_lib.php');
session_start();

page_start('DotaDB - Home','../librerie/style.css');
	br();
	simple_link('../eroi/riep.php','Eroi');
	hr(1);
	simple_link('../oggetti/riep.php','Oggetti');
	hr(1);
	simple_link('../query_avanzate/index.php','Query Avanzate');


	br(15);
	simple_link('../login.php',dx('Logout',1));

page_end();



?>