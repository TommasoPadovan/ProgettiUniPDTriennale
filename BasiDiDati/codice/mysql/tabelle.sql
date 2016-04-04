delimiter |

DROP TABLE IF EXISTS Eroi|
CREATE TABLE Eroi (
	nome varchar(20) primary key,
	primary_attribute varchar(3) not null,
	bio varchar(2048),

	base_str float not null,
	base_agl float not null,
	base_int float not null,
	base_atk float not null,

	gain_str float not null,
	gain_agl float not null,
	gain_int float not null,

	curr_lvl tinyint not null,

	bonus_str float not null default 0,
	bonus_agl float not null default 0,
	bonus_int float not null default 0,
	bonus_atk float not null default 0
)ENGINE=InnoDB|



DROP TABLE IF EXISTS Oggetti|
CREATE TABLE Oggetti (
	nome varchar(20) primary key,
	costo  smallint not null,
	descrizione varchar(512),
	tipo varchar(20),

	bonus_str float default 0,
	bonus_agl float default 0,
	bonus_int float default 0,
	bonus_atk float default 0
)ENGINE=InnoDB|



DROP TABLE IF EXISTS Spell|
CREATE TABLE Spell (
	nome varchar(20) primary key,
	tasto varchar(1),
	descrizione varchar(512) not null,
	ability_type varchar(20),
	affection varchar(20),
	damage_type varchar(20),
	piercing bool,
	ultimate bool,
	modalita varchar(20),
	effetto varchar(512),

	eroe varchar(20),

	foreign key (eroe) references Eroi(nome) on delete cascade on update cascade
)Engine=InnoDB|


DROP TABLE IF EXISTS SpellDetail|
CREATE TABLE SpellDetail (
	spell varchar(20),
	lvl tinyint,
	CD float,
	mana_cost smallint,
	damage float,

	primary key(spell,lvl),
	foreign key (spell) references Spell(nome) on delete cascade on update cascade
)Engine=InnoDB|





DROP TABLE IF EXISTS Inventario|
CREATE TABLE Inventario (
	eroe varchar(20),
	oggetto varchar(20),

	primary key(eroe,oggetto),
	foreign key (eroe) references Eroi(nome) on delete cascade on update cascade, 
	foreign key (oggetto) references Oggetti(nome) on delete cascade on update cascade
)ENGINE=InnoDB|



DROP TABLE IF EXISTS Disponibilita|
CREATE TABLE Disponibilita (
	oggetto varchar(20),
	negozio varchar(20),

	primary key(oggetto,negozio),
	foreign key (oggetto) references Oggetti(nome) on delete cascade on update cascade
)ENGINE=InnoDB|


DROP TABLE IF EXISTS EffettiAttivi|
CREATE TABLE EffettiAttivi (
	nome varchar(20) primary key,
	descrizione varchar(512),
	CD float,
	mana_cost smallint,

	oggetto varchar(20),

	foreign key (oggetto) references Oggetti(nome) on delete cascade on update cascade
)ENGINE=InnoDB|


|
delimiter ;

