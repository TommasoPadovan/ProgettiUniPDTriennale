# oggetti
INSERT INTO Oggetti VALUES ('Iron Branch', '50', 'A seemingly ordinary branch, its ironlike qualities are bestowed upon the bearer.', 'Passivo', 1, 1, 1,0);
INSERT INTO Oggetti VALUES ('Circlet', '165', 'An elegant circlet designed for human princesses.', 'Passivo',2,2,2,0);
INSERT INTO Oggetti VALUES ('Blades of Attack', '420', 'The damage of these small, concealable blades should not be underestimated.', 'Passivo',0,0,0,4);
INSERT INTO Oggetti VALUES ('Sange and Yasha', '4100', 'Sange and Yasha, when attuned by the moonlight and used together, become a very powerful combination.', 'Passivo',16,16,0,16);
INSERT INTO Oggetti VALUES ('Desolator', '3500', 'A wicked weapon, used in torturing political criminals.', 'Passivo',0,0,0,50);
INSERT INTO Oggetti VALUES ('Mystic Staff', '2700', 'Enigmatic staff made of only the most expensive crystals.', 'Passivo',0,0,25,0);

INSERT INTO Oggetti VALUES ('Rod of Athos', '3100', 'Atos, the Lord of Blight, has his essence stored in this deceptively simple wand.', 'Attivo',0,0,30,0);
	INSERT INTO EffettiAttivi VALUES('Cripple','Slows the target s movement speed.',10,50,'Rod of Athos');
INSERT INTO Oggetti VALUES ('Glimmer Cape', '1950', 'The stolen cape of a master illusionist.', 'Attivo',0,0,0,0);
	INSERT INTO EffettiAttivi VALUES('Glimmer','After a 0.4 second delay, grants invisibility and 55% magic resistance to you or a target allied unit. Can be cast while channelling.',16,130,'Glimmer Cape');
INSERT INTO Oggetti VALUES ('Silver Edge', '5450', 'Once used to slay an unjust king, only to have the kingdom erupt into civil war in the aftermath.', 'Attivo',16,0,0,32);
	INSERT INTO EffettiAttivi VALUES('Shadow Walk','Makes you invisible until the duration ends, or until you attack or cast a spell. While invisible, you move 20% faster and can move through units. Attacking to end the invisibility will deal 225 bonus damage to the target, disable their passive abilities, and reduce their damage output.',24,75,'Silver Edge');
INSERT INTO Oggetti VALUES ('Orchid Malevolence', '4075', 'A garnet rod constructed from the essence of a fire demon.', 'Attivo',0,0,25,30);
	INSERT INTO EffettiAttivi VALUES('Soul Burn','Silences the target unit for 5 seconds and amplifies the damage it takes by 30%.',18,100,'Orchid Malevolence');


INSERT INTO Disponibilita VALUES ('Iron Branch','Main Shop');
INSERT INTO Disponibilita VALUES ('Circlet','Main Shop');
INSERT INTO Disponibilita VALUES ('Circlet','Side Shop');
INSERT INTO Disponibilita VALUES ('Blades of Attack','Main Shop');
INSERT INTO Disponibilita VALUES ('Blades of Attack','Side Shop');
INSERT INTO Disponibilita VALUES ('Sange and Yasha','Main Shop');
INSERT INTO Disponibilita VALUES ('Desolator','Main Shop');
INSERT INTO Disponibilita VALUES ('Mystic Staff','Secret Shop');

INSERT INTO Disponibilita VALUES ('Rod of Athos','Main Shop');
INSERT INTO Disponibilita VALUES ('Rod of Athos','Secret Shop');
INSERT INTO Disponibilita VALUES ('Glimmer Cape','Main Shop');
INSERT INTO Disponibilita VALUES ('Silver Edge','Main Shop');
INSERT INTO Disponibilita VALUES ('Orchid Malevolence','Main Shop');
INSERT INTO Disponibilita VALUES ('Orchid Malevolence','Secret Shop');


