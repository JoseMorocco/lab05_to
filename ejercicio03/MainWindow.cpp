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
        "Brasil",
        "Argentina",
        "Chile",
        "Colombia",
        "México",
        "España",
        "Alemania",
        "Italia",
        "Reino Unido",
        "Canadá",
        "Japón",
        "China",
        "Corea del Sur",
        "Rusia",
        "Australia",
        "India",
        "Egipto"
    });

    ui->paisList->setCurrentRow(0);
    seleccionarPais(ui->paisList->currentItem());

    connect(ui->paisList, &QListWidget::itemClicked, this, &MainWindow::seleccionarPais);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::seleccionarPais(QListWidgetItem *item)
{
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
    else if (pais == "Argentina") {
        idioma = "Español";
        capital = "Buenos Aires";
    }
    else if (pais == "Chile") {
        idioma = "Español";
        capital = "Santiago";
    }
    else if (pais == "Colombia") {
        idioma = "Español";
        capital = "Bogotá";
    }
    else if (pais == "México") {
        idioma = "Español";
        capital = "Ciudad de México";
    }
    else if (pais == "España") {
        idioma = "Español";
        capital = "Madrid";
    }
    else if (pais == "Alemania") {
        idioma = "Alemán";
        capital = "Berlín";
    }
    else if (pais == "Italia") {
        idioma = "Italiano";
        capital = "Roma";
    }
    else if (pais == "Reino Unido") {
        idioma = "Inglés";
        capital = "Londres";
    }
    else if (pais == "Canadá") {
        idioma = "Inglés";
        capital = "Ottawa";
    }
    else if (pais == "Japón") {
        idioma = "Japonés";
        capital = "Tokio";
    }
    else if (pais == "China") {
        idioma = "Chino mandarín";
        capital = "Pekín";
    }
    else if (pais == "Corea del Sur") {
        idioma = "Coreano";
        capital = "Seúl";
    }
    else if (pais == "Rusia") {
        idioma = "Ruso";
        capital = "Moscú";
    }
    else if (pais == "Australia") {
        idioma = "Inglés";
        capital = "Canberra";
    }
    else if (pais == "India") {
        idioma = "Hindi";
        capital = "Nueva Delhi";
    }
    else if (pais == "Egipto") {
        idioma = "Árabe";
        capital = "El Cairo";
    }

    ui->idiomaText->setText(idioma);
    ui->capitalText->setText(capital);
}
