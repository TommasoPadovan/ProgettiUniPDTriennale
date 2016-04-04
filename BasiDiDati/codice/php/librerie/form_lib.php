<?php
require_once('html_lib.php');
# inizio fine form ###########################################################################################
function form_start($act,$met,$i=0) {
	if ($met=='get' or $met=='post'){
		if ($i==0) echo "<form action=\"$act\" method=\"$met\" />";
		else return "<form action=\"$act\" method=\"$met\" />";
	}
}

function form_end($i=0) {
	if ($i==0) echo "</form>";
	else return "</form>";
}
######################################################################################################





# formattazione form ########################################################################################
function label($nome_var,$video) {
	echo "<label for=\"$nome_var\">$video</label>";
}
######################################################################################################





# text ##################################################################################################
function text($nome_var,$val="") {
	echo "<input type=\"text\" id=\"$nome_var\" name=\"$nome_var\" value=\"$val\" />";
}
function r_text($nome_var,$val="") {
	return "<input type=\"text\" id=\"$nome_var\" name=\"$nome_var\" value=\"$val\" />";
}

function label_text($nome_var,$video,$val="") {
	label($nome_var,$video);
	br();
	text($nome_var,$val);
}
######################################################################################################






# textarea ###############################################################################################
function textarea($r,$c,$nome_var,$val="",$i=0) {
	if ($i==0) echo "<textarea id=\"$nome_var\" name=\"$nome_var\" rows=\"$r\" cols=\"$c\">$val</textarea>";
	else return "<textarea id=\"$nome_var\" name=\"$nome_var\" rows=\"$r\" cols=\"$c\">$val</textarea>";
}
######################################################################################################




#option #################################################################################################
function tendina($nome_var,$arr_option) {
	$str="<select name=\"$nome_var\">";
	foreach ($arr_option as $val) {
		$str.="<option value=\"$val\">$val</option>";
	}
	echo $str.'</select>';
}
######################################################################################################





# hidden ################################################################################################
function hidden($nome_var,$val) {
	echo "<input type=\"hidden\" name=\"$nome_var\" value=\"$val\">";
}
######################################################################################################



#tabella nx2 ##############################################################################################
function table_nx2($head,$arr) {				//dentro $arr devono esserci ("nome_variabile" => "roba_da_stampare")
	table_start();
		table_row(array('','<b>'.$head.'</b>'));
		foreach ($arr as $key => $val) {
			table_row(array('<b>'.$val.'</b>',r_text($key)));
		}
	table_end();
}
######################################################################################################





# submit/reset ############################################################################################
function submit($val,$i=0) {
	if ($i==0) echo "<input type=\"submit\" value=\"$val\" />";
	else return "<input type=\"submit\" value=\"$val\" />";
}

function cancella($val) {echo "<input type=\"reset\" value=\"$val\" />";}

function button_link($url,$text,$i=0) {
	$str=form_start($url,'get',1);
	$str.=submit($text,1);
	$str.=form_end(1);
	if ($i==0) echo $str;
	else return $str;
}

# checkbox ###############################################################################################
function checkbox($nome_var,$video) {echo "<input type=\"checkbox\" name=\"$nome_var\" value=\"$nome_var\" /> $video";}
######################################################################################################



# radiobutton #############################################################################################
function radiobutton($nome_var,$arrCoppie,$i=0) {
	$radiostr='';
	foreach ($arrCoppie as $value => $video) {
		$radiostr.="<input type=\"radio\" name=\"$nome_var\" value=\"$value\" />";
		$radiostr.=' '.$video.'<br />';
	}
	if ($i==0) echo $radiostr;
	else return $radiostr;
}

######################################################################################################
?>