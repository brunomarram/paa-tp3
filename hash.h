#define tam 677

/*hash.h armazena a estrutura e os prototipos das funcaoes*/
struct dados
{
  int info;
  struct dados *prox;
};

typedef struct dados Dados;
typedef Dados* Hash[tam];

int funcaoHash(int num);/**/
void inicializaHash(Hash tab); /**/
void insereHash(Hash tab,int num);
int buscaHash(Hash tab, int num);
int imprimeColisao(Hash tab, int pos);
void imprimeHash(Hash tab);