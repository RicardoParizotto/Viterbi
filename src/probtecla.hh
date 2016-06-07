/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Matriz de probabilidade das teclas do teclado                             *
 * --------------------------------------------------------------------------*/
#define _OK 0.9623
#define ER1 0.0250
#define ER2 0.0100
#define ER3 0.0020
#define ER4 0.0007

/************************************************************************** 
 * Matriz de probabilidade de teclar uma tecla tentando teclar outra.
 * ------------------------------------------------------------------------
 * - Para acessar o valor, acesse: probTecla[tecla][tecla_errada]. 
 * - Por exemplo, para saber a chance de se teclar 's' quando se quer 
 *   teclar 'a', acesse: probTecla[a][s].
 * - O inverso não é necessariamente igual.
 * - O vetor é indexado com inteiros, para acessar a letra facilmente, 
 *   utilize o método posMtr(char).
 * - Mais facilmente ainda, utilize a função que retorna um double 
 *   getProbTecla(char a, char b).
 **************************************************************************/
static const double probTecla[27][27] = {
//    a    b    c    d    e    f    g    h    i    j    k    l    m    n    o    p    q    r    s    t    u    v    w    x    y    z    ' '
    {_OK, ER4, ER4, ER3, ER3, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER1, ER4, ER4, ER4, ER2, ER3, ER4, ER1, ER4}, // a
    {ER4, _OK, ER4, ER4, ER4, ER4, ER1, ER1, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER4, ER4, ER4, ER1}, // b
    {ER4, ER4, _OK, ER1, ER4, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER1, ER4, ER4, ER1}, // c
    {ER4, ER4, ER1, _OK, ER1, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER2, ER1, ER4, ER4, ER4, ER3, ER1, ER4, ER4, ER4}, // d
    {ER4, ER4, ER4, ER1, _OK, ER2, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER3, ER1, ER2, ER3, ER4, ER4, ER1, ER4, ER4, ER4, ER4}, // e
    {ER4, ER3, ER1, ER1, ER2, _OK, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER2, ER4, ER1, ER4, ER3, ER4, ER4, ER4}, // f
    {ER4, ER1, ER3, ER4, ER4, ER1, _OK, ER1, ER4, ER4, ER4, ER4, ER4, ER3, ER4, ER4, ER4, ER3, ER4, ER1, ER4, ER1, ER4, ER4, ER2, ER4, ER4}, // g
    {ER4, ER1, ER4, ER4, ER4, ER4, ER1, _OK, ER2, ER1, ER4, ER4, ER3, ER1, ER4, ER4, ER4, ER4, ER4, ER2, ER4, ER2, ER4, ER4, ER1, ER4, ER4}, // h
    {ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, _OK, ER2, ER1, ER2, ER4, ER4, ER1, ER3, ER4, ER4, ER4, ER4, ER1, ER4, ER4, ER4, ER3, ER4, ER4}, // i
    {ER4, ER3, ER4, ER4, ER4, ER4, ER4, ER1, ER2, _OK, ER1, ER4, ER1, ER1, ER3, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER4, ER4, ER3, ER4, ER4}, // j
    {ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER1, _OK, ER1, ER1, ER4, ER2, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4}, // k
    {ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, _OK, ER4, ER4, ER1, ER2, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4}, // l
    {ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER3, ER4, ER1, ER1, ER3, _OK, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1}, // m
    {ER4, ER1, ER4, ER4, ER4, ER4, ER3, ER1, ER4, ER1, ER3, ER4, ER1, _OK, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1}, // n
    {ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER2, ER1, ER4, ER4, _OK, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4}, // o
    {ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER2, ER4, ER3, ER1, ER4, ER4, ER1, _OK, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4}, // p
    {ER1, ER4, ER4, ER4, ER3, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, _OK, ER4, ER2, ER4, ER4, ER4, ER1, ER4, ER4, ER4, ER4}, // q
    {ER4, ER4, ER4, ER2, ER1, ER1, ER2, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, _OK, ER4, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4}, // r
    {ER1, ER4, ER3, ER1, ER2, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER2, ER4, _OK, ER4, ER4, ER4, ER1, ER2, ER4, ER1, ER4}, // s
    {ER4, ER4, ER4, ER4, ER4, ER2, ER1, ER2, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER4, _OK, ER4, ER4, ER4, ER4, ER1, ER4, ER4}, // t
    {ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER2, ER1, ER1, ER3, ER4, ER4, ER4, ER2, ER4, ER4, ER4, ER4, ER4, _OK, ER4, ER4, ER4, ER1, ER4, ER4}, // u
    {ER4, ER1, ER1, ER2, ER4, ER1, ER1, ER2, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, _OK, ER4, ER4, ER4, ER4, ER4}, // v
    {ER1, ER4, ER4, ER2, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER3, ER1, ER4, ER4, ER4, _OK, ER4, ER4, ER4, ER4}, // w
    {ER2, ER4, ER1, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER4, ER4, ER4, _OK, ER4, ER1, ER4}, // x
    {ER4, ER4, ER4, ER4, ER4, ER4, ER2, ER1, ER3, ER2, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER1, ER4, ER4, ER4, _OK, ER4, ER4}, // y
    {ER1, ER4, ER2, ER3, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER4, ER4, ER4, ER1, ER4, _OK, ER4}, // z
    {ER4, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER1, ER4, ER4, ER4, ER4, ER4, ER4, ER4, ER1, ER4, ER4, ER4, ER4, _OK}  // ' '
};

// Converte char para um inteiro indexado de 0 à 26;
inline int posMtr(char c) {return (c-'a' >= 0) ? c-'a' : 26; }

/************************************************************************** 
 * Auxiliar para buscar o valor da probabilidade de uma letra
 * ------------------------------------------------------------------------
 * - Recebe duas letras
 * - Retorna a probabilidade de teclar a segunda letra, tentando teclar
 *   a primeira
 **************************************************************************/
inline double getProbTecla(char a, char b) {return probTecla[posMtr(a)][posMtr(b)];}
