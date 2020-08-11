static Base* MontaExpressaoPrefix (char* Expressao){
	start_lex(Expressao);
	return MontaExpressaoRec();
}

static Base* MontaExpressaoRec(){
	Base *b = 0;
	get_next_token();
	if(Token.classe != EOF){
		switch (Token.classe){
			case '+': b = new soma();
				break;
			case '-': b = new subtracao();
				break;
			//case '*':
			//case '/':
			case IDENTIFIER:
				cout << "ERRO. Identificador nao previsto" << Token.repr;
				return 0;
			case INTERGER:
				return new numero(a+0+(Token.repr));
		}

		b->setEsq(MontaExpressaoRec());
		b->setDir(MontaExpressaoRec());
	}
	return b;
}