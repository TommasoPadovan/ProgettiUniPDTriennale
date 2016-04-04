delimiter |
######################################################################################################
# controlla che l'attributo primario sia uno tra {str,agl,int} Sia update che insert  ######################################################
######################################################################################################
drop procedure if exists cpa|								# procedura comune
create procedure cpa (pa varchar(3))
BEGIN
	IF not (pa='str' or pa='agl' or pa='int') THEN
		insert into Eroi
		select *
		from Eroi
		limit 1;
	END IF;
END|

drop trigger if exists check_primary_attribute_insert|				# insert
create trigger check_primary_attribute_insert
before insert on Eroi
for each row
BEGIN
	call cpa(new.primary_attribute);
END|

drop trigger if exists check_primary_attribute_update|			# update
create trigger check_primary_attribute_update
before update on Eroi
for each row
BEGIN
	call cpa(new.primary_attribute);
END|
######################################################################################################









######################################################################################################
# ad ogni inserimento o rimozione di un nuovo oggetto nell'inventario di un determinato eroe, aggiorna le statistiche "bonus" di quell'eroe  ###################
######################################################################################################
drop trigger if exists nuovo_oggetto|
create trigger nuovo_oggetto
after insert on Inventario
for each row
BEGIN
	declare attacco float;
	declare forza float;
	declare agilita float;
	declare intelligenza float;

	select o.bonus_atk into attacco
	from Oggetti o
	where o.nome=new.oggetto;	
	select o.bonus_str into forza
	from Oggetti o
	where o.nome=new.oggetto;	
	select o.bonus_agl into agilita
	from Oggetti o
	where o.nome=new.oggetto;	
	select o.bonus_int into intelligenza
	from Oggetti o
	where o.nome=new.oggetto;	

	update Eroi
	set bonus_atk=bonus_atk+attacco,
		bonus_str=bonus_str+forza,
		bonus_agl=bonus_agl+agilita,
		bonus_int=bonus_int+intelligenza
	where nome=new.eroe;
END|



drop trigger if exists cancellazione_oggetto|		#NB, come in qualche patch fa assumo che la black king bar, uns volta comprata, non si possa piu' vendere
create trigger cancellazione_oggetto
before delete on Inventario
for each row
BEGIN
	IF old.oggetto="Black King Bar" THEN
		insert into Eroi
		select *
		from Eroi
		limit 1;
	ELSE begin
		declare attacco float;
		declare forza float;
		declare agilita float;
		declare intelligenza float;

		select o.bonus_atk into attacco
		from Oggetti o
		where o.nome=old.oggetto;	
		select o.bonus_str into forza
		from Oggetti o
		where o.nome=old.oggetto;	
		select o.bonus_agl into agilita
		from Oggetti o
		where o.nome=old.oggetto;	
		select o.bonus_int into intelligenza
		from Oggetti o
		where o.nome=old.oggetto;


		update Eroi
		set bonus_atk=bonus_atk-attacco,
			bonus_str=bonus_str-forza,
			bonus_agl=bonus_agl-agilita,
			bonus_int=bonus_int-intelligenza
		where nome=old.eroe;
	end;
	END IF;

END|
######################################################################################################


# serve per eliminare "direttamente" (=non mediante cascade) la riga da inventario in modo da attivare il trigger
drop trigger if exists cascade_emulator_for_items|
create trigger cascade_emulator_for_items
before delete on Oggetti
for each row
BEGIN
	delete from Inventario
	where oggetto=old.nome;
END|


|
delimiter ;
