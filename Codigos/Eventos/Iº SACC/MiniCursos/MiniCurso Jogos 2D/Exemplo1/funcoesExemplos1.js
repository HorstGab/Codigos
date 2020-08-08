var canvas;
var ctx;
var triangulo = {
	xp1:50,
	xp2:100,
	xp3:100,
	yp1:50,
	yp2:100,
	yp3:50,
	vel:0.1,
	desenha:function() {
		ctx.beginPath();
		ctx.moveTo(this.xp1, this.yp1);
		ctx.lineTo(this.xp2, this.yp2);
		ctx.lineTo(this.xp3, this.yp3);
		ctx.fill();
	},
	move:function() {
		this.xp1++;
		this.xp2++;
		this.xp3++;
	}

}

function desenhar() {
	ctx.fillStyle = "#aef";
	ctx.fillRect(0,0, 400, 300);
	ctx.fillStyle = "#000";
	triangulo.desenha();
}

function atualizar(){
	triangulo.move();
}

function executar() {
	desenhar();
	atualizar();
	window.requestAnimationFrame(executar);
}

function inicio() {
	canvas = document.createElement("canvas");
	canvas.width = 800;
	canvas.height = 600;
	ctx = canvas.getContext("2d");

	document.body.appendChild(canvas);
	executar();
}
inicio();