#ifdef __unix__
    #include "linux.h"
#elif defined(_WIN32) || defined(WIN32)
   #define OS_Windows
   #include "windows.h"
#endif

int main(int argc, char *argv[]){
    static char pasta [30];
    printf ("Digite o nome do Projecto: ");
    fflush(stdin);
    scanf("%s",pasta);
  #ifdef OS_Windows
    char raiz[]={"C:\\xampp\\htdocs\\"};
    strcat(raiz,pasta);
    fflush(stdin);
    (windows(raiz,pasta)==1)?printf("Projecto criado com Sucesso...\n"):printf("N�o teve exito na cria��o do Projecto...\n");
  #else
    char raiz[]={"/var/www/html"};
    strcat(raiz,pasta);
    (nix(raiz,pasta)==1)?printf("Projecto criado com Sucesso...\n"):printf("N�o teve exito na cria��o do Projecto...\n");
  #endif
  return 1;
}
