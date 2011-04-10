#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QProcess>

class ApiTrace;
class ApiTraceEvent;
class ApiTraceFilter;
class ApiTraceFrame;
class ApiTraceModel;
class ImageViewer;
class QLineEdit;
class QModelIndex;
class QProgressBar;
class QUrl;
class Retracer;
class ShadersSourceWidget;
class VertexDataInterpreter;

namespace QJson {
    class Parser;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

public slots:
    void loadTrace(const QString &fileName);

private slots:
    void callItemSelected(const QModelIndex &index);
    void openTrace();
    void filterTrace();
    void replayStart();
    void replayStop();
    void replayFinished(const QByteArray &output);
    void replayError(const QString &msg);
    void startedLoadingTrace();
    void finishedLoadingTrace();
    void lookupState();
    void showSettings();
    void openHelp(const QUrl &url);
    void showSurfacesMenu(const QPoint &pos);
    void showSelectedSurface();

private:
    void initObjects();
    void initConnections();
    void newTraceFile(const QString &fileName);
    void replayTrace(bool dumpState);
    void parseState(const QVariantMap &params);
    void fillStateForFrame();

private:
    Ui_MainWindow m_ui;
    ShadersSourceWidget *m_sourcesWidget;

    ApiTrace *m_trace;
    ApiTraceModel *m_model;
    ApiTraceFilter *m_proxyModel;
    QLineEdit *m_filterEdit;

    QProgressBar *m_progressBar;

    QString m_traceFileName;

    ApiTraceEvent *m_selectedEvent;

    ApiTraceEvent *m_stateEvent;

    QJson::Parser *m_jsonParser;

    Retracer *m_retracer;

    VertexDataInterpreter *m_vdataInterpreter;

    ImageViewer *m_imageViewer;
};


#endif