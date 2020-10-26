package codec;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class YCbCr {

	private int Y;
	private int Cb;
	private int Cr;
	public YCbCr(){
		this.Y = 0;
		this.Cb = 0;
		this.Cr = 0;
	}
	public YCbCr(int y, int cb, int cr) {
		this.Y = y;
		this.Cb = cb;
		this.Cr = cr;
	}
	
	public YCbCr[][] RGBtoYCbCr(BufferedImage img) throws IOException {
		YCbCr[][] ycbcrimg = new YCbCr[img.getWidth()][img.getHeight()];
		
		for(int i = 0; i < img.getWidth(); i++){
            for(int j = 0; j < img.getHeight(); j++){ 
            	
            	Color pixel = new Color (img.getRGB(i, j));
            	int r = pixel.getRed();
            	int g = pixel.getGreen();
            	int b = pixel.getBlue();
            	
            	int y = (int) ((int) (0.299		*r) + (0.587	*g) + (0.114 	*b));
            	int Cb = (int) ((int)(-0.169	*r) + (-0.331 	*g) + (0.5 		*b));
            	int Cr = (int) ((int)(0.5		*r) + (-0.419 	*g) + (-0.091	*b));
            	
            	ycbcrimg[i][j] = new YCbCr(y,Cb,Cr);
            }
		}
		printYCbCr(ycbcrimg);
		convertYinImg(ycbcrimg);
		return ycbcrimg;
	}
	
	
	public void printYCbCr(YCbCr[][] ycbcrimg) {
		for(int i = 0; i < ycbcrimg.length; i++){
            for(int j = 0; j < ycbcrimg[0].length; j++){
            	System.out.println("Y = " + ycbcrimg[i][j].Y + 
            					   " Cb = " + ycbcrimg[i][j].Cb + 
            					   " Cr = " + ycbcrimg[i][j].Cr);
            }
		}
	}

	public void convertYinImg(YCbCr[][] ycbcrimg) throws IOException {
		FileWriter f = new FileWriter("Y.txt");
		PrintWriter gravarArq = new PrintWriter(f);

		for(int i = 0; i < ycbcrimg.length; i++){
			gravarArq.printf(String.valueOf(ycbcrimg[i][0]));
		}
		f.close();

	}
}
