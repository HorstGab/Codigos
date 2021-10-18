package aes;

import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

import arquivos.Arquivos;

public class Aes {

	public static void criptografiaAes(String file, String chave, String bytes) {
		// TODO Auto-generated method stub

		try {
	    	String txtArquivo = Arquivos.LeituraArquivo(file);
	    	byte[] textoencriptado = criptografar(txtArquivo, chave, bytes);
	    	Arquivos.EscritaArquivo(textoencriptado);
	      
	    } catch (Exception e) {
	      e.printStackTrace();
	    }
	  }
	
	
	public static void descriptografarAes(String file, String chave, String bytes){
		// TODO Auto-generated method stub
		try {
			byte[] txt = Arquivos.LeituraArquivoByte(file);
			String descriptxt = descriptografar(txt, chave, bytes); 
			System.out.println(descriptxt);
		}catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static String descriptografar(byte[] txt, String chave, String bytes) throws Exception {
		Cipher decripta = Cipher.getInstance("AES/CBC/PKCS5Padding", "SunJCE");
        SecretKeySpec key = new SecretKeySpec(chave.getBytes("UTF-8"), "AES");
        decripta.init(Cipher.DECRYPT_MODE, key,new IvParameterSpec(bytes.getBytes("UTF-8")));
        return new String(decripta.doFinal(txt),"UTF-8");
	}
	
	private static byte[] criptografar(String txt, String chave, String bytes) throws Exception {
		  Cipher encripta = Cipher.getInstance("AES/CBC/PKCS5Padding", "SunJCE");
		  SecretKeySpec key = new SecretKeySpec(chave.getBytes("UTF-8"), "AES");
		  encripta.init(Cipher.ENCRYPT_MODE, key, new IvParameterSpec(bytes.getBytes("UTF-8")));
		  return encripta.doFinal(txt.getBytes("UTF-8"));
	}
}
