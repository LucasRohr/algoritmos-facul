#include <iostream>
#include "../atleta/atleta.h"
#include "../nadador/nadador.h"
#include "../corredor/corredor.h"

#ifndef INFORMACOES_ATLETA_H
#define INFORMACOES_ATLETA_H

class InformacoesAtleta {
    public:
        void imprime_exclusivos_atleta(Atleta* atleta);
        void imprime_informacoes_atleta(Atleta* atleta);
};

#endif
