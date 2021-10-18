package view;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import aes.Aes;
import javax.swing.JRadioButton;

public class ViewKeyAes extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textField;
	private JTextField textField_1;
	private ButtonGroup G1;


	
	/**
	 * Create the frame.
	 */
	public ViewKeyAes(String file) {
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 450, 200);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblChave = new JLabel("Chave");
		lblChave.setBounds(55, 12, 70, 15);
		contentPane.add(lblChave);
		
		textField = new JTextField("0123456789abcdef");
		textField.setBounds(208, 12, 168, 19);
		contentPane.add(textField);
		textField.setColumns(10);
		
		JLabel lblIv = new JLabel("IV");
		lblIv.setBounds(55, 49, 33, 15);
		contentPane.add(lblIv);
		
		textField_1 = new JTextField("AAAAAAAAAAAAAAAA");
		textField_1.setColumns(10);
		textField_1.setBounds(208, 47, 168, 19);
		contentPane.add(textField_1);
		
		JButton btnConfirma = new JButton("Confirma");
		btnConfirma.setBounds(152, 119, 117, 25);
		contentPane.add(btnConfirma);
		
		JRadioButton rdbtnCriptografar = new JRadioButton("Criptografar");
		rdbtnCriptografar.setBounds(28, 72, 149, 23);
		contentPane.add(rdbtnCriptografar);
		
		JRadioButton rdbtnDesciptografar = new JRadioButton("Descriptografar");
		rdbtnDesciptografar.setBounds(234, 72, 149, 23);
		contentPane.add(rdbtnDesciptografar);
		
		G1 = new ButtonGroup();
		G1.add(rdbtnCriptografar);
		G1.add(rdbtnDesciptografar);
		
		
		
		btnConfirma.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				
				if(!rdbtnCriptografar.isSelected()&&!rdbtnDesciptografar.isSelected()) {
					JOptionPane.showMessageDialog(contentPane, 
							"Erro, escolha uma opção de Criptografar ou Descriptografar!");
				}
				if(rdbtnCriptografar.isSelected()) {
					Aes.criptografiaAes(file, textField.getText(), textField_1.getText());
				}
				if(rdbtnDesciptografar.isSelected()) {
					Aes.descriptografarAes(file, textField.getText(), textField_1.getText());
				}
			}
		});
	}
}
