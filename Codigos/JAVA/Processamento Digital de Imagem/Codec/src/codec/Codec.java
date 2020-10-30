package codec;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


public class Codec {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		System.out.println("Insert Image");
		/*Scanner in = new Scanner(System.in);
		String caminho = in.nextLine();*/

		BufferedImage img = ImageIO.read(new File("/home/gabriel/Área de Trabalho/imagem.jpeg")); //ler imagem

		YCbCr cvt = new YCbCr();
		YCbCr[][] CVT1 = cvt.RGBtoYCbCr(img);

	}

}
