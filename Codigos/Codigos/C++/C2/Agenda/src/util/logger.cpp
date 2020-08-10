#include "logger.h"

#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QFileInfo>
#include <iostream>

using namespace std;
/*! \file logger.cpp
  */

/// Singleton instance initialization
Logger* Logger::me = 0;

/*!
 * \brief Construtor da classe Logger.
 * \param parent
 */
Logger::Logger(QObject *parent) :  QObject(parent) {
    // cria um arquivo na pasta local do executável
    file = new QFile();
}

/*!
 * \brief Destrutor da classe Logger.
 */
Logger::~Logger() {
    delete file;
    me = 0;
}

/*!
 * \brief Cria uma instância da classe Logger, se a mesma não existir,
 * caso contrário retorna a instância já criada.
 * \return - Instância da classe Logger
 */
Logger* Logger::getInstance() {
    if (!me) me = new Logger();
    return me;
}

/*!
 * \brief Gera o nome de arquivo para o dia atual.
 * \return Nome do arquivo para o dia atual.
 */
QString Logger::getLogName () {
    int day = QDateTime::currentDateTime().date().day();
    if (day<10)
        return "logs0" + QString::number(day)+".txt";
    else
        return "logs" +  QString::number(day)+".txt";
}

/*!
 * \brief Remove o arquivo se houve mudança de mês.
 * \param fileName - nome do arquivo para verificar.
 */
void Logger::logsRemove (QString fileName) {
    QFileInfo   fileInfo;

    if (fileName=="") fileName = getLogName ();
    fileInfo.setFile(fileName);
    if (fileInfo.exists() && fileInfo.lastModified().date()!=QDate::currentDate())
        file->remove( fileName );
}

/*!
 * \brief Efetua o log da aplicação, gravando o mesmo em um arquivo
 * de log e apresentando na tela.
 * \param type - tipo da mensagem
 * \param msg - mensagem
 */
void Logger::doLog( QtMsgType type,  const QString msg) {

    // processa a mensagem de log para ser arquivada
    QString s = QDateTime::currentDateTime().toString( "dd/MM/yyyy hh:mm:ss.zzz" );

    switch (type) {
    case QtInfoMsg:     s += " [Info] ";       break;
    case QtDebugMsg:    s += " [Debug] ";       break;
    case QtWarningMsg:  s += " [Warning] ";     break;
    case QtCriticalMsg: s += " [Critical] ";    break;
    case QtFatalMsg:    s += " [Fatal] ";       abort();
    }
    s += msg;

    // arquiva a mensagem
    QString fileName = getLogName();

    logsRemove(  fileName  );

    file->setFileName( fileName );
    if (file->open(QIODevice::WriteOnly | QIODevice::Append)) {
       QTextStream out(&*file);
       out << s << endl;
       file->close();
    }

    cout <<  s.toLatin1().constData() << endl;
}

#if QT_VERSION >= 0x050000
/*!
  \brief Procedimento que direciona um log da aplica��o para o m�todo doLog da classe Logger.
  Vers�o Framework qt>=5
  \param type - tipo da mensagem: warning, debug ou critical
  \param QMessageLogContext - xx
  \param msg - mensagem a ser apresentata.
*/
    #include <QMessageLogContext>
    void logHandler (QtMsgType type, const QMessageLogContext &,
                  const QString &msg) {
         Logger::getInstance()->doLog(type, msg);
    }

    void InstalarLog() {
        qInstallMessageHandler(logHandler);
    }

#else
    /*!
      \brief Procedimento que direciona um log da aplica��o para o m�todo doLog da classe Logger.
      Vers�o Framework qt<5
      \param type - tipo da mensagem: warning, debug ou critical
      \param msg - mensagem a ser apresentata.
    */
    void logHandler(QtMsgType type, const char *msg) {
        Logger::getInstance()->doLog(type, msg);
    }

    void InstalarLog() {
        qInstallMsgHandler(logHandler);
    }
#endif
