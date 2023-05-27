<?php
// Configuración del puerto serial
$serialPort = 'COM3';  
$baudRate = 115200;

// Obtener el comando enviado desde JavaScript
$command = $_GET['command'];

// Crear el comando completo con el formato adecuado para el esp32
$arduinoCommand = $command . "\n";

// Abrir el puerto serial
$serial = fopen($serialPort, 'w+');
if (!$serial) {
    echo 'Error al abrir el puerto serial';
    exit;
}

// Establecer la configuración del puerto serial
stream_set_timeout($serial, 2);  // Configura un tiempo de espera de 2 segundos
exec("mode $serialPort: BAUD=$baudRate PARITY=N data=8 stop=1 xon=off");

// Enviar el comando a Arduino
fwrite($serial, $arduinoCommand);

// Leer la respuesta de Arduino
$response = '';
while ($char = fread($serial, 1)) {
    $response .= $char;
}

// Cerrar el puerto serial
fclose($serial);

// Enviar la respuesta de vuelta a JavaScript
echo $response;
?>
