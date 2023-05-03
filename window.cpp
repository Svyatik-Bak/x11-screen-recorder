#include "window.h"
#include <QString>
#include <QProcess>
#include <cstdlib>
#include <iostream>
#include "./ui_window.h"

using namespace std;

window::window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::window)
{
    ui->setupUi(this);
    setFixedSize(this->geometry().width(),this->geometry().height());
}

window::~window()
{
    delete ui;
}


void window::on_pushButton_clicked()
{
    QString resolution = ui->resolution->text();
    QString framerate = ui->framerate->text();
    QString pulseaudio = ui->pulseaudio->text();
    QString codec = ui->codec->text();
    QString bitrate = ui->bitrate->text();
    QString monitor = ui->monitor->text();
    QString output = ui->output->text();
    QString acodec = ui->acodec->text();
    QString abitrate = ui->abitrate->text();
    QString resolution_2 = ui->resolution_2->text();
    QString arate = ui->arate->text();
    QTextStream output2(stdout);
    QString command = "ffmpeg -video_size res123 -framerate frames476 -f x11grab -i monitor321 -f pulse -ac 2 -i pulsedev123 -acodec auiocodek -vcodec videocoedc123 -crf bitsrate999 -b:a audiobitrate -ar arates -vf scale=scal123 vidneoouput &";
    command.replace("res123", resolution).replace("frames476", framerate).replace("monitor321", monitor).replace("pulsedev123", pulseaudio).replace("videocoedc123", codec).replace("bitsrate999", bitrate).
        replace("vidneoouput", output).replace("auiocodek", acodec).replace("audiobitrate", abitrate).replace("scal123", resolution_2).replace("arates", arate);
    std::string strcommand = command.toUtf8().constData();
    const char* charcommand = strcommand.c_str();
    std::system(charcommand);
}


void window::on_pushButton_2_clicked()
{
    std::system("killall ffmpeg");
}