#eroi
INSERT INTO Eroi VALUES ('Beastmaster', 'str', 'Karroch was born a child of the stocks. His mother died in childbirth; his father, a farrier for the Last King of Slom, was trampled to death when Karroch was five. Afterward Karroch was indentured to the king’s menagerie, where he grew up among all the beasts of the royal court: lions, apes, fell-deer, and things less known, things barely believed in.',23,18,16,41,2.2,1.6,1.9,1,0,0,0,0);
	INSERT INTO Spell VALUES ('Wild Axes', 'q', 'Beastmaster sends his axes flying and calls them home again, slicing through enemy units and trees along their path. Each axe can hit an enemy once.', 'Unit Target', 'Enemies', 'Magico', '0', '0', 'Attiva', '', 'Beastmaster');
		INSERT INTO SpellDetail VALUES ('Wild Axes',1,13,120,70);
		INSERT INTO SpellDetail VALUES ('Wild Axes',2,13,120,100);
		INSERT INTO SpellDetail VALUES ('Wild Axes',3,13,120,130);
		INSERT INTO SpellDetail VALUES ('Wild Axes',4,13,120,170);
	INSERT INTO Spell VALUES ('Call of the Wild Hawk', 'w', 'Beastmaster calls forth a watchful Hawk to scout the battlefield. At level 3 and beyond, the hawk can become invisible after being still for 4 seconds.', 'No Target', 'Self', '- - -', '0', '0', 'Attiva', '', 'Beastmaster');
		INSERT INTO SpellDetail VALUES ('Call of the Wild Hawk',1,40,15,0);
		INSERT INTO SpellDetail VALUES ('Call of the Wild Hawk',2,40,15,0);
		INSERT INTO SpellDetail VALUES ('Call of the Wild Hawk',3,40,15,0);
		INSERT INTO SpellDetail VALUES ('Call of the Wild Hawk',4,40,15,0);
	INSERT INTO Spell VALUES ('Call of the Wild Boar', 'e', 'Beastmaster calls a powerful Boar to stalk the battlefield, capable of spitting poison at enemies to slow their movement and attack speed.', 'abilitytype', 'No Target', 'Self', '- - -', '0', '0', 'Attiva', '', 'Beastmaster');
		INSERT INTO SpellDetail VALUES ('Call of the Wild Boar',1,40,15,0);
		INSERT INTO SpellDetail VALUES ('Call of the Wild Boar',2,40,15,0);
		INSERT INTO SpellDetail VALUES ('Call of the Wild Boar',3,40,15,0);
		INSERT INTO SpellDetail VALUES ('Call of the Wild Boar',4,40,15,0);
	INSERT INTO Spell VALUES ('Inner Beast', 'd', 'Beastmaster s ability to incite the innate strength of animals was seen in the mauling of the king of Slom.', 'Passive', 'Self', '- - -', '1', '0', 'Passiva', 'Untaps the inner fury of allies, passively increasing their attack speed.', 'Beastmaster');
	INSERT INTO Spell VALUES ('Primal Roar', 'r', 'Beastmaster lets loose a deafening roar that stuns, and shoves open, a path to its target. All units in the path of the roar are damaged, while units shoved aside by the roar have their movement and attack speed slowed.', 'Unit Target', 'Enemies', 'Magico', '1', '1', 'Attiva', '', 'Beastmaster');
		INSERT INTO SpellDetail VALUES ('Primal Roar',1,80,150,200);
		INSERT INTO SpellDetail VALUES ('Primal Roar',2,75,175,250);
		INSERT INTO SpellDetail VALUES ('Primal Roar',3,70,200,300);

INSERT INTO Eroi VALUES ('', '', '',,,,,,,,1,0,0,0,0);
INSERT INTO Eroi VALUES ('', '', '',,,,,,,,1,0,0,0,0);
INSERT INTO Eroi VALUES ('', '', '',,,,,,,,1,0,0,0,0);
