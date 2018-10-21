<?php
$server = "localhost";
$username = "werislin_iot";
$password = "werislin_iot";
$database = "werislin_IoT";
$conn = mysqli_connect($server, $username, $password, $database);
if (!$conn) {
  die('koneksi gagal boss : ' . mysqli_error());
}

echo "<table border=1>";
echo "<tr>";
echo "<td>ID</td>";
echo "<td>Tanggal Jam</td>";
echo "<td>Data 1</td>";
echo "<td>Data 2</td>";
echo "<td>Sensor ID</td>";
echo "<tr>";

	$sql2 = "SELECT * FROM ember ORDER BY ID DESC LIMIT 5000";
	$row= mysqli_query($conn,$sql2);
	while($srow=mysqli_fetch_array($row)){
		echo "<tr>";
		echo "<td>$srow[id]</td>";
		echo "<td>$srow[waktu]</td>";
		echo "<td>$srow[data1]</td>";
		echo "<td>$srow[data2]</td>";
		echo "<td>$srow[sensorid]</td>";
		echo "</tr>";
	}
mysqli_close($conn);
?>

