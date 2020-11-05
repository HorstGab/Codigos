package codec;

import codec.transformada.Downsampling;
import codec.transformada.YCbCr;
import org.jetbrains.annotations.NotNull;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


public class Codec {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		System.out.println("Insert Image");

		BufferedImage img = ImageIO.read(new File("/home/gabriel/Downloads/image.jpeg"));
//		BufferedImage img = ImageIO.read(new File("/home/milena/Downloads/image.jpeg")); //ler imagem
		System.out.println("w - " + img.getWidth() + " h - " + img.getHeight());

		int chunksize = 8;
		int w = chunksize;
		int h = chunksize;
		BufferedImage[] imgs = divideArray(img, chunksize);
		Downsampling dwn = new Downsampling();


		System.out.println(imgs.length);
		YCbCr[] cvt = new YCbCr[imgs.length];
		for(int i = 0; i < imgs.length; i++){
			cvt[i] = new YCbCr();
			cvt[i] = dwn.downsample(cvt[i].RGBtoYCbCr(imgs[i]), w, h, 4);

//			printY(cvt[i]);
			//O metodo dctTransformY já retorna uma matriz double, então dá pra guardar direto
			//na variavel
//			double[][] DCT = dctTransformY(cvt[i].getY());
//			for(int index = 0; index < img.getWidth(); index++){
//				for(int j=0; j<img.getHeight(); j++){
//					DCT[i][j] = dctTransformY(cvt.getY());
//				}
//			}
//		Quantizacao q = new Quantizacao();
//		q = q.quantiza(DCT, imgs[i].getWidth(), img[i].getHeight());
			//cvt[i] = q.quantiza(cvt[i].getY(), img[i].getWidth(), img[i].getHeight());
		}


		/*cvt.setY(dctTransformY(cvt.getY()));
		cvt.setCb(dctTransformCb(cvt.getCb()));
		cvt.setCr(dctTransformCr(cvt.getCr()));*/

//		double [][]DCT = new double[0][0];


		System.out.println("Done");
		//writing mini images into image files
		for (int i = 0; i < imgs.length; i++) {
			ImageIO.write(imgs[i], "jpg", new File("img.jpeg"));
		}
		System.out.println("Mini images created");

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

	public static BufferedImage[] divideArray(BufferedImage img, int chunksize) throws IOException {

		int chunkWidth = img.getWidth() / chunksize;
		int chunkHeight = img.getHeight() / chunksize;
		int count = 0;

		BufferedImage imgs[] = new BufferedImage[chunksize*chunksize];
		for(int i = 0; i < chunksize; i++){
			for(int j = 0; j < chunksize; j++){

				imgs[count] = new BufferedImage(chunkWidth, chunkHeight, img.getType());
//				count++;

				// draws the image chunk
				Graphics2D gr = imgs[count++].createGraphics();
				gr.drawImage(img, 0, 0, chunkWidth, chunkHeight, chunkWidth * j, chunkHeight * i, chunkWidth * j + chunkWidth, chunkHeight * i + chunkHeight, null);
				gr.dispose();

			}
		}

		System.out.println("Splitting done");




		return imgs;
	}
}
