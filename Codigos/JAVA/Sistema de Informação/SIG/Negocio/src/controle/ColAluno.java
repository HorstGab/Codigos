package controle;

import java.sql.Connection;
import java.sql.SQLException;

import dao.DaoAluno;
import dao.DaoCurso;
import unioeste.geral.parqueestudantil.bo.Aluno;
import util.NegocioException;

public class ColAluno {
	
	public Connection con;
	
	public ColAluno (Connection connection) {
		con = connection;
	}
	
	public int inserirAluno(Aluno a, Connection con)throws NegocioException, SQLException {
		int res = 0;
		DaoAluno daoAluno = new DaoAluno();
		DaoCurso daoCurso = new DaoCurso();
		
		int idCurso = daoCurso.getIdCursoPorNome(a.getCurso().getNomeCurso(), con);
		if(idCurso < 0) {
			idCurso = daoCurso.insereCurso(a.getCurso().getNomeCurso(), con);
		}
		if (daoAluno.validarAluno(a.getNomeCompleto(), con)){
			
			res = daoAluno.insereAluno(a.getNomeCompleto(), a.getIdade(), a.getAno(),
					a.getSerie(), idCurso,con);
		}else {
			System.out.println("Já existe uma arvore plantada com o nome desse Aluno!");
		}
		return res ;
	}

}
