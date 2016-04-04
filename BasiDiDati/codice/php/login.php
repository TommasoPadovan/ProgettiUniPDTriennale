<?php
require_once('librerie/html_lib.php');
require_once('librerie/form_lib.php');

page_start('Login - DotaDB',"librerie/style.css");

form_start('home/checklogin.php','post');
	fieldset_start();
		label_text('login','Login','admin');
		br(2);
		label_text('psw','Password','admin');
	fieldset_end();

	br(2);
	submit('Avanti');

	br(7);
	magic_link('home/checklogin.php','Login as Guest','guest');

form_end();


page_end();
?>