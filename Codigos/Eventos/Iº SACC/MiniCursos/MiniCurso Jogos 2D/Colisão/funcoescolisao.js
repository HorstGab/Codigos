var canvas;
var ctx;
var largura;
var altura;
var desce = false;
// var fps = 0;
var quadrado ={
	largura:50,
	altura:35,
	x:10,
	y:10,
	vel:10,
	desenha:function (argument) {
		ctx.beginPath();
		ctx.fillStyle = "#faa";
		ctx.fillRect(this.x, this.y, this.largura, this.altura);
	},
	move:function(){
		if (this.x + this.largura < largura) 
			this.x += this.vel;
	},
};

var circulo={
	raio: 17,
	x:750,
	y:30,
	vel:10,
	desenha:function(){
		ctx.fillStyle = "#a0d";
		ctx.arc(this.x, this.y, this.raio, 0, Math.PI*2, true);
		ctx.fill();
	},
	move:function(){
		this.x -= this.vel;
		if(desce)
			this.y += this.vel;
	},
	colisao:function(){
		if((this.x-this.raio) <= (quadrado.x+quadrado.largura))
			// alert("Vai bater Caralho");
			desce = true;

	}
	
}


function atualizar() {
	quadrado.move();
	// circulo.move();
	circulo.colisao();
}
function desenhar() {
	ctx.fillStyle = "#aef";
	ctx.fillRect(0,0, largura, altura);
	if(!desce) 
		quadrado.desenha();
	circulo.desenha();
}
function executar() {
	atualizar();
	desenhar();
	window.requestAnimationFrame(executar);
}

function inicio() {
	largura = 800;
	altura = 600;

	canvas = document.createElement("canvas");
	canvas.width = largura;
	canvas.height = altura;
	ctx = canvas.getContext("2d");

	document.body.appendChild(canvas);
	executar();
}

function teclaPressionada(event) {
	switch(event.keyCode){
		case 38: //up
			circulo.y-=10;
			break;
		case 40: //down
			circulo.y+=10;
			break;
		case 37: //left
			circulo.x-=10;
			break;
		case 39: //right
			circulo.x+=10;
			break;
	}
}

window.addEventListener('keydown', teclaPressionada, true);
inicio();