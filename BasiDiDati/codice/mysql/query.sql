# mostra hitpoints, armor e manapool (le tre statistiche dinamiche principali di ogni eroe) dell'eroe in questione

select nome as 'Nome',
	cast(150+(base_str+(gain_str*curr_lvl))*19 as decimal(10,0)) as 'Hitpoints',
	cast((base_agl+(gain_agl*curr_lvl))*0.14 as decimal(10,0)) as 'Armor',
	cast((base_int+(gain_int*curr_lvl))*13 as decimal(10,0)) as 'Mana Pool'
from Eroi
where nome='pudge';




# mostra numero di oggetti posseduti ed il net worth di un eroe, ovvero la somma dei costi degli oggetti nell'inventario

select e.nome, count(*) as 'Numero Oggetti', sum(o.costo) as 'Net Worth'
from Eroi e left join Inventario i on e.nome=i.eroe
			left join Oggetti o on i.oggetto=o.nome
group by e.nome;
