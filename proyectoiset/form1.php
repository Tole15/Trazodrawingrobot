<!DOCTYPE html>
<html>
<head>
    <style>
        body {
            font-family: 'Bubblegum Sans', cursive;
            background-color: #fefaff;
            padding: 20px;
        }
        
        header {
            text-align: center;
            padding: 20px;
            background-color: #fefaff;
            margin-top: 0;
            margin-bottom: 80px;
        }
        
        header img {
            float: left;
            max-width: 130px;
            margin-top: -35px;
            margin-right: 20px;
        }
        
        header img:hover {
            transform: scale(1.1);
        }
        
        .container {
            display: flex;
            justify-content: space-between;
        }

        .left-section {
            flex: 1;
            text-align: left;
        }

        .right-section {
            flex: 1;
            text-align: right;
        }

        form {
            display: flex;
            flex-direction: column;
            align-items: flex-end;
            max-width: 400px;
            margin-top: 20px;
        }
        
        h1 {
            text-align: left;
            font-size: 30px;
            color: #080109;
            margin-bottom: 10px;
            margin-top: -40px;
            margin-left: 180px;
        }
        
        .image-containertrazo {
            display: flex;
            justify-content: left;
            align-items: left;
            flex-wrap: wrap;
            gap: 10px;
            margin-top: -55px;
            margin-left: 180px;
            height: min-content;
        }
        
        .image-containertrazo img {
            max-width: 500px;
            cursor: pointer;
            transition: transform 0.3s ease;
            border-radius: 50%;
            margin-left: -120px;
            margin-top: -110px;
            margin-bottom: -90px;
        }
        
        .image-containertrazo img:hover {
            transform: scale(1.1);
        }
        
        .image-container {     
            background: #fefaff;  
            display: flex;
            justify-content: center;
            align-items: center;
            flex-wrap: wrap;
            gap: 20px;
            margin-bottom: 20px;
            padding: 10px;
            margin: -10px 0 0 0;
            box-shadow: 0 10px 8px rgba(0, 0, 0, 0.1);
            height: min-content;
        }
           
        .image-container img {
            max-width: 180px;
            cursor: pointer;
            transition: transform 0.3s ease;
            border-radius: 50%;
        }
        
        .image-container img:hover {
            transform: scale(1.1);
        }
        
        .information {
            color: #080109;
            background-color: #fefaff;
            border-radius: 5px;
            box-shadow: 0 4px 7px rgba(0, 0, 0, 0.1);
            font-family: 'Bubblegum Sans', cursive;
            text-align: center;
            margin-top: 200px;
            margin-bottom: 50px;
        }

        .information h2 {
            font-size: 24px;
            color: #080109;
            margin-bottom: 10px;
            text-align: center;
        }

        .information p {
            color: #080109;
            font-size: 18px;
            line-height: 1.5;
            margin-bottom: 10px;
            text-align: center;
        }

        .information ul {
            list-style-type: disc;
            margin-left: 20px;
            margin-bottom: 10px;
            text-align: center;
            list-style: none;
        }

        .information li {
            font-size: 18px;
            color: #080109;
        }
        
        .university-info, .team-info {
            text-align: center;
        }
        
        .university-info h4, .team-info h4 {
            font-size: 18px;
            margin-bottom: 5px;
        }
        
        .university-info p, .team-info p {
            font-size: 14px;
            margin: 0;
        }
        
        .nexttoside {
            display: flex;
            justify-content: center;
            margin-top: 0;
        }

        .pause-button {
            width: 50%;
            margin-right: 30px;
            background-color: #f2dd5a;
            color: #080109;
            border: none;
            padding: 10px 20px;
            text-align: center;
            text-decoration: none;
            font-size: 16px;
            font-weight: bold;
            margin-top: 15px;
            cursor: pointer;
            border-radius: 10px;
            box-shadow: 0 10px 8px rgba(0, 0, 0, 0.1);
        }
        
        .pause-button:hover {
            background-color: #f8defc;
        }
        
        .finish-button { 
            width: 50%;
            margin-right: 35px;
            background-color: #f2dd5a;
            color: #080109;
            border: none;
            padding: 10px 20px;
            text-align: center;
            text-decoration: none;
            font-size: 16px;
            font-weight: bold;
            margin-top: 15px;
            cursor: pointer;
            border-radius: 10px;
            box-shadow: 0 10px 8px rgba(0, 0, 0, 0.1);
        }
        
        .finish-button:hover {
            background-color: #f8defc;
        }
        
        .reanudar-button { 
            width: 50%;
            margin-right: 35px;
            background-color: #f2dd5a;
            color: #080109;
            border: none;
            padding: 10px 20px;
            text-align: center;
            text-decoration: none;
            font-size: 16px;
            font-weight: bold;
            margin-top: 15px;
            cursor: pointer;
            border-radius: 10px;
            box-shadow: 0 10px 8px rgba(0, 0, 0, 0.1);
        }
        
        .reanudar-button:hover {
            background-color: #f8defc;
        }
        
        #lapiz {
            position: absolute;
            top: 300px;
            right: 48%;
            max-width: 255px;
            padding: 0 20px;
            transform: rotate(300deg);
        }
        
        #lapiz:hover {
            top: 320px;
            right: 47%;
            width: 250px;
            transform: scale(1.1);
            transform: rotate(320deg);
        }
        
        footer {
            color: #080109;
            padding: 25px;
            background-color: #f8defc;
            border-radius: 10px;
            width: 100%;
            margin: 0;
        }
     
        .footer-container {
            text-align: center;
            display: flex;
            justify-content: space-between;
            align-items: normal;
        }
    </style>
    <link href="https://fonts.googleapis.com/css?family=Bubblegum+Sans&display=swap" rel="stylesheet">
