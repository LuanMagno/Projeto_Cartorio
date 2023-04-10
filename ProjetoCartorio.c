#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registrar()//Respons�vel por registrar usu�rios no sistema
{
   //vari�veis 
   char arquivo[15];
   char cpf[15];
   char nome[70];
   char sobrenome[70];
   char cargo[40];

   printf("CPF:");
   scanf("%s", cpf);//%s para salvar string

   strcpy (arquivo, cpf); //strcpy serve para copiar as strings, do segundo para o primeiro (x=y) entao x copia o valor de y

   FILE *file;
   file = fopen(arquivo, "w");
   fprintf(file,cpf);
   fclose(file);

   file = fopen (arquivo, "a");
   fprintf(file, ",");
   fclose(file);

   printf("Nome:");
   scanf("%s", nome);

   file = fopen(arquivo, "a");
   fprintf(file, nome);
   fclose(file);

   file = fopen (arquivo, "a");
   fprintf(file, ",");
   fclose(file);

   printf("Sobrenome:");
   scanf("%s", sobrenome);

   file = fopen(arquivo, "a");
   fprintf(file, sobrenome);
   fclose(file);

   file = fopen (arquivo, "a");
   fprintf(file, ",");
   fclose(file);

   printf("Cargo:");
   scanf("%s", cargo);

   file = fopen (arquivo, "a");
   fprintf(file,cargo);
   fclose(file);

   file = fopen (arquivo, "a");
   fprintf (file,",");
   fclose(file);

   system("pause");

}
int consultar()//Consultar o usu�rio registrado anteriormente 
{
   char cpf[15];
   char conteudo[200];

   printf("Digite o CPF a ser consultado: ");
   scanf("%s", cpf);

   FILE *file;
   file= fopen(cpf, "r");
   
   if (file == NULL)
   {
      printf("Usu�rio n�o encontrado\n");
      
   }
   while (fgets(conteudo, 200, file) !=NULL)
   {
      printf("Estas s�o as informa��es do usu�rio:");
      printf("%s", conteudo);
      printf("\n\n");
   }
   system("pause");
}
int deletar()//Deletar usu�rio cadastrado 
{
   char cpf[15];
   printf("Digite o cpf do usu�rio a ser deletado:"); 
   scanf("%s", cpf);

   remove(cpf);
   FILE *file;
   file= fopen(cpf,"r");
   if(file==NULL)
   {
      printf("Usu�rio n�o encontrado \n");
      system("pause");
   }
   else
   {
      printf("Usu�rio deletado com sucesso\n"); 
      system("pause");  
   }
}



int main()
{
   setlocale(LC_ALL, "Portuguese");//definindo linguagem
   int opcao=0;
   int repet=1;
   for (repet=1;repet=1;)
   {
      
      printf("\t###Cart�rio da Ebac###\n\n");
      printf(" Opcao 1 - Registrar nomes\n");
      printf(" Opcao 2 - Pesquisar nomes\n");
      printf(" Opcao 3 - Deletar nomes\n");
      printf(" Opcao 4 - Sair do sistema\n\n");
      printf("Op��o:");
    
      scanf("%d", &opcao);//para ler a op��o utilizada

      switch (opcao)
      {
      case 1:
         registrar();           
      break;
      case 2:
         consultar();    
      break;
      case 3:
         deletar();    
      break;
      case 4:
        printf("Obrigado por usar o sistema!");
        return 0;
      break;
      default:
         printf("Escolha uma op��o v�lida\n");
         system("pause");
      break;
      }
      system("cls");
    }
   return 0;//N�o � essencial por�m � uma "boa pratica"
}
//- || significa "ou"
//- (O switch � melhor utilizado em vez de se precisa colocar v�rioss ifs, o case � para cada caso e o 
//- default � para caso nenhum desses ocorra, todos precisam do break; no final)
//- "system cls" serve para limpar a tela e "system pause" aguarda at� que seja pressionado outra tecla
//- 