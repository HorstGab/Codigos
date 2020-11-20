<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="pt_br">
<head>
<meta charset="UTF-8">
<title>Parque dos Estudantes Unioeste</title>
<link rel="stylesheet" href="style.css">
<script src="script.js"></script>
</head>

<body>

    <div class="container">
        <div id="main-container">
            <h1>Parque dos Estudantes UNIOESTE</h1>
            <form id="register-form" method="post" action="index">
                <div class="half-box"> 
                    <label for="img">Selecionar imagem:</label>
                    <input type="file" id="img" name="img" accept="image/*" multiple>
                </div>
                <div class="full-box">
                    <label for="name">Nome do Aluno</label>
                    <input type="text" name ="name" id="name" placeholder="Nome Completo" data-min-lenght="5"/>
                </div>
                <div class="half-box">
                    <label for="idade">Idade</label>
                    <input type="number" name ="idade" id="idade" placeholder="Idade do Aluno" />
                </div>
                <div class="half-box">                    
                    <label for="ano">Ano:</label>
                    <input type="number" name="ano" id="ano" placeholder="Ano"/>
                </div>
                <div class="half-box">
                    <label for="serie">Série:</label>
                    <input type="number" name="serie" id="serie" placeholder="Série do Aluno"/>
                </div>
                <div class="full-box"> 
                    <label for="curso">Curso:</label>
                    <input type="text" name="curso" id="curso" placeholder="Curso Matriculado" data-min-lenght="5"/>
                </div>
                <div class="full-box">
                    <input type="submit" id="btn-submit" value="OK"/>
                </div>
            </form>
        </div>
        
       
        <p class="error-validation template"></p>

        <script>
            // Initialize and add the map
            function initMap() {
                //feather.replace();

                map = new google.maps.Map(document.getElementById("map"), {
                    center: new google.maps.LatLng(-20.475261, -55.802089),
                    zoom: 16,
                });

                const features = [
                {
                    position: new google.maps.LatLng(-20.475142305591216,-55.801997673243065), //coit�
                },
                {
                    position: new google.maps.LatLng(-20.475426658990521,-55.802209928861181), //jasmim manga
                },
                {
                    position: new google.maps.LatLng(-20.475236444953882,-55.802034738417149), //jasmim deserto
                }
                ];
            
               

                const contentString = 
                [
                    
                        '<div id="content">' +
                        '<div id="siteNotice">' +
                        "</div>" +
                        '<h1 id="firstHeading" class="firstHeading">Coit�</h1>' +
                        '<div id="bodyContent">' +
                        "<div>Aluno: Gabriel H. Montoanelli</div>" +
                        "<div>Curso: Ci�ncia da Computa��o</div>" +
                        "<div> Serie: 4� Ano </div>" + 
                        "<div>Nome Popular: Coit�</div>" +
                        "<div>Nome Cient�fico: Crescentia Cujete </div>" +
                        "<div> Data do Plantio: 11/11/2020 " +
                        '<div> <img src="Coite.jpg" width=100 height=100> </div>'+
                        "</div>" +
                        "</div>",
                    
                        '<div id="content">' +
                        '<div id="siteNotice">' +
                        "</div>" +
                        '<h1 id="firstHeading" class="firstHeading">Jasmim Manga</h1>' +
                        '<div id="bodyContent">' +
                        "<div>Aluno: Gabriel H. Montoanelli</div>" +
                        "<div>Curso: Ci�ncia da Computa��o</div>" +
                        "<div> Serie: 4� Ano </div>" + 
                        "<div>Nome Popular: Jasmim Manga</div>" +
                        "<div>Nome Cient�fico: Plumeria Rubra </div>" +
                        "<div> Data do Plantio: 11/11/2020 " +
                        '<div> <img src="JasmimManga.jpg" width=100 height=100> </div>'+
                        "</div>" +
                        "</div>",
                    
                       
                        '<div id="content">' +
                        '<div id="siteNotice">' +
                        "</div>" +
                        '<h1 id="firstHeading" class="firstHeading">Jasmim do Deserto/Caribe</h1>' +
                        '<div id="bodyContent">' +
                        "<div>Aluno: Gabriel H. Montoanelli</div>" +
                        "<div>Curso: Ci�ncia da Computa��o</div>" +
                        "<div> Serie: 4� Ano </div>" + 
                        "<div>Nome Popular: Jasmim do Deserto</div>" +
                        "<div>Nome Cient�fico: Plumeria Pudica </div>" +
                        "<div> Data do Plantio: 11/11/2020 " +
                        '<div> <img src="JasmimCaribe.jpg" width=100 height=100> </div>'+
                        "</div>" +
                        "</div>"
                    
                ];

                // The marker, positioned at Uluru
                    // Create markers.
                for (let i = 0; i < features.length; i++) {
                    const marker = new google.maps.Marker({
                        position: features[i].position,
                        map: map,
                        title: "Parque Estudantil"
                    });

                    const infowindow = new google.maps.InfoWindow({
                        content: contentString[i],
                        maxWidth: 250,
                    });
                    marker.addListener("click", () => {
                    infowindow.open(map, marker);
                    });
                }
            }      
                
        </script>
        <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCFNI-xc1Z282nonyomwhVYT5E1n6doeNc&callback=initMap&libraries=&v=weekly"
          defer>
        </script>
        <div id= "map"></div>
    </div> 
</body>


</html>