</head>
<body>
    <header>
        <img src="ucol.png" alt="Logo UdeC">
        <p style="text-align:right;"><a style="font-size: 25px; color:#080109; margin-top:-40px; margin-left:-30px;" href="info.html">Acerca de</a></p>
    </header>
    <div class="container">
        <div class="left-section">
            <h1>¡Hola! Soy TRAZO, tu robot de dibujo</h1>
            <div class="image-containertrazo">
                <img src="TRAZO.svg">
            </div>
            <h1>Prueba mi uso en la derecha</h1>
        </div>
        <div>
            <img id="lapiz" src="lapiz.png">
        </div>
        <div class="right-section">
            <form>
                <div class="image-container">
                    <img src="circulo.png" alt="Círculo" onclick="sendCommand('circulo')">
                    <img src="rectangulo.jpg" alt="Rectángulo" onclick="sendCommand('rectangle')">
                    <img src="triangulo.png" alt="Triángulo" onclick="sendCommand('triangle')">
                    <img src="cuadrado.png" alt="Cuadrado" onclick="sendCommand('square')">
                </div>
                <div class="nexttoside">
                    <button class="finish-button" onclick="sendCommand('finish')">Fin</button>
                    <button class="reanudar-button" onclick="sendCommand('reanudar')">Reanudar</button>
                    <button class="pause-button" onclick="sendCommand('paused')">Pausa</button>
                </div>
                <br>
            </form>
        </div>
    </div>

    <script>
        function sendCommand(shape) {
            switch (shape) {
                case 'circulo':
                    console.log('Comando enviado: ' + shape);
                    saveData(shape);
                    abrirEnlaceEnSegundoPlano("http://192.168.4.1/circle");
                    break;
                case 'rectangle':
                    console.log('Comando enviado: ' + shape);
                    saveData(shape);
                    abrirEnlaceEnSegundoPlano("http://192.168.4.1/rectangle");
                    break;
                case 'triangle':
                    console.log('Comando enviado: ' + shape);
                    saveData(shape);
                    abrirEnlaceEnSegundoPlano("http://192.168.4.1/triangle");
                    break;
                case 'square':
                    console.log('Comando enviado: ' + shape);
                    saveData(shape);
                    abrirEnlaceEnSegundoPlano("http://192.168.4.1/square");
                    break;
                case 'finish':
                    console.log('Comando enviado: ' + shape);
                    saveData(shape);
                    abrirEnlaceEnSegundoPlano("http://192.168.4.1/finish");
                    break;
                case 'pausa':
                    console.log('Comando enviado: ' + shape);
                    abrirEnlaceEnSegundoPlano("http://192.168.4.1/paused");
                    break;
                case 'reanudar':
                    console.log('Comando enviado: ' + shape);
                    abrirEnlaceEnSegundoPlano("http://192.168.4.1/reanudar");
                    break;
                default:
                    console.log('Forma no válida');
                    return;
            } 
        }

        function saveData(shape) {
            var url = 'save_selection.php?shape=' + shape;
            var xhr = new XMLHttpRequest();
            xhr.open('GET', url, true);
            xhr.onload = function() {
                if (xhr.status === 200) {
                    console.log('Datos guardados en la base de datos');
                } else {
                    console.log('Error al guardar los datos');
                }
            };
            xhr.send();
        }

        function abrirEnlaceEnSegundoPlano(url) {
            var enlace = document.createElement('a');
            enlace.href = url;
            enlace.target = '_blank';
            enlace.style.display = 'none';
            document.body.appendChild(enlace);
            enlace.click();
            document.body.removeChild(enlace);
        }
    </script>
</body>
</html>
