<?php

$ip = $_SERVER['HTTP_X_FORWARDED_FOR'] ?? $_SERVER['REMOTE_ADDR'];
$figure = $_GET['shape'];
$selection_date = date('Y-m-d H:i:s');
$servername = "localhost";
$username = "root";
$password = "rootroot";
$dbname = "dibujos";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Error de conexión a la base de datos: " . $conn->connect_error);
}

$stmt = $conn->prepare("INSERT INTO user_selections (ip, figure, selection_date) VALUES (?, ?, ?)");
$stmt->bind_param("sss", $ip, $figure, $selection_date);

if ($stmt->execute() === TRUE) {
    echo "Los datos se han guardado correctamente en la base de datos.";
} else {
    echo "Error al guardar los datos: " . $conn->error;
}

$stmt->close();
$conn->close();

?>
