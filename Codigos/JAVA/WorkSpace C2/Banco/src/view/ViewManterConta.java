package view;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Box;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.BevelBorder;
import javax.swing.border.EmptyBorder;

import model.ModelCliente;
import util.Observador;

public class ViewManterConta extends JFrame {
	private static final long serialVersionUID = 1L;

	private JPanel contentPane;

	private Observador observador;
	private JButton btnExcluir;
	private JTextField fieldidcliente;
	private JTextField fieldnome;
	private JTextField fieldsobrenome;
	private JTextField fieldcpf;

	ModelCliente model;

	/**
	 * Create the frame.
	 */
	public ViewManterConta ( Observador ctrl_observador ) {
		this.observador = ctrl_observador;
		setResizable(false);
		setAlwaysOnTop(true);
		setTitle("Cadastro de Clientes");
		setIconImage(Toolkit.getDefaultToolkit().getImage(ViewManterConta.class.getResource("/resource/favicon.ico")));
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 463, 192);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);

		JPanel acoes = new JPanel();
		acoes.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		contentPane.add(acoes, BorderLayout.SOUTH);

		JButton btnSalvar = new JButton("Salvar");
		btnSalvar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (fieldcpf.getText().isEmpty()) {
					JOptionPane.showMessageDialog(null,"Preenchimento inválido...\n O campo `CPF´ precisa ser preenchido!");
					return;
				}
				if (fieldnome.getText().isEmpty()) {
					JOptionPane.showMessageDialog(null,"Preenchimento inválido...\n O campo `Nome´ precisa ser preenchido!");
					return;
				}
				if (fieldsobrenome.getText().isEmpty()) {
					JOptionPane.showMessageDialog(null,"Preenchimento inválido...\n O campo `Sobrenome´ precisa ser preenchido!");
					return;
				}

				model.setCpf( (fieldcpf.getText()));
				model.setNome( (fieldnome.getText()));
				model.setSobrenome( (fieldsobrenome.getText()));
				observador.salvar( model);		
				setVisible(false);
			}
		});
		btnSalvar.setIcon(new ImageIcon(ViewManterConta.class.getResource("/resource/gravar.png")));
		btnSalvar.setHorizontalAlignment(SwingConstants.LEFT);
		acoes.add(btnSalvar);

		btnExcluir = new JButton("Excluir");
		btnExcluir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int resposta = JOptionPane.showConfirmDialog(null, "Deseja realmente excluir este cadastro?", "Confirma��o",
						JOptionPane.YES_NO_OPTION);
				if (resposta == JOptionPane.YES_OPTION){
					observador.remover( model);
					setVisible(false);
				}
			}
		});
		btnExcluir.setIcon(new ImageIcon(ViewManterConta.class.getResource("/resource/excluir.png")));
		btnExcluir.setHorizontalAlignment(SwingConstants.LEFT);
		acoes.add(btnExcluir);

		Component horizontalStrut = Box.createHorizontalStrut(50);
		acoes.add(horizontalStrut);

		JButton btnFechar = new JButton("Fechar");
		btnFechar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
			}
		});
		btnFechar.setIcon(new ImageIcon(ViewManterConta.class.getResource("/resource/fechar.png")));
		acoes.add(btnFechar);

		JPanel panel = new JPanel();
		panel.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		contentPane.add(panel, BorderLayout.CENTER);
		GridBagLayout gbl_panel = new GridBagLayout();
		gbl_panel.columnWidths = new int[]{105, 65, 185, 0};
		gbl_panel.rowHeights = new int[]{30, 0, 0, 24, 0};
		gbl_panel.columnWeights = new double[]{0.0, 1.0, 1.0, Double.MIN_VALUE};
		gbl_panel.rowWeights = new double[]{0.0, 0.0, 0.0, 27.0, Double.MIN_VALUE};
		panel.setLayout(gbl_panel);

		JLabel lblidlocal = new JLabel("Identificador:");
		GridBagConstraints gbc_lblidlocal = new GridBagConstraints();
		gbc_lblidlocal.fill = GridBagConstraints.VERTICAL;
		gbc_lblidlocal.anchor = GridBagConstraints.EAST;
		gbc_lblidlocal.insets = new Insets(0, 0, 5, 5);
		gbc_lblidlocal.gridx = 0;
		gbc_lblidlocal.gridy = 0;
		panel.add(lblidlocal, gbc_lblidlocal);
		lblidlocal.setLabelFor(fieldidcliente);

		fieldidcliente = new JTextField();
		fieldidcliente.setHorizontalAlignment(SwingConstants.RIGHT);
		fieldidcliente.setEditable(false);
		fieldidcliente.setEnabled(false);
		fieldidcliente.setText("00000000");
		GridBagConstraints gbc_fieldidcliente = new GridBagConstraints();
		gbc_fieldidcliente.fill = GridBagConstraints.BOTH;
		gbc_fieldidcliente.insets = new Insets(0, 0, 5, 5);
		gbc_fieldidcliente.gridx = 1;
		gbc_fieldidcliente.gridy = 0;
		panel.add(fieldidcliente, gbc_fieldidcliente);
		fieldidcliente.setColumns(10);

		JLabel lblcpf = new JLabel("CPF:");
		GridBagConstraints gbc_lblcpf = new GridBagConstraints();
		gbc_lblcpf.fill = GridBagConstraints.VERTICAL;
		gbc_lblcpf.anchor = GridBagConstraints.EAST;
		gbc_lblcpf.insets = new Insets(0, 0, 5, 5);
		gbc_lblcpf.gridx = 0;
		gbc_lblcpf.gridy = 1;
		panel.add(lblcpf, gbc_lblcpf);

		fieldcpf = new JTextField();
		GridBagConstraints gbc_fieldcpf = new GridBagConstraints();
		gbc_fieldcpf.insets = new Insets(0, 0, 5, 5);
		gbc_fieldcpf.fill = GridBagConstraints.BOTH;
		gbc_fieldcpf.gridx = 1;
		gbc_fieldcpf.gridy = 1;
		panel.add(fieldcpf, gbc_fieldcpf);
		fieldcpf.setColumns(10);

		JLabel lblNome = new JLabel("Nome:");
		lblNome.setHorizontalAlignment(SwingConstants.RIGHT);
		lblNome.setLabelFor(lblNome);
		GridBagConstraints gbc_lblNome = new GridBagConstraints();
		gbc_lblNome.anchor = GridBagConstraints.EAST;
		gbc_lblNome.insets = new Insets(0, 0, 5, 5);
		gbc_lblNome.gridx = 0;
		gbc_lblNome.gridy = 2;
		panel.add(lblNome, gbc_lblNome);

		fieldnome = new JTextField();

		GridBagConstraints gbc_fieldnome = new GridBagConstraints();
		gbc_fieldnome.gridwidth = 2;
		gbc_fieldnome.insets = new Insets(0, 0, 5, 0);
		gbc_fieldnome.fill = GridBagConstraints.HORIZONTAL;
		gbc_fieldnome.gridx = 1;
		gbc_fieldnome.gridy = 2;
		panel.add(fieldnome, gbc_fieldnome);
		fieldnome.setColumns(50);

		JLabel lblSobrenome = new JLabel("Sobrenome:");
		GridBagConstraints gbc_lblSobrenome = new GridBagConstraints();
		gbc_lblSobrenome.fill = GridBagConstraints.VERTICAL;
		gbc_lblSobrenome.anchor = GridBagConstraints.EAST;
		gbc_lblSobrenome.insets = new Insets(0, 0, 0, 5);
		gbc_lblSobrenome.gridx = 0;
		gbc_lblSobrenome.gridy = 3;
		panel.add(lblSobrenome, gbc_lblSobrenome);

		fieldsobrenome = new JTextField();
		GridBagConstraints gbc_fieldsobrenome = new GridBagConstraints();
		gbc_fieldsobrenome.gridwidth = 2;
		gbc_fieldsobrenome.fill = GridBagConstraints.BOTH;
		gbc_fieldsobrenome.gridx = 1;
		gbc_fieldsobrenome.gridy = 3;
		panel.add(fieldsobrenome, gbc_fieldsobrenome);
		fieldsobrenome.setColumns(50);
		//setFocusTraversalPolicy(new FocusTraversalOnArray(new Component[]{lblidlocal, fieldidlocal, lblNome, fieldnome, lblEmUso, fieldativo, btnSalvar, btnExcluir, btnFechar}));
	}

	public void mostrar ( ModelCliente model ) {		
		this.model = model;
		fieldidcliente.setText(  String.valueOf( model.getIdcliente() ));
		fieldcpf.setText(model.getCpf());
		fieldnome.setText( model.getNome());
		fieldsobrenome.setText( model.getSobrenome());
		btnExcluir.setEnabled ( model.getIdcliente()!=-1);
		fieldnome.requestFocus();
		setVisible(true);
	}
}