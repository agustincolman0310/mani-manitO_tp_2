
#include "parser.h"
#include "camion.h"
#include "auto.h"
#include "camioneta.h"
#include "poema.h"
#include "novela.h"
#include "cuento.h"
#include "constantes.h"

using namespace std;

Parser::Parser(char** argv) {
    this->entrada = argv;
}

Lectura* Parser::procesarEntrada() const {
    Lectura* lectura = NULL;
    if(this->obtener_tipo_lectura() == "N") {
        lectura = new novela();
    }
    else if (this->tipoVehiculo() == AUTO) {
        vehiculo = new Auto(this->cilindrada(), this->kilometraje(), this->combustible());
    }
    else if (this->tipoVehiculo() == CAMIONETA) {
        vehiculo = new Camioneta(this->cilindrada(), this->kilometraje(), this->combustible());
    }
    return vehiculo;
}

std::string Parser::obtener_tipo_lectura() const {
    return this->entrada[posicion::TIPO_VEHICULO];
}

float Parser::cilindrada() const {
    return stof(this->entrada[posicion::CILINDRADA]);
}

float Parser::kilometraje() const {
    return stof(this->entrada[posicion::KILOMETRAJE]);
}

float Parser::combustible() const {
    return stof(this->entrada[posicion::COMBUSTIBLE]);
}


