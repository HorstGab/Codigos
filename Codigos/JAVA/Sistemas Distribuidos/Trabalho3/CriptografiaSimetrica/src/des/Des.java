package des;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

import arquivos.Arquivos;

public class Des {
	
	private static SecretKey keys = null;

	public static void crip (String file) {
		try {
			String txtArquivo = Arquivos.LeituraArquivo(file);
	    	byte[] textoencriptado = criptografar(txtArquivo);
	    	
	    	System.out.println("Texto encriptado : " + new String(textoencriptado));
	    	
	    	String txtDescrip = descriptografar(textoencriptado);
	    	System.out.println(txtDescrip);
		}catch (Exception e) {
		      e.printStackTrace();
		    }
	}
	

	private static byte[] criptografar(String txt) throws Exception {
		KeyGenerator keygenerator = KeyGenerator.getInstance("DES");
        keys = keygenerator.generateKey();
		Cipher encripta = Cipher.getInstance("DES/ECB/PKCS5Padding");
		encripta.init(Cipher.ENCRYPT_MODE, keys);
		return encripta.doFinal(txt.getBytes("UTF-8"));
	}
	
	
	private static String descriptografar(byte[] txt) throws Exception {
		Cipher decripta = Cipher.getInstance("DES/ECB/PKCS5Padding");
        decripta.init(Cipher.DECRYPT_MODE, keys);
        return new String(decripta.doFinal(txt),"UTF-8");
	}
}
