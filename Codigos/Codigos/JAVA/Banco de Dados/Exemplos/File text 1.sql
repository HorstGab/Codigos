/*desc pessoa;*/

/*alter table pessoas
rename to Pessoa;

alter table pessoas
add column profissao varchar(10) after nome;

alter table pessoas
modify column profissao varchar(20);

alter table pessoas
change column profissao prof varchar(20);

alter table pessoas
drop column profissao;*/

/*select * from pessoa;
select * from cursos;*/



/*desc cursos;
create table if not exists cursos(
	nome varchar(30) not null unique,
    descricao text,
    carga int unsigned *//*sem sinal*//*,
    totalAula int unsigned,
    ano year default '2019'
)default charset = utf8;

alter table cursos
add column idCurso int first;

alter table cursos
add primary key(idCurso);*/

/*alter table cursos
modify column nome varchar(50);*/

/*insert into cursos values
('1', 'CN', 'Disciplina de Numerico', '4', '1', 2019),
('2', 'BD', 'Construcao e relacionamento de banco de dados', '4', '1', '2019'),
('3', 'Compiladores', 'Construcao de compiladores e linguagens', '4', '1', '2019'),
('4', 'Engenharia de Sw', 'Sistematização de implementação', '4', '1', '2019'),
('5', 'Empreendedorismo', 'bobeira', '4', '1', '2019'),
('6', 'OAC', 'Baixo nivel', '4', '1', '2019'),
('7', 'PAA', 'projetar e analisar os algoritmos', '4', '1', '2019'),
('8', 'Redes', 'sistemas de redes', '2', '1', '2019'),
('9', 'SO', '', '2', '1', '2019'),
('10', 'Direito da Inovação Tecnologica', '', '2', '1','2020');*/

select * from cursos;
select * from pessoa;
desc pessoa;
desc cursos;


/*update cursos
set descricao = '' 
where idcurso = '5'
limit 1;*/

/*DELETE FROM cursos WHERE idCursos = '9'; deleta de cursos onde idCursos for igual a 9*/
/*delete from cursos where descricao = '' limit 2;*/ /*deleta de cursos onde a descrição é vazia, 
nos dois primeiros casos*/

/*truncate cursos;*/ /*apaga todos os dados da tabela*/
