delimiter |
#####################################################################################################
###################################calcola hp, manapool e armor ################################################
#####################################################################################################
DROP function IF EXISTS `calculate_str`;

DELIMITER $$
CREATE FUNCTION `calculate_str`(hero varchar(20),what varchar(20)) RETURNS int(11)
BEGIN
	declare base float;
	declare gain float;
	declare bonus float;
	declare lvl int;

	select base_str, gain_str, bonus_str, curr_lvl into base, gain, bonus, lvl  
	from Eroi
	where nome=hero;
		
	IF what='hp' THEN
		return (base+(gain*lvl)+bonus)*19;
	ELSEIF what='regen' THEN
		return (base+(gain*lvl)+bonus)*0.03;
	ELSE
		return base+(gain*lvl)+bonus;
	END IF;

END$$

DELIMITER ;



#####################################################################################################



DROP function IF EXISTS `calculate_agl`;

DELIMITER $$
CREATE FUNCTION `calculate_agl`(hero varchar(20), what varchar(20)) RETURNS int(11)
BEGIN
	declare base float;
	declare gain float;
	declare bonus float;
	declare lvl int;

	select base_agl, gain_agl, bonus_agl, curr_lvl into base, gain, bonus, lvl  
	from Eroi
	where nome=hero;
		
		IF what='armor' THEN
		return (base+(gain*lvl)+bonus)*0.14;
	ELSEIF what='atkspeed' THEN
		return (base+(gain*lvl)+bonus)*1;
	ELSE
		return base+(gain*lvl)+bonus;
	END IF;
END$$

DELIMITER ;





#####################################################################################################





DROP function IF EXISTS `calculate_int`;

DELIMITER $$
CREATE FUNCTION `calculate_int`(hero varchar(20), what varchar(20)) RETURNS int(11)
BEGIN
	declare base float;
	declare gain float;
	declare bonus float;
	declare lvl int;

	select base_int, gain_int, bonus_int, curr_lvl into base, gain, bonus, lvl  
	from Eroi
	where nome=hero;
		
		IF what='manapool' THEN
		return (base+(gain*lvl)+bonus)*13;
	ELSEIF what='regen' THEN
		return (base+(gain*lvl)+bonus)*0.04;
	ELSE
		return base+(gain*lvl)+bonus;
	END IF;
END$$

DELIMITER ;




#####################################################################################################
##########################################calcola attacco ##################################################
#####################################################################################################
DROP FUNCTION IF EXISTS `calculate_atk`;
DELIMITER $$
CREATE FUNCTION `calculate_atk`(hero varchar(20)) RETURNS int(11)
BEGIN
	declare pr_atr varchar(3);
	declare base float;
	declare bonus float;

	select primary_attribute,base_atk, bonus_atk into pr_atr, base, bonus
	from Eroi
	where nome=hero;

	IF pr_atr='str' THEN
		return calculate_str(hero,'')+base+bonus;
	ELSEIF pr_atr='agl' THEN
		return calculate_agl(hero,'')+base+bonus;
	ELSE
		return calculate_int(hero,'')+base+bonus;
	END IF;

END$$

DELIMITER ;