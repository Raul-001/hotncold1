#include <iostream>
#include <cstdlib>
#include <cmath>

void help(void) // tabela de ajuda //ok
{
    std::cout << "Bem-vindo ao jogo Hot-n-Cold\n";
    std::cout << "Teu objetivo é acertar o número em que pensei\n";
    std::cout << "O número deve ser um inteiro de 0 ao valor inserido\n";
    std::cout << "Caso o valor seja maior que o escolhido, digite outro valor\n";
    std::cout << "Caso o valor seja negativo, o programa se encerrará\n";
    std::cout << "Boa sorte!" << std::endl;
};
void fim(void) // ok // msg final
{
    std::cout << "Jogo encerrado! T_T\n";
}
void acerto(int num) // ok // msg de acerto
{
    std::cout << "Você acertou! Congratz;\n";
    std::cout << "O número era: " << num << std::endl;
}
void locutor(int max, int chute, int secret) // aponta se está hot or cold
{
    int prox = std:: ceil(max / 10);
    if (prox <= 0) prox++;
    //secret - prox <= chute <= secret + prox
    if(abs(chute - secret) <= abs( 2* prox )){
        std:: cout<< "Quente\n";
    }
    else{
        std:: cout << "Frio\n";
    }
    std ::cout << "Você errou, tente outra vez\n";
};

int randnum_secreto(int num) // gera o numero secreto // ok
{
    int palpite = rand() % num;
    return palpite;
};
// tornar o main enxuto
// entre randnum_secreto
// e exit -> tornar mais enxuto
int main(int argc, char *argv[])
{
    int teto{0};
    int jogador_palpite{0};
    int valor_secreto{0};
    if (argc > 2)
    {
        std::cout << ">>>> Argumentos em excesso. \n";
    }
    if (argc == 2)
    {
        teto = std::stoi(argv[1]);
        valor_secreto = randnum_secreto(teto);
        help();
        do
        {
            std ::cin >> jogador_palpite;
            locutor(teto, jogador_palpite, valor_secreto);
        } while ((jogador_palpite != valor_secreto) && jogador_palpite != -1);
        if (jogador_palpite == valor_secreto)
            acerto(valor_secreto);
        fim();
        exit(0);
    }
    if (argc < 2 && argc == 1)
    {
        teto = 45; // valor arbitrário
        randnum_secreto(teto);
        help();
        do
        {
            std ::cin >> jogador_palpite;
            locutor(teto, jogador_palpite, valor_secreto);
        } while (jogador_palpite != valor_secreto && jogador_palpite != -1);
        if (jogador_palpite == valor_secreto)
            acerto(valor_secreto);
        fim();
        exit(0);
    }
    return 0;
}