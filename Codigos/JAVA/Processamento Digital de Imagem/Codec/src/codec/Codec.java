package codec;

import codec.transformada.Cb;
import codec.transformada.Cr;
import codec.transformada.Y;
import codec.transformada.YCbCr;
import org.jetbrains.annotations.NotNull;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;



public class Codec {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		System.out.println("Insert Image");

		BufferedImage img = ImageIO.read(new File("/home/gabriel/Área de Trabalho/imagem.jpeg"));
//		BufferedImage img = ImageIO.read(new File("/home/milena/Downloads/image.jpeg")); //ler imagem
		System.out.println("w - " + img.getWidth() + " h - " + img.getHeight());
		YCbCr cvt = new YCbCr();
		ArrayList<YCbCr> list = new ArrayList<>();

		cvt = cvt.RGBtoYCbCr(img);

		list = divideArray(cvt, 8);

		for(int index = 0; index < list.size(); index++){
			System.out.println(list.get(index));
		}

//		Downsampling dwn = new Downsampling();
//		cvt = dwn.downsample(cvt.RGBtoYCbCr(img), img.getWidth(), img.getHeight(), 4);

		/*cvt.setY(dctTransformY(cvt.getY()));
		cvt.setCb(dctTransformCb(cvt.getCb()));
		cvt.setCr(dctTransformCr(cvt.getCr()));*/

//		double [][]DCT = new double[0][0];

		//O metodo dctTransformY já retorna uma matriz double, então dá pra guardar direto
		//na variavel
//		double[][] DCT = dctTransformY(cvt.getY());
//		for(int i = 0, i < img.getWidth(); i++){
//			for(int j=0; j<img.getHeight(); j++){
//				DCT[i][j] = dctTransformY(cvt.getY());
//			}
//		}
//		Quantizacao q = new Quantizacao();
//		q = q.quantiza(DCT, img.getWidth(), img.getHeight());
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

	public static ArrayList<YCbCr> divideArray(YCbCr img, int chunksize) {
		ArrayList<YCbCr> sub = new ArrayList<>();

		int aux = 0;

		int w = img.getY().length, h = img.getY()[0].length;

//		percorre toda a imagem
		for(int i = 0; i < w; i+=aux){
			for(int j = 0; j < h; j+=aux){

				//matriz do subconjunto
				Y[][] suby = new Y[chunksize][chunksize];
				Cb[][] subcb = new Cb[chunksize][chunksize];
				Cr[][] subcr = new Cr[chunksize][chunksize];

				//percorre a sub matriz
				for(int i1 = 0; i1 < chunksize; i1++) {
					for(int j1 = 0; j1 < chunksize; j1++){

						suby[i1][j1] = img.getY()[i1][j1];
						subcb[i1][j1] = img.getCb()[i1][j1];
						subcr[i1][j1] = img.getCr()[i1][j1];

					}
				}
				//add a sub matriz na lista
				sub.add(new YCbCr(suby,subcb,subcr));
				aux = 0;
			}
		}

		return sub;
	}

}
