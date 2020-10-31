package codec;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;


public class YCbCr {

	private Y[][] y;
	private Cb[][] cb;
	private Cr[][] cr;

	public YCbCr(){
		this.y= null;
		this.cb = null;
		this.cr = null;
	}
	public YCbCr(Y[][] y, Cb[][] cb, Cr[][] cr){
		this.y = y;
		this.cb = cb;
		this.cr = cr;
	}

	public Y[][] getY() {
		return y;
	}
	public void setY(Y[][] y) {
		this.y = y;
	}
	public Cb[][] getCb() {
		return cb;
	}
	public void setCb(Cb[][] cb) {
		this.cb = cb;
	}
	public Cr[][] getCr() {
		return cr;
	}
	public void setCr(Cr[][] cr) {
		this.cr = cr;
	}

	public YCbCr RGBtoYCbCr(BufferedImage img) throws IOException {
		Y[][] y = rgbtoY(img);
		Cb[][] cb = rgbtoCb(img);
		Cr[][] cr = rgbtoCr(img);

		YCbCr ycbcr = new YCbCr(y, cb, cr);
		return ycbcr;
	}

	public Y[][] rgbtoY (BufferedImage img) throws IOException {
		Y[][] my = new Y[img.getWidth()][img.getHeight()];
		for (int i = 0; i < img.getWidth(); i++) {
			for (int j = 0; j < img.getHeight(); j++) {
				Color pixel = new Color(img.getRGB(i, j));
				int r = pixel.getRed();
				int g = pixel.getGreen();
				int b = pixel.getBlue();

				int y = (int) ((int) (0.299 * r) + (0.587 * g) + (0.114 * b));
				my[i][j] = new Y(y);
			}
		}
		return my;
	}

	public Cb[][] rgbtoCb (BufferedImage img) throws IOException {
		Cb[][] mcb = new Cb[img.getWidth()][img.getHeight()];
		for (int i = 0; i < img.getWidth(); i++) {
			for (int j = 0; j < img.getHeight(); j++) {
				Color pixel = new Color(img.getRGB(i, j));
				int r = pixel.getRed();
				int g = pixel.getGreen();
				int b = pixel.getBlue();

				int cb = (int) ((int)(-0.169	*r) + (-0.331 	*g) + (0.5 		*b));
				mcb[i][j] = new Cb(cb);
			}
		}
		return mcb;
	}

	public Cr[][] rgbtoCr (BufferedImage img) throws IOException {
		Cr[][] mcr = new Cr[img.getWidth()][img.getHeight()];
		for (int i = 0; i < img.getWidth(); i++) {
			for (int j = 0; j < img.getHeight(); j++) {
				Color pixel = new Color(img.getRGB(i, j));
				int r = pixel.getRed();
				int g = pixel.getGreen();
				int b = pixel.getBlue();

				int cr = (int) ((int)(0.5		*r) + (-0.419 	*g) + (-0.091	*b));
				mcr[i][j] = new Cr(cr);
			}
		}
		return mcr;
	}
}
