package servlet;

import java.io.IOException;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import servico.UCManterAluno;
import unioeste.geral.parqueestudantil.bo.Aluno;
import unioeste.geral.parqueestudantil.bo.Curso;

@WebServlet("/index")
public class CadastroAluno extends HttpServlet{
	private static final long serialVersionUID = 1L;
	
	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public CadastroAluno() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	/**
     * @see HttpServlet#doGet(HttpServletRequest request,
     HttpServletResponse response)
     */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {        
    	// TODO Auto-generated constructor stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
    }
	
	


	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		doGet(request, response);
		
		UCManterAluno uca = new UCManterAluno();

		request.setCharacterEncoding("UTF-8");
		
		//todos os dados chegam no formato string
		//String imgs[] = request.getParameter("img");
		String nome = request.getParameter("name");
		String idade = request.getParameter("idade");
		String ano = request.getParameter("ano");
		String serie = request.getParameter("serie");
		String curso = request.getParameter("curso");
		
		try {
			System.out.println(nome + "nome");
			Aluno a = new Aluno();
			Curso c = new Curso();
			c.setNomeCurso(curso);
			a.setNomeCompleto(nome);
			a.setIdade(Integer.parseInt(idade));
			a.setAno(Integer.parseInt(ano));
			a.setSerie(Integer.parseInt(serie));
			a.setCurso(c);
			
			try {
				
				uca.cadastrarAluno(a.getNomeCompleto(), a.getIdade(), a.getAno(), a.getSerie(), a.getCurso());
			}catch(SQLException e2) {
				// TODO Auto-generated catch block
				e2.printStackTrace();
			}
		}catch(Exception e1){
			e1.printStackTrace();
		}
		
	//	request.setAttribute("ParqueEstudante", curso);
		request.getRequestDispatcher("/index.jsp").forward(request, response);
	}
}
