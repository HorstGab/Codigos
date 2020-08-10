package model;


public class ModelMovimentacao extends Model {
	
	protected int    idmovimentacao=-1;
	protected int    idconta;
	protected String descricao;
	protected double valor;
	protected String tipo;
	
	@Override
	public int getId() {
		return this.idmovimentacao;
	}
	
	public int getIdmovimentacao() {
		return idmovimentacao;
	}

	public void setIdmovimentacao(int idmovimentacao) {
		this.idmovimentacao = idmovimentacao;
	}

	public int getIdconta() {
		return idconta;
	}

	public void setIdconta(int idconta) {
		this.idconta = idconta;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public double getValor() {
		return valor;
	}

	public void setValor(double valor) {
		this.valor = valor;
	}

	public String getTipo() {
		return tipo;
	}
	
	public void setTipo(String tipo) {
		this.tipo = tipo;
	}
	
	public String toString() {
		return this.tipo + " " + this.valor + "\n";
	}

	
}
