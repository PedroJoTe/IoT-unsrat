<?php

$server = "localhost";
$username = "werislin_iot";
$password = "werislin_iot";
$database = "werislin_IoT";
$conn = mysqli_connect($server, $username, $password, $database);
if (!$conn) {
  die('koneksi gagal boss : ' . mysqli_error());
}


$d1 = $_GET['data1'];
$d2 = $_GET['data2'];
$d3 = 'kosong';
$sid = $_GET['sid'];
$i = $_GET['i'];

	if (!empty($d1) && !empty($d2) && !empty($d3) && !empty($sid)) {
  		$sql = "insert into ember set data1='$d1', data2='$d2', data3='$d3', sensorid='$sid', waktu=now()";
  		$r = mysqli_query($conn,$sql);

  		echo "OK";
	}
	else {
		echo "Not Ok";
	}
mysqli_close($conn);
?>

