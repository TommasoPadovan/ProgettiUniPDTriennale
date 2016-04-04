<?php
# dichiarazione delle query

$riep_eroi="
select nome as Nome, primary_attribute as 'Attributo Primario', bio as Storia
from Eroi;
";

# eroi/dettaglio.php #########################################################################################
function dett_eroi_spell($nome_eroe) {
	$dett_eroi_spell="
	select nome as Nome, tasto as Tasto, modalita as 'Attiva/Passiva', damage_type as 'Tipo di Danno', descrizione as Descrizione
	from Spell
	where eroe=\"$nome_eroe\";
	";
	return $dett_eroi_spell;
}


function stat_eroe($nome_eroe) {
	$qr="
	select base_str, base_agl, base_int, base_atk,
		gain_str, gain_agl, gain_int, curr_lvl
	from Eroi
	where nome=\"$nome_eroe\";
	";
	return $qr;
}

function items_eroe($nome_eroe) {
	$qr="
	select oggetto
	from Inventario
	where eroe=\"$nome_eroe\";
	";
	return $qr;
}

function bonus_stats_eroe($nome_eroe) {
	$qr="
	select bonus_str, bonus_agl,bonus_int,bonus_atk
	from Eroi
	where nome=\"$nome_eroe\";
	";
	return $qr;
}

function net_worth_eroe($nome_eroe) {
	$qr="
	select count(i.oggetto) as 'N. Oggetti', sum(o.costo) as 'Net Worth'
	from Eroi e left join Inventario i on e.nome=i.eroe
				left join Oggetti o on i.oggetto=o.nome
	where e.nome=\"$nome_eroe\"
	group by e.nome;
	";
	return $qr;
}

function ins_inventario($nome_eroe,$nome_oggetto) {
	$qr="
	insert into Inventario
	values (\"$nome_eroe\", \"$nome_oggetto\");";
	return $qr;
}

function calc_str($nome_eroe) {
	$qr="
	select calculate_str('$nome_eroe','') as 'Strenght Tot',
		calculate_str('$nome_eroe','hp') as 'Hit Points',
		calculate_str('$nome_eroe','regen') as 'Hp Regen';";
	return $qr;
}

function calc_agl($nome_eroe) {
	$qr="
	select calculate_agl('$nome_eroe','') as 'Agility Tot',
		calculate_agl('$nome_eroe','armor') as 'Armor',
		calculate_agl('$nome_eroe','atkspeed') as 'Attack Speed';";
	return $qr;
}

function calc_int($nome_eroe) {
	$qr="
	select calculate_int('$nome_eroe','') as 'Intellect Tot',
		calculate_int('$nome_eroe','manapool') as 'Mana Pool',
		calculate_int('$nome_eroe','regen') as 'Mana Regen';";
	return $qr;
}

function calc_atk($nome_eroe) {
	$qr="select calculate_atk('$nome_eroe') as 'Attacco';";
	return $qr;
}

function cambia_livello($nome_eroe,$lvl) {
	$qr="
	UPDATE Eroi
	SET curr_lvl='$lvl'
	WHERE nome='$nome_eroe';";
	return $qr;
}

function remove_item_from_inv($nome_eroe,$nome_oggetto) {
	$qr="
	DELETE FROM Inventario
	WHERE eroe='$nome_eroe' and oggetto='$nome_oggetto';";
	return $qr;
}
######################################################################################################






# eroi/dettaglio_spell.php ######################################################################################
	function det_spell1($nome_spell) {
		$qr="
		select nome as Nome, tasto as Tasto, descrizione as Descrizione
		from Spell
		where nome=\"$nome_spell\";
		";
		return $qr;
	}

	function det_spell2($nome_spell) {
		$qr="
		select ability_type as Ability,affection as Affects,damage_type as Damage
		from Spell
		where nome=\"$nome_spell\";
		";
		return $qr;
	}

	function det_spell3($nome_spell) {
		$qr="
		select piercing,ultimate,modalita
		from Spell
		where nome=\"$nome_spell\";
		";
		return $qr;
	}


	function det_lvl_spell($nome_spell) {
		$qr="
		select sd.lvl as Livello, sd.CD, sd.mana_cost as 'Mana Cost', sd.damage as Danno
		from Spell s join SpellDetail sd on s.nome=sd.spell
		where s.nome=\"$nome_spell\"
		order by sd.lvl;
		";
		return $qr;
	}

######################################################################################################





$riep_oggetti="
select nome as Nome, costo as Costo, descrizione as Descrizione
from Oggetti
";
# oggetti/dettaglio.php ########################################################################################
function det_oggetto1($nome_oggetto) {
	$qr="
	select nome as Nome, costo as Costo, descrizione as Descrizione
	from Oggetti
	where nome=\"$nome_oggetto\";
	";
	return $qr;
}


function det_oggetto2($nome_oggetto) {
	$qr="
	select bonus_str,bonus_agl,bonus_int,bonus_atk,tipo
	from Oggetti
	where nome=\"$nome_oggetto\";
	";
	return $qr;
}


function disp_oggetto($nome_oggetto) {
	$qr="
	select negozio
	from Disponibilita
	where oggetto=\"$nome_oggetto\";
	";
	return $qr;
}


function hero_has($nome_oggetto) {
	$qr="
	select eroe
	from Inventario
	where oggetto=\"$nome_oggetto\";
	";
	return $qr;
}

function eff_attivi($nome_oggetto) {
	$qr="
	select nome as 'Nome', CD as 'Call Down', mana_cost as 'Costo di Mana', descrizione as 'Descrizione'
	from EffettiAttivi
	where oggetto='$nome_oggetto';";
	return $qr;
}
######################################################################################################


# oggetti/check.php ##########################################################################################
function ins_item($n,$c,$d,$t,$bs,$bag,$bi,$bat) {
	$qr="
	insert into Oggetti
	values (\"$n\",\"$c\",\"$d\",\"$t\",\"$bs\",\"$bag\",\"$bi\",\"$bat\");
	";
	return $qr;
}

function ins_eff_attivi($n,$d,$CD,$m,$o) {
	$qr="
	insert into EffettiAttivi
	values (\"$n\",\"$d\",\"$CD\",\"$m\",\"$o\")
	";
	return $qr;
}
######################################################################################################



# eroi/check.php############################################################################################
function ins_hero($n,$p,$b,$bs,$bag,$bi,$bat,$gs,$gag,$gi) {
	$qr="
	insert into Eroi
	values (\"$n\",\"$p\",\"$b\",\"$bs\",\"$bag\",\"$bi\",\"$bat\",\"$gs\",\"$gag\",\"$gi\",\"1\",\"0\",\"0\",\"0\",\"0\");
	";
	return $qr;
}

function ins_spell($n,$t,$d,$at,$af,$dt,$p,$u,$m,$e) {
	$qr="
	insert into Spell
	values (\"$n\",\"$t\",\"$d\",\"$at\",\"$af\",\"$dt\",\"$p\",\"$u\",\"$m\",\"$e\")
	";
	return $qr;
}

function ins_dettagli_spell($s,$l,$CD,$mc,$d) {
	$qr="
	insert into SpellDetail
	values (\"$s\",\"$l\",\"$CD\",\"$mc\",\"$d\")
	";
	return $qr;
}
######################################################################################################
?>


