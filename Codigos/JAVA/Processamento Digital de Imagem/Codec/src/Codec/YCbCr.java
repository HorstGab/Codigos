package Codec;

import java.awt.Color;
import java.awt.image.BufferedImage;

public class YCbCr {

	private int Y;
	private int Cb;
	private int Cr;
	public YCbCr(int y, int cb, int cr) {
		this.Y = y;
		this.Cb = cb;
		this.Cr = cr;
	}
	
	
	
	public YCbCr[][] RGBtoYCbCr(BufferedImage img) {
		YCbCr[][] ycbcrimg = new YCbCr[img.getWidth()][img.getHeight()];
		
		for(int i = 0; i < img.getWidth(); i++){
            for(int j = 0; j < img.getHeight(); j++){ 
            	
            	Color pixel = new Color (img.getRGB(i, j));
            	int r = pixel.getRed();
            	int g = pixel.getGreen();
            	int b = pixel.getBlue();
            	
            	double yd =  (0.299		*r) + (0.587	*g) + (0.114 	*b);
            	double Cbd = (-0.169	*r) + (-0.331 	*g) + (0.5 		*b);
            	double Crd = (0.5		*r) + (-0.419 	*g) + (-0.091	*b);
            	
            	ycbcrimg[i][j] = new YCbCr(Integer.parseInt(""+yd), 
            							   Integer.parseInt(""+Cbd), 
            							   Integer.parseInt(""+Crd));
            	
            }
		}
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
}
