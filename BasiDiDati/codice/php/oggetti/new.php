<?php
require_once('../librerie/html_lib.php');
require_once('../librerie/form_lib.php');
session_start();

if ($_SESSION['id']=='admin') {
	page_start('Nuovo Oggetto','../librerie/style.css');
		br(2);
		form_start('check.php','post');
			formattazione_start();
				riga_start();
					area_start();
						fieldset_start();
							label('nome','Nome:'); br(); text('nome');							//nome
							br(2);													//costo
							label('costo','Costo:'); br(); text('costo');
						fieldset_end();
					area_end();
					pad(50);
					area_start();
						fieldset_start();
							echo "<b>Disponibilit&agrave</b>"; br();
							checkbox('main','Main Shop'); br();
							checkbox('side','Side Shop'); br();
							checkbox('secret','Secret Shop');
						fieldset_end();
					area_end();
					pad(50);
					area_start();
						fieldset_start();												//tipo
							echo ' <br>';
							label('tipo','Tipo: '); tendina('tipo',array('Passivo','Attivo'));
							echo ' <br><br>';
						fieldset_end();
					area_end();
				riga_end();
			formattazione_end();

			br(2);																//descrizione
			label('descrizione','Descrizione:'); br(); textarea(4,50,'descrizione');


			br(3);																//bonus
			$arr_bonus= array (
				'bonus_str' => 'Strenght',
				'bonus_agl' => 'Agility',
				'bonus_int' => 'Intellect',
				'bonus_atk' => 'Attack'
			);
			formattazione_start(); riga_start();
				area_start();
					table_nx2('Bonus',$arr_bonus);
				area_end();
				area_start(); pad(25); area_end();
				area_start();
					b('Effetti Attivi');
					br();
					label('nome_effetto','Nome:'); br(); text('nome_effetto'); br(2);
					label('CD','Call Down:'); br(); text('CD'); br(2);
					label('mana_cost','Mana Cost:'); br(); text('mana_cost'); br(2);
				area_end();
				area_start(); pad(15); area_end();
				area_start();
					label('descrizione_effetto','Descrizione:'); br(); textarea(10,30,'descrizione_effetto');
				area_end();
			riga_end(); formattazione_end();

			br(2);
			submit('Avanti');
			echo ' ';
			cancella('Reset');

		form_end();
		
		br();
		button_link('riep.php','Annulla');

	page_end();
}
else {
	forbidden('../librerie/style.css','../home/home.php');
}



?>