<?php
session_start();

echo '<script src="https://cdn.jsdelivr.net/gh/google/code-prettify@master/loader/run_prettify.js"></script>';
echo '<form action="" method = "post"><input type = "submit" name = "show_problem" value = "Arata problema"></input></form>';

if(isset($_POST['show_problem'])) {
	$directory_files = glob('probleme/*.cpp');

	$random_File = $directory_files[array_rand($directory_files)];

	if(isset($_SESSION['last_problem'])) {
		while($random_File == $_SESSION['last_problem']) {
			$random_File = $directory_files[array_rand($directory_files)];
		}
	}

	$_SESSION['last_problem'] = $random_File;


	echo '<h2>'.'Problema '.str_replace(".cpp", "", str_replace("probleme/", "", $random_File)).':</h2><br><pre class="prettyprint">'.htmlspecialchars(file_get_contents($random_File)).'</pre>';
}
?>