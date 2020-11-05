package codec;

import codec.transformada.DCT;
import codec.transformada.Downsampling;
import codec.transformada.Quantizacao;
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

//		BufferedImage img = ImageIO.read(new File("/home/gabriel/Downloads/image.jpeg"));
		BufferedImage img = ImageIO.read(new File("/home/milena/Downloads/imagem.jpeg")); //ler imagem
		System.out.println("w - " + img.getWidth() + " h - " + img.getHeight());

		int chunksize = 8;
		int w = chunksize;
		int h = chunksize;
		BufferedImage[] imgs = divideArray(img, chunksize);
		Downsampling dwn = new Downsampling();
		DCT dct = new DCT();

		int[][] r1 = new int[][]{null, null};
		int[][] r2 = new int[][]{null, null};
		int[][] r3 = new int[][]{null, null};

		Huffman hff = new Huffman();


		System.out.println(imgs.length);
		YCbCr[] cvt = new YCbCr[imgs.length];
		Quantizacao q = new Quantizacao();

		double[][] DCT1 = new double[0][];
		double[][] DCT2 = new double[0][];
		double[][] DCT3 = new double[0][];
		for (int i = 0; i < imgs.length; i++) {
			cvt[i] = new YCbCr();
			cvt[i] = dwn.downsample(cvt[i].RGBtoYCbCr(imgs[i]), w, h, 4);
			DCT1 = dct.dctTransformY(cvt[i].getY());
			DCT2 = dct.dctTransformCb(cvt[i].getCb());
			DCT3 = dct.dctTransformCr(cvt[i].getCr());

//			printY(cvt[i]);
		}

		/*
		nao finzalizado
		r1 = q.quantiza(DCT1, w, h);
		r2 = q.quantiza(DCT2, w, h);
		r3 = q.quantiza(DCT3, w, h);
		hff.compress();*/
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

<<<<<<< HEAD
		//writing mini images into image files

		for (int i = 0; i < imgs.length; i++) {
			ImageIO.write(imgs[i], "jpg", new File("img" + i + ".jpg"));
		}
		System.out.println("Mini images created");
=======

>>>>>>> bab5bb594342e6f1a39c7abbb769fc93b6d50aad


		return imgs;
	}
}