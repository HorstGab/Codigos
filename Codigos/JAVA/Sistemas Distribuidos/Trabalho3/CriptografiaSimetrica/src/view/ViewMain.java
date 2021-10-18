package view;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import des.Des;


public class ViewMain {

	private JFrame frmCriptografiaSimtrica;
	private JTextField textFieldDir;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				try {
					ViewMain window = new ViewMain();
					window.frmCriptografiaSimtrica.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public ViewMain() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmCriptografiaSimtrica = new JFrame();
		frmCriptografiaSimtrica.setTitle("Criptografia Simétrica");
		frmCriptografiaSimtrica.setBounds(100, 100, 450, 250);
		frmCriptografiaSimtrica.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmCriptografiaSimtrica.getContentPane().setLayout(null);
		
		textFieldDir = new JTextField();
		textFieldDir.setBounds(140, 10, 300, 19);
		frmCriptografiaSimtrica.getContentPane().add(textFieldDir);
		textFieldDir.setColumns(10);
		
		
		JButton btnExecutar = new JButton("Executar");
		btnExecutar.setBounds(32, 159, 117, 25);
		frmCriptografiaSimtrica.getContentPane().add(btnExecutar);
		
		JButton btnCancelar = new JButton("Cancelar");
		btnCancelar.setBounds(273, 159, 117, 25);
		frmCriptografiaSimtrica.getContentPane().add(btnCancelar);
		
		JButton btnDiretorio = new JButton("Diretório");
		btnDiretorio.setBounds(12, 10, 117, 25);
		frmCriptografiaSimtrica.getContentPane().add(btnDiretorio);
		
		JComboBox<String> comboBox = new JComboBox<String>();
		comboBox.setBounds(140, 89, 104, 24);
		comboBox.addItem("AES");
		comboBox.addItem("DES");
		frmCriptografiaSimtrica.getContentPane().add(comboBox);
		
		JLabel lblAlgoritmo = new JLabel("Algoritmo");
		lblAlgoritmo.setBounds(31, 94, 70, 15);
		frmCriptografiaSimtrica.getContentPane().add(lblAlgoritmo);
		
		btnDiretorio.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				JFileChooser file = new JFileChooser();
				file.setFileSelectionMode(JFileChooser.FILES_ONLY);
				int i = file.showSaveDialog(null);
				if(i == 1) {
					textFieldDir.setText("");
			    } else {
			        File arquivo = file.getSelectedFile();
			        textFieldDir.setText(arquivo.getPath());
				}
				
			}
		});
		
		btnExecutar.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				
				
				if(textFieldDir.getText().equals("")) {
					JOptionPane.showMessageDialog(frmCriptografiaSimtrica, 
							"Erro, Arquivo não selecionado!");
				}
				
			
				if(comboBox.getSelectedItem().equals("AES")) {
					ViewKeyAes frame = new ViewKeyAes(textFieldDir.getText());
					frame.setVisible(true);
					
				}
				
				if(comboBox.getSelectedItem().equals("DES")) {
					Des.crip(textFieldDir.getText());
				}
				
				
				
			}
		});
		
		btnCancelar.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				System.exit(0);			}
		});
			
	}
}
