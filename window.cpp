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
    QTextStream output2(stdout);
    QString command = "ffmpeg -video_size res123 -framerate frames476 -f x11grab -i monitor321 -f pulse -ac 2 -i pulsedev123 -acodec aac -vcodec videocoedc123 -vb bitsrate999 vidneoouput &";
    command.replace("res123", resolution).replace("frames476", framerate).replace("monitor321", monitor).replace("pulsedev123", pulseaudio).replace("videocoedc123", codec).replace("bitsrate999", bitrate).
        replace("vidneoouput", output);
    std::string strcommand = command.toUtf8().constData();
    const char* charcommand = strcommand.c_str();
    std::system(charcommand);
}


void window::on_pushButton_2_clicked()
{
    std::system("killall ffmpeg");
}

