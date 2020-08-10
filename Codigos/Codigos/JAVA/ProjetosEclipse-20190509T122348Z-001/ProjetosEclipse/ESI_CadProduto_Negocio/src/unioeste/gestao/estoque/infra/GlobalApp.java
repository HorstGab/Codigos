/**
 * Title:        Infraestrutura 
 * Description:  Projeto sistema exemplo
 * Copyright:    Copyright (c) 2006
 * Company:      Unioeste
 * @author       Roberto Gil
 * @version 1.0
 */


package unioeste.gestao.estoque.infra;

import esI.geral.infra.ConexaoBD;
import esI.geral.infra.UsuarioBD;


public class GlobalApp {

  private static UsuarioBD usuarioBanco;
  private static ConexaoBD conexaoBD = null;
 
  public GlobalApp() {
  }

  public static void setUsuarioBanco (UsuarioBD ub) {
     usuarioBanco = ub;
  }

  public static UsuarioBD getUsuarioBanco () {
     return usuarioBanco;
  }

  public static void setConexaoBD (ConexaoBD conexao) {
     conexaoBD = conexao;
  }

  public static ConexaoBD getConexaoBD () throws Exception  {
	  if (conexaoBD == null) {
          conexaoBD = new ConexaoBD();
          UsuarioBD usuario = new UsuarioBD();
          usuario.setSenha("");
          usuario.setBanco("esI");
          usuario.setUsuario("root");
          conexaoBD.conectar(usuario);
       }
	  return conexaoBD;
  }


}
