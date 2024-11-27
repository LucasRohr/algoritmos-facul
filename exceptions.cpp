/**
 * Tratamento de excessões em C++
 * 
 * Lucas Rohr Carreño
 * Pietro do Couto Freitas
 * Tomás Strieder
 */

#include <iostream>

using namespace std;

#define SIZE 5

int fill_array_old_way(int* array, int fill_until_position);
void fill_array(int* array, int fill_until_position);

// Prototipação de funções de tratamento de exceção padrão da linguagem
void terminate_exception_handler();
void new_exception_handler();

int main() {
    set_new_handler(new_exception_handler);
    set_terminate(terminate_exception_handler);

    int array[SIZE];

    /**
     * Lidando com erros usando IF statements
     */
    int result = fill_array_old_way(array, SIZE);
    
    if (result != 0) cout << "[fill_array_old_way] tentativa de preencher o array em posição inválida (" << result << ")" << endl;

    /**
     * Lidando com erros usando trycatch
     */
    try {
        // Força a emissão de um erro ao tentar setar uma posição fora dos limites do array
        fill_array(array, SIZE);
    } catch(int  i) {
        // Tratamento do erro emitido pela função fill_array
        cout << "[fill_array] tentativa de preencher o array em posição inválida (" << i << ")" << endl;
    }

    /**
     * Lidando com handlers de erro padrão da linguagem (bad_alloc)
     * Força o estouro de memória, que por sua vez, para fins didáticos, emitirá uma exceção terminal ao compilar
     */
    while (true) {
        new int[999999999999999999];
    }

    return 0;
}

/**
 * Handler personalizado para tentativa de alocação de memória esgotada
 */
void new_exception_handler() {
    cout << "oops, memória esgotada" << endl;

    /**
     * Lidando com handlers de erro padrão da linguagem (terminate)
     * emite um erro não tratado por nenhum catch, forçando o terminate a capturar o erro
     */
    throw(-1);
}

/**
 * Handler personalizado para excessões terminais
 */
void terminate_exception_handler() {
    cout << "oops, exceção terminal" << endl;
}

/**
 * Função para preencher um array com valores crescentes no intervalo de 0 a fill_until_position - 1
 * @param array um ponteiro para o elemento inicial do array
 * @param fill_until_position a posição até a qual deve ser preenchida
 * @throws um erro ao tentar acessar uma posição inválida no array
 */
void fill_array(int* array, int fill_until_position) {
    if(fill_until_position >= SIZE) throw(fill_until_position);

    for(int i = 0; i < fill_until_position; i++) {;
        array[i] = i;
    }
}

/**
 * Função para preencher um array com valores crescentes no intervalo de 0 a fill_until_position - 1
 * @param array um ponteiro para o elemento inicial do array
 * @param fill_until_position a posição até a qual deve ser preenchida
 * @returns posição inválida caso tente acessar ela no array
 * @returns 0 em caso de sucesso
 */
int fill_array_old_way(int* array, int fill_until_position) {
    if(fill_until_position >= SIZE) return fill_until_position;

    for(int i = 0; i < fill_until_position; i++) {;
        array[i] = i;
    }

    return 0;
}