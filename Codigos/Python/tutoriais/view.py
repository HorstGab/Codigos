import PySimpleGUI as sg

class ViewPython:
    def __init__(self):
      
        sg.change_look_and_feel('DarkBrown4') #alterar o layout da view  
        #layout
        layout = [
            [sg.Text('Nome', size=(5,0)), sg.Input(size=(15,0),key='nome')],
            [sg.Text('Idade', size=(5,0)), sg.Input(size=(15,0),key='idade')],
            [sg.Text('Quais provedores de e-mail são aceitos?')],
            [sg.Checkbox('Gmail', key='gmail'), sg.Checkbox('Outlook', key='outlook'), sg.Checkbox('Yahoo', key='yahoo')],
            [sg.Text('Aceita cartão?')],
            [sg.Radio('Sim','cartões', key = 'aceitacartao'),sg.Radio('Não','cartões', key = 'naoaceitacartao')],
            [sg.Button('Enviar Dados')],
            [sg.Output(size=(30,20))] #log
        ]
        #janela
        janela = sg.Window("Dados do Usuário").layout(layout ) 
        #extrair os dados
        self.button, self.values = janela.Read() 

    def Iniciar(self):
        nome = self.values['nome']
        idade = self.values['idade']
        aceita_gmail = self.values['gmail'] 
        aceita_hotlook = self.values['outlook']
        aceita_yahoo = self.values['yahoo'] 
        aceita_cartão = self.values['aceitacartao']
        nao_aceita_cartão = self.values['naoaceitacartao']

        print(f'nome: {nome}')
        print(f'idade: {idade}')
        print(f'aceita gmail: {aceita_gmail}')
        print(f'aceita outlook: {aceita_hotlook}')
        print(f'aceita yahoo: {aceita_yahoo}')
        print(f'aceita cartão: {aceita_cartão}')
        print(f'não aceita cartão: {nao_aceita_cartão}')


view = ViewPython()
view.Iniciar()