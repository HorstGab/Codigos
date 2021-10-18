package arquivos;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;

public class Arquivos {

	public static String LeituraArquivo (String diretorio) throws IOException {
		 
		FileReader arq = new FileReader(diretorio); 
		BufferedReader lerArq = new BufferedReader(arq);
		String linha = lerArq.readLine(); 
		String txtArquivo = linha;

		while (linha != null) {
			linha = lerArq.readLine(); 
		    if (linha != null) {
		    	txtArquivo = txtArquivo + "\n"+linha; 
		    }
		}
		arq.close();
		return txtArquivo;
	}
	
	public static byte[] LeituraArquivoByte(String diretorio) throws IOException {
		byte[] fbytes = null;
		try{
			File file = new File(diretorio);
	        fbytes = Files.readAllBytes(file.toPath());
        }catch(IOException e) {
        	System.err.println("LeituraArquivoByte");
            e.printStackTrace();
        }
		return fbytes;
	}
	  
	public static void EscritaArquivo(byte[] txt) throws IOException {
		
		File f = new File("crip.txt");
		if(f.exists()) {
			f.delete();
			f = new File("crip.txt");
		}
		FileOutputStream in = new FileOutputStream(f);
		in.write(txt);
		in.close();
	 }
	  
	  
}
