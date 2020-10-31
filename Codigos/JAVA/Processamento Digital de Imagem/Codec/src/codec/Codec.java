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
		System.out.println("w - " + img.getWidth() + " h - " + img.getHeight());
		YCbCr cvt = new YCbCr();
		Downsampling dwn = new Downsampling();
		YCbCr[][] CVT1 = dwn.downsample(cvt.RGBtoYCbCr(img), img.getHeight(), img.getHeight(), 4);
		printY(CVT1);
	}

	public static void printY (YCbCr[][] y){
		for (int i = 0; i < y.length; i++){
			for (int j = 0; j < y[0].length; j++){
				System.out.println(y[i][j].getCb());
			}
		}
	}

}
