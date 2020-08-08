package model;

public class ContaCorrente implements Contas {

	private double saldo;
	private double taxaPorOperacao = 0.45;
	
	@Override
	public void deposita(double valor) {
		// TODO Auto-generated method stub
		this.saldo += valor - this.taxaPorOperacao;
	}

	@Override
	public void saca(double valor) {
		// TODO Auto-generated method stub
		this.saldo -= valor - this.taxaPorOperacao;
	}

	@Override
	public double getSaldo() {
		// TODO Auto-generated method stub
		return this.saldo;
	}

}
