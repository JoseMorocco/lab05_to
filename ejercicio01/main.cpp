#include <QCoreApplication>
#include <QDebug>

#include <vector>
#include <algorithm>
#include <random>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    std::vector<int> numeros;

    // Generar 20 numeros aleatorios entre 1 y 50
    std::random_device rd;
    std::mt19937 generador(rd());
    std::uniform_int_distribution<int> distribucion(1, 50);

    for (int i = 0; i < 20; i++) {
        numeros.push_back(distribucion(generador));
    }

    qDebug() << "Numeros generados:";

    for (int numero : numeros) {
        qDebug().noquote().nospace() << numero;
    }

    // Contar impares menores de 20 mediante lambda
    int cantidad = std::count_if(
        numeros.begin(),
        numeros.end(),
        [](int numero) {
            return numero % 2 != 0 && numero < 20;
        }
    );

    qDebug() << "Cantidad de impares menores de 20:"
             << cantidad;

    return 0;
}
