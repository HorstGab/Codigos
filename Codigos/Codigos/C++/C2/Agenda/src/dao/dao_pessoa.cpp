#include "dao_aluno.h"

struct sAluno {
    int id;
    char nome[100];
    bool ativo;
};

Dao_Aluno::Dao_Aluno(QObject *parent) :
    Dao("autoincrement_aluno.dat", parent) {
    this->fileName = "aluno.dat";
}

fpos_t Dao_Aluno::findId ( int id ) {
    sAluno      aluno;

    fopen_s( &f, fileName.toLatin1().constData(), "rb" );
    fpos_t pos=-1;
    if (f) {
        fseek(f, 0, SEEK_SET );
        while (!feof(f) && pos==-1) {
            fread (&aluno, sizeof(sAluno),1,f);
            if ((aluno.ativo) && (aluno.id==id)) {
                fgetpos ( f, &pos);
                pos -= sizeof(sAluno);
            }
        }
        fclose ( f );
    }
    return pos;
}

QVector<Model_Aluno *> *Dao_Aluno::search(QString name ) {

    QVector<Model_Aluno*>* objs=new QVector<Model_Aluno*>();

    Model_Aluno *obj;
    sAluno      aluno;
    QString     s;

    f = fopen ( fileName.toLatin1().constData(), "rb" );
    if (f) {        
        fseek(f, 0, SEEK_SET );
        while (!feof(f)) {
            fread (&aluno, sizeof(sAluno),1,f);
            s = aluno.nome;
            if (!feof(f) && (aluno.ativo) &&
                    ((s.contains(name, Qt::CaseInsensitive)) || (name==""))) {
                obj = new Model_Aluno( );
                obj->setId(aluno.id);
                obj->setName(aluno.nome);
                objs->append(obj);
            }
        }
        fclose ( f );
    }
    return objs;
}

void Dao_Aluno::insert ( Model_Aluno *obj ) {

    f = fopen ( fileName.toLatin1().constData(), "a+" );
    if (f) {
        sAluno aluno;
        aluno.id = updateIndex();
        strcpy_s ( aluno.nome, obj->getName().toLatin1().constData() );
        aluno.ativo = true;

        fwrite( &aluno, sizeof(sAluno), 1, f );

        fclose ( f );

        obj->setId( aluno.id );
        notify( action_insert, obj );
    }
}

void Dao_Aluno::update ( Model_Aluno *obj ) {

    fpos_t pos = findId( obj->getId() );

    f = fopen ( fileName.toLatin1().constData(), "r+" );
    if (f) {
        fseek ( f, pos, SEEK_SET );

        sAluno aluno;
        aluno.id = obj->getId();
        strcpy_s ( aluno.nome, obj->getName().toLatin1().constData() );
        aluno.ativo = true;

        fwrite( &aluno, sizeof(sAluno), 1, f );

        fclose ( f );
        notify( action_update, obj );
    }
}

void Dao_Aluno::save ( Model_Aluno *obj ) {
    if (obj->getId()==-1)
        this->insert(obj);
    else
        this->update(obj);
}

void Dao_Aluno::remove ( Model_Aluno *obj ) {
    fpos_t pos = findId( obj->getId() );
    if (pos!=-1) {
        f = fopen (fileName.toLatin1().constData(), "r+" );
        if (f) {
            fseek ( f, pos, SEEK_SET );
            sAluno aluno;
            aluno.id = obj->getId();
            strcpy_s ( aluno.nome, obj->getName().toLatin1().constData() );
            aluno.ativo = false;
            fwrite( &aluno, sizeof(sAluno), 1, f );

            fclose(f);
            emit notify ( action_remove, obj );
        }
    }
}
