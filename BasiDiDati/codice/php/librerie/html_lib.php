<!-- un po' di funzioni globali di libreria per la composizione di pagine html -->

<?php
# INIZIO & FINE PAGINA  #######################################################################################
function page_start($title,$relcss) {
echo<<<END
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml"  xml:lang="it" lang="it">

	<head>
		<title>$title</title>
		<link rel="stylesheet" type="text/css" href="$relcss">
	</head>
		
	<body>
		<hr />
		<h2>$title</h2>
		<hr />
END;
}

function page_end() {
 echo<<<END
	</body>
</html>
END;
}

function forbidden($relcss,$back) {
	page_start('Forbidden',$relcss);
		paragraph('Non hai i permessi necessari per vedere questa pagina');
		simple_link($back,'Indietro');
	page_end();
}
######################################################################################################






# LINK #################################################################################################
function simple_link($url,$str,$i=0) {
	if ($i==0) echo "<a href=\"$url\">$str</a>";
	else return "<a href=\"$url\">$str</a>";
}

function magic_link($url,$str,$nome_var,$f=0,$video='') { 		#inserisce un hiperlink passando in get una varibile di nome $nome_var che ha il valore di $str
	$magic_url="$url?$nome_var=$str";
	if ($f==0) echo "<a href=\"$magic_url\">$str</a>";
	else return "<a href=\"$magic_url\">$video</a>";
}

function multi_magic_link($url,$arrCoppie,$video,$i=0) {
	$magic_url="$url?";
	foreach ($arrCoppie as $key => $value) {
		$magic_url.="$key=$value&";
	}
	$magic_url=substr($magic_url, 0, -1);	//tolgo l'ultima &
	if ($i==0) echo "<a href=\"$magic_url\">$video</a>";
	else return "<a href=\"$magic_url\">$video</a>";
}



######################################################################################################






# SPAZIATURA, FORMATTAZIONE ETC ###############################################################################
function br($x=1) {							//x righe a capo
	for ($i=0; $i<$x; $i++) { 
		echo '<br />';
	}
}
function hr($x=0) {							//linea con x linee di pad sopra e sotto
	br($x+1);
	echo "<hr />";
	br($x);
}
function paragraph($str) {						//paragrafo
	echo "<p>$str</p>";
}

function fieldset_start() {echo "<fieldset>";}			//fieldset
function fieldset_end() {echo "</fieldset>";}

function b($str,$i=0) {
	if($i==0) echo "<b>$str</b>";				//grassetto
	else return "<b>$str</b>";
}

function h($i,$str) {echo "<h$i>$str</h$i>";}			//titoli	

function dx($str,$i=0) {							//dx-sx
	if ($i==0) echo "<p align=\"right\">$str</p>";
	else return "<p align=\"right\">$str</p>";
}
function sx($str,$i=0) {
	if ($i==0) echo "<p align=\"left\">$str</p>";
	else return "<p align=\"left\">$str</p>";
}


#formattazione con tabelle
function formattazione_start() {echo "<table>";}
function formattazione_end() {echo "</table>";}
function riga_start() {echo "<tr>";}
function riga_end() {echo "</tr>";}
function area_start() {echo "<td>";}
function area_end() {echo "</td>";}
function pad($i) {	echo "<td><table cellpadding=\"$i\"><tr><td></td></tr></table></td>";} //aggiunge uno quadrato vuoto largo $i nella tabella

######################################################################################################






# TABELLE ###############################################################################################
function table_start() {echo "<table border=\"1\">";}

function table_heading($arr) {
	echo "<tr>";
	foreach ($arr as $key => $val) {
		echo "<td><b>$key</b></td>";
	}
	echo "</tr>";
}

function table_row($arr) {
	echo "<tr>";
	foreach ($arr as $val) {
		echo "<td>$val</td>";
	}
	echo "</tr>";
}

function tabularize($quey_result) {
	table_start();
	for ($i=0; $i<mysql_num_rows($quey_result) ; $i++) { 
		$row=mysql_fetch_assoc($quey_result);
		if ($i==0) table_heading($row);
		table_row($row);

	}
	table_end();
}

function magic_row($arr,$url,$col,$nome_var) {		#costruisce una riga di tabella con link magici nella colonna $col
	echo "<tr>";
	foreach ($arr as $key => $val) {
		if ($key==$col) {
			echo "<td>";
			magic_link($url,$val,$nome_var);
			echo "</td>";
		}
		else echo "<td>$val</td>";
	}
	echo "</tr>";
}

function magic_table($quey_result,$url,$col,$nome_var) {
	table_start();
	for ($i=0; $i<mysql_num_rows($quey_result) ; $i++) { 
		$row=mysql_fetch_assoc($quey_result);
		if ($i==0) table_heading($row);
		magic_row($row,$url,$col,$nome_var);
	}
	table_end();
}

function table_end() {echo"</table>";}
######################################################################################################
?>