package codec;

import codec.transformada.Downsampling;
import codec.transformada.Quantizacao;
import codec.transformada.YCbCr;
import org.jetbrains.annotations.NotNull;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import static codec.transformada.DCT.*;



public class Codec {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		System.out.println("Insert Image");

		BufferedImage img = ImageIO.read(new File("/home/milena/Downloads/image.jpeg")); //ler imagem
		System.out.println("w - " + img.getWidth() + " h - " + img.getHeight());
		YCbCr cvt = new YCbCr();
		Downsampling dwn = new Downsampling();
		cvt = dwn.downsample(cvt.RGBtoYCbCr(img), img.getWidth(), img.getHeight(), 4);

		/*cvt.setY(dctTransformY(cvt.getY()));
		cvt.setCb(dctTransformCb(cvt.getCb()));
		cvt.setCr(dctTransformCr(cvt.getCr()));*/
		double [][]DCT = new double[0][0];
		for(int i=0, i<img.getWidth(); i++){
			for(int j=0; j<img.getHeight(); j++){
				DCT[i][j] = dctTransformY(cvt.getY());
			}
		}
		Quantizacao q = new Quantizacao();
		q = q.quantiza(DCT, img.getWidth(), img.getHeight());
		//cvt = q.quantiza(cvt.getY(), img.getWidth(), img.getHeight());


	}

	public static void printY (@NotNull YCbCr y){
		for (int i = 0; i < y.getY().length; i++){
			for (int j = 0; j < y.getY()[0].length; j++){
				System.out.println(y.getY()[i][j].getY());
			}
		}
	}

	public static void printCb (@NotNull YCbCr cb){
		for (int i = 0; i < cb.getCb().length; i++){
			for (int j = 0; j < cb.getCb()[0].length; j++){
				System.out.println(cb.getCb()[i][j].getCb());
			}
		}
	}

	public static void printCr (@NotNull YCbCr cr){
		for (int i = 0; i < cr.getCr().length; i++){
			for (int j = 0; j < cr.getCr()[0].length; j++){
				System.out.println(cr.getCr()[i][j].getCr());
			}
		}
	}

}
