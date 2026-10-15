#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->paisList->addItems({
        "Perú",
        "Estados Unidos",
        "Francia",
        "Brasil"
    });

    ui->paisList->setCurrentRow(0);
    seleccionarPais(ui->paisList->currentItem());

    connect(ui->paisList, &QListWidget::itemClicked, this, &MainWindow::seleccionarPais);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::seleccionarPais(QListWidgetItem *item) {
    QString pais = item->text();
    QString idioma{};
    QString capital{};

    if (pais == "Perú") {
        idioma = "Español";
        capital = "Lima";
    }
    else if (pais == "Estados Unidos") {
        idioma = "Inglés";
        capital = "Washington D. C.";
    }
    else if (pais == "Francia") {
        idioma = "Francés";
        capital = "París";
    }
    else if (pais == "Brasil") {
        idioma = "Portugués";
        capital = "Brasilia";
    }

    ui->idiomaText->setText(idioma);
    ui->capitalText->setText(capital);
}
