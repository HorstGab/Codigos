package servico;

import java.sql.Connection;

import controle.ColAluno;
import sql.Query;
import unioeste.geral.parqueestudantil.bo.Aluno;
import unioeste.geral.parqueestudantil.bo.Curso;

public class UCManterAluno {

	public UCManterAluno(){}
	
	public int cadastrarAluno(String nome, int idade, int ano, int serie, Curso curso) throws Exception{
		Connection conn = Query.getConnection();
		conn.setAutoCommit(false);
		
		ColAluno colAluno = new ColAluno(conn);
		int ok = 0;
		
		try {
			if(nome != "") {
				Aluno a = new Aluno();
				a.setNomeCompleto(nome);
				a.setIdade(idade);
				a.setAno(ano);
				a.setSerie(serie);
				a.setCurso(curso);
				ok = colAluno.inserirAluno(a, conn);
			}else {
				System.err.println("Nome do Aluno não pode ser nula!");
			}
			conn.commit();
		}catch(Exception e) {
			e.printStackTrace();
			conn.rollback();
			System.err.println("O Aluno não foi cadastrado - Erro na classe: " + UCManterAluno.class.getName());
		}
		return ok;
	}
}
