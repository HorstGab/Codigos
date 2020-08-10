package view;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

import javax.swing.Box;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.BevelBorder;
import javax.swing.border.EmptyBorder;

import model.Model;
import model.ModelCliente;
import util.Observador;
import util.Param;

public class ViewConsultarConta extends JInternalFrame  {

	private static final long serialVersionUID = 1L;

	private Observador observador;

	private JPanel contentPane;

	private JTextField fieldcpf;
	private JLabel lblnome;
	private JPanel botoes;
	private JButton btnConsultar;
	private JPanel panel;
	private JTable table;
	private TableModel tableModel;
	private JButton btnLimpar;
	private JButton btnInserir;
	private Component verticalStrut;
	private JButton btnEditar;
	private JTextField fieldnome;
	private JLabel lblsobrenome;
	private JTextField fieldsobrenome;

	public ViewConsultarConta( Observador observador ) {
		this.observador = observador;
		//Algumas configurações gerais
		setClosable(true);//Se o frame vai poder ser fechado pelo botão fechar 
		setIconifiable(true);//Se o frame vai poder ser minimizado.
		setResizable(true);//Pemite editar o tamanho.
				
		//setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 725, 532);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));

		panel = new JPanel();
		contentPane.add(panel, BorderLayout.CENTER);
		panel.setLayout(new BorderLayout(0, 0));

		JPanel consulta = new JPanel();
		consulta.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		panel.add(consulta, BorderLayout.NORTH);
		GridBagLayout gbl_consulta = new GridBagLayout();
		gbl_consulta.columnWidths = new int[]{206, 206, 206, 0};
		gbl_consulta.rowHeights = new int[]{20, 20, 0, 0};
		gbl_consulta.columnWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
		gbl_consulta.rowWeights = new double[]{0.0, 0.0, 0.0, Double.MIN_VALUE};
		consulta.setLayout(gbl_consulta);

		JLabel lblCPF = new JLabel("Nome do local:");
		lblCPF.setHorizontalAlignment(SwingConstants.RIGHT);
		GridBagConstraints gbc_lblCPF = new GridBagConstraints();
		gbc_lblCPF.anchor = GridBagConstraints.EAST;
		gbc_lblCPF.fill = GridBagConstraints.VERTICAL;
		gbc_lblCPF.insets = new Insets(0, 0, 5, 5);
		gbc_lblCPF.gridx = 0;
		gbc_lblCPF.gridy = 0;
		consulta.add(lblCPF, gbc_lblCPF);

		fieldcpf = new JTextField();
		lblCPF.setLabelFor(fieldcpf);
		fieldcpf.setPreferredSize(new Dimension(200, 20));
		fieldcpf.setToolTipText("locais de ocorr\u00EAncia dos itens do relat");
		GridBagConstraints gbc_fieldcpf = new GridBagConstraints();
		gbc_fieldcpf.gridwidth = 2;
		gbc_fieldcpf.fill = GridBagConstraints.BOTH;
		gbc_fieldcpf.insets = new Insets(0, 0, 5, 0);
		gbc_fieldcpf.gridx = 1;
		gbc_fieldcpf.gridy = 0;
		consulta.add(fieldcpf, gbc_fieldcpf);

		lblnome = new JLabel("Nome:");
		lblnome.setHorizontalAlignment(SwingConstants.RIGHT);
		GridBagConstraints gbc_lblnome = new GridBagConstraints();
		gbc_lblnome.anchor = GridBagConstraints.EAST;
		gbc_lblnome.fill = GridBagConstraints.VERTICAL;
		gbc_lblnome.insets = new Insets(0, 0, 5, 5);
		gbc_lblnome.gridx = 0;
		gbc_lblnome.gridy = 1;
		consulta.add(lblnome, gbc_lblnome);
		lblnome.setLabelFor(fieldnome);
		
		fieldnome = new JTextField();
		GridBagConstraints gbc_fieldnome = new GridBagConstraints();
		gbc_fieldnome.gridwidth = 2;
		gbc_fieldnome.insets = new Insets(0, 0, 5, 0);
		gbc_fieldnome.fill = GridBagConstraints.HORIZONTAL;
		gbc_fieldnome.gridx = 1;
		gbc_fieldnome.gridy = 1;
		consulta.add(fieldnome, gbc_fieldnome);
		fieldnome.setColumns(10);
		
		lblsobrenome = new JLabel("Sobrenome:");
		GridBagConstraints gbc_lblsobrenome = new GridBagConstraints();
		gbc_lblsobrenome.anchor = GridBagConstraints.EAST;
		gbc_lblsobrenome.insets = new Insets(0, 0, 0, 5);
		gbc_lblsobrenome.gridx = 0;
		gbc_lblsobrenome.gridy = 2;
		consulta.add(lblsobrenome, gbc_lblsobrenome);
		
		fieldsobrenome = new JTextField();
		fieldsobrenome.setColumns(10);
		GridBagConstraints gbc_fieldsobrenome = new GridBagConstraints();
		gbc_fieldsobrenome.gridwidth = 2;
		gbc_fieldsobrenome.fill = GridBagConstraints.HORIZONTAL;
		gbc_fieldsobrenome.gridx = 1;
		gbc_fieldsobrenome.gridy = 2;
		consulta.add(fieldsobrenome, gbc_fieldsobrenome);

		tableModel = new TableModel();
		tableModel.setHeaders( new String[] {"CPF", "Nome", "Sobrenome"}, 
				new String[] {"cpf", "nome", "sobrenome"});
		table = new JTable(tableModel);
		table.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				btnEditar.setEnabled(true);
				if (e.getClickCount() == 2) {
					edit();
				}
			}
				
		});
		table.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));

		// Create cell renderer for this view/table
		CellRenderer cellRenderer = new CellRenderer(SwingConstants.LEFT, SwingConstants.CENTER);
		for (int i = 0; i < table.getColumnCount(); i++) {
			table.getColumnModel().getColumn(i).setCellRenderer(cellRenderer);
		}

		JScrollPane scrollPane = new JScrollPane(table);
	
		table.setPreferredScrollableViewportSize(new Dimension(500, 70));
		panel.add(scrollPane, BorderLayout.CENTER);

		botoes = new JPanel();
		botoes.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		contentPane.add(botoes, BorderLayout.EAST);
		GridBagLayout gbl_botoes = new GridBagLayout();
		gbl_botoes.columnWidths = new int[]{103, 0};
		gbl_botoes.rowHeights = new int[]{1, 29, 23, 20, 29, 25, 0};
		gbl_botoes.columnWeights = new double[]{0.0, Double.MIN_VALUE};
		gbl_botoes.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		botoes.setLayout(gbl_botoes);

		btnConsultar = new JButton("Consultar");
		btnConsultar.setIcon(new ImageIcon(ViewConsultarConta.class.getResource("/resource/procurar.png")));
		btnConsultar.setSelectedIcon(new ImageIcon(ViewConsultarConta.class.getResource("/resource/procurar.png")));
		btnConsultar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				observador.consultar( getParams() );
			}
		});
		GridBagConstraints gbc_btnConsultar = new GridBagConstraints();
		gbc_btnConsultar.fill = GridBagConstraints.BOTH;
		gbc_btnConsultar.insets = new Insets(0, 0, 5, 0);
		gbc_btnConsultar.gridx = 0;
		gbc_btnConsultar.gridy = 1;
		botoes.add(btnConsultar, gbc_btnConsultar);

		btnLimpar = new JButton("Limpar");
		btnLimpar.setIcon(new ImageIcon(ViewConsultarConta.class.getResource("/resource/botaoLimpar.png")));
		btnLimpar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				fieldcpf.setText("");
				fieldnome.setText("");
				fieldsobrenome.setText("");
				tableModel.setData( new ArrayList<Model>() );
			}
		});
		GridBagConstraints gbc_btnLimpar = new GridBagConstraints();
		gbc_btnLimpar.fill = GridBagConstraints.BOTH;
		gbc_btnLimpar.insets = new Insets(0, 0, 5, 0);
		gbc_btnLimpar.gridx = 0;
		gbc_btnLimpar.gridy = 2;
		botoes.add(btnLimpar, gbc_btnLimpar);

		verticalStrut = Box.createVerticalStrut(20);
		GridBagConstraints gbc_verticalStrut = new GridBagConstraints();
		gbc_verticalStrut.anchor = GridBagConstraints.NORTH;
		gbc_verticalStrut.fill = GridBagConstraints.HORIZONTAL;
		gbc_verticalStrut.insets = new Insets(0, 0, 5, 0);
		gbc_verticalStrut.gridx = 0;
		gbc_verticalStrut.gridy = 3;
		botoes.add(verticalStrut, gbc_verticalStrut);

		btnInserir = new JButton("Inserir");
		btnInserir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				observador.manter( new ModelCliente() );
			}
		});
		btnInserir.setIcon(new ImageIcon(ViewConsultarConta.class.getResource("/resource/inserir.png")));
		GridBagConstraints gbc_btnInserir = new GridBagConstraints();
		gbc_btnInserir.fill = GridBagConstraints.BOTH;
		gbc_btnInserir.insets = new Insets(0, 0, 5, 0);
		gbc_btnInserir.gridx = 0;
		gbc_btnInserir.gridy = 4;
		botoes.add(btnInserir, gbc_btnInserir);

		btnEditar = new JButton("Editar");
		btnEditar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				edit();
			}
		});
		btnEditar.setIcon(new ImageIcon(ViewConsultarConta.class.getResource("/resource/edit.png")));
		GridBagConstraints gbc_btnEditar = new GridBagConstraints();
		gbc_btnEditar.anchor = GridBagConstraints.NORTH;
		gbc_btnEditar.fill = GridBagConstraints.HORIZONTAL;
		gbc_btnEditar.gridx = 0;
		gbc_btnEditar.gridy = 5;
		botoes.add(btnEditar, gbc_btnEditar);

		btnEditar.setEnabled(false);	
		
	}
	
	private void edit ( ) {
		observador.manter ( tableModel.getModel( table.getSelectedRow() ));
	}

	private ArrayList<Param> getParams () {	
		ArrayList<Param> al = new ArrayList<Param>();
		al.add ( new Param( "cpf", fieldcpf.getText() ) ) ;
		al.add ( new Param( "nome", fieldnome.getText() ));
		al.add ( new Param( "sobrenome", fieldsobrenome.getText() ));
		return al;
	}

	public void mostrar ( ArrayList<Model> array ) {
		tableModel.setData(array);
		btnEditar.setEnabled(false);
	}
	
	public void atualizar ( ModelCliente model, boolean ok ) {
		if (ok) {
			tableModel.atualizar (model);
		}
	}
	
	public void remover( ModelCliente model, boolean ok  ) {
		if (ok) {
			tableModel.remover (model);
		}
	}

}
