<?php

#1) mostra per l'eroe selezionato il numero di oggetti posseduti ed il loro costo totale
function query1($nome_eroe) {
	return "
select e.nome, count(i.oggetto) as 'N. Oggetti', sum(o.costo) as 'Net Worth'
from Eroi e left join Inventario i on e.nome=i.eroe
		left join Oggetti o on i.oggetto=o.nome
where e.nome='$nome_eroe'
group by e.nome;
	";
}

#2) tutti gli oggetti (mostrando nome, costo e descrizione) che hanno effetto attivo, il cui costo di mana sia superiore a ad un certo tot e CD più lungo di tot
function query2($mana, $calldown) {
	return "
select o.nome, o.costo, o.descrizione, e.mana_cost, e.CD
from Oggetti o join EffettiAttivi e on o.nome=e.oggetto
where o.nome in (
	select oggetto
	from EffettiAttivi
	where mana_cost>$mana and CD>$calldown);
	";
}

#3) costo totale di mana di "tutta la rotation di spell" (=tutte le magie una immediatamente dopo l'altra) di ogni eroe che ha solo spell attive,
#	considerando le spell al massimo livello
function query3() {
	return "
select e.nome as Eroe, sum(d.mana_cost) as 'Rotation Total Cost'
from Eroi e join Spell s on e.nome=s.eroe
		join SpellDetail d on s.nome=d.spell
where ((s.ultimate=0 and d.lvl=4) or (s.ultimate=1 and d.lvl=3)) and e.nome not in (
	select nome
	from Eroi
	where nome in (
		select eroe
		from Spell
		where modalita='Passiva'
	)
)
group by e.nome;
	";
}

#4) eroi la cui spell con CD più alto (a qualsiasi livello) ha CD maggiore dell'oggetto più lento a ricaricarsi posseduto dallo stesso eroe
function query4() {
	return "
select e.nome as Eroe, max(d.CD) as 'CallDown massimo'
from Eroi e join Spell s on e.nome=s.eroe
		join SpellDetail d on s.nome=d.spell
group by e.nome
having max(d.CD) >ALL(
	select max(CD)
	from EffettiAttivi
	where oggetto in (
		select oggetto
		from Inventario
		where eroe=e.nome
	)
);
	";
}

#5) il negozio che ha venduto ad eroi il cui nome compicia per X il maggior numero di oggetti aventi effetti attivi
function query5($x) {
	return "
select d.negozio as Negozio, count(*) as 'Numero Oggetti Venduti'
from Disponibilita d join Oggetti o on d.oggetto=o.nome
				join Inventario i on o.nome=i.oggetto
where i.eroe like '$x%' and d.oggetto in (
	select oggetto
	from EffettiAttivi
)
group by d.negozio
having count(*)= (
	select max(counted) from (
		select count(*) as counted
			from Disponibilita d2 join Oggetti o2 on d2.oggetto=o2.nome
							join Inventario i2 on o2.nome=i2.oggetto
			where i2.eroe like '$x%' and d2.oggetto in (
				select oggetto
				from EffettiAttivi
			)
			group by d2.negozio
	) as counts
);
	";
}

#6) eroi, media dei tempi d'attesa delle spell lvl1, delle spell livello masssimo, degli oggeti solo se i la media di tempi di attesa a livello 1 è più lunga delle spell maxate
function query6() {
	return "
select e.nome as Eroe, e.primary_attribute as 'Attributo Primario', avg(d.CD) as 'Media CallDown spell al massimo livello'
from Eroi e join Spell s on e.nome=s.eroe
		join SpellDetail d on s.nome=d.spell
where (s.ultimate=0 and d.lvl=4) or (s.ultimate=1 and d.lvl=3)
group by e.nome, e.primary_attribute
having avg(d.CD) < ALL (
	select avg(d2.CD)
	from Eroi e2 join Spell s2 on e2.nome=s2.eroe
			join SpellDetail d2 on s2.nome=d2.spell
	where e2.nome=e.nome and d2.lvl=1
	group by e2.nome
);
	";
}


?>