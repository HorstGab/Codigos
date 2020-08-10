#ifndef LOGGER_H
#define LOGGER_H

/// Bibliotecas incluí­das
#include <QObject>
#include <QFile>
#include <QTextStream>

/*!
  \file logger.h
  \class Logger
  \brief Logger é uma classe que objetiva realizar todos os logs do sistema. Apresenta os logs na tela e
  em arquivos diários. A cada virada de dia, se o arquivo já existe, o mesmo é apagado, com o objetivo
  de manter os dados de somente um dia.
  \author Teresinha Arnauts Hachisuca
 */
class Logger : public QObject {
    Q_OBJECT

private:
    Logger( QObject *parent = 0);

    QString getLogName ();
    // xxx
    void logsRemove ( QString fileName );

    /// atributo que guarda a inst&acirc;ncia da classe
    static Logger* me;

    QFile *file;        //< Atributo do tipo arquivo
    QTextStream out;    //< Formato dos dados do arquivo

public:
    static Logger* getInstance( );
    ~Logger();
    void doLog(QtMsgType, const QString);
};

void InstalarLog();
#if QT_VERSION >= 0x050000
    #include <QMessageLogContext>
    void logHandler (QtMsgType type, const QMessageLogContext &, const QString &msg);
#else
    void logHandler(QtMsgType type, const char *msg);
#endif




#endif // LOGGER_H
