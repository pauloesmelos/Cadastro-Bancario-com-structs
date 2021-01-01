 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <locale.h>
 #include <string.h>
 #include <ctype.h>
 
 typedef struct{
 	char name[50];
 	int num;
 	float saldo;
 }cartao;
 
 int main(void){
 	
 	int OPC,OP;
 	int i=0,cont_reincidencia=0,cont=0,qn=0,j,c;
 	int num,num2,exc1=0,exc2=0;
 	float dep;
 	char excluir[]={'\0'},teste[4];
 	char nome[50],option[4];
 	
 	setlocale(LC_ALL,"");
 	cartao conta[50];
 	
 	do{
 		system("cls");
 		printf("=========SISTEMA DE CADASTRO DE CONTAS BANC�RIAS========\n");
 		printf("	1.Registrar uma conta banc�ria\n");
 		printf("	2.Consultar uma conta banc�ria\n");
 		printf("	3.Checar quantidade de contas abertas\n");
 		printf("	4.Excluir uma conta banc�ria\n");
 		printf("	5.Fazer um dep�sito banc�rio\n");
 		printf("	6.Fazer uma transfer�ncia banc�ria entre contas\n");
 		printf("	7.Sair do programa\n");
 		scanf("%d",&OPC);
 		
 			switch(OPC){
 				case 1:
 						cont=0;
						qn=i;
 						printf("OP��O ESCOLHIDA:%d <Cadastrar conta >\n",OPC);
 						fflush(stdin);
 						printf("===============================================\n");
 						printf("Digite o nome do benefici�rio: ");
 						gets(conta[i].name);
 						printf("Digite o c�digo do seu cart�o: ");
 						scanf("%d",&conta[i].num);
 							for(j=0;j<qn;++j){
 	
 								if(conta[i].num == conta[j].num){
 									cont++;
								 }
								 
							 }
						if(cont==0){
 						printf("Digite o saldo inicial da sua conta banc�ria: ");
 						scanf("%f",&conta[i].saldo);
 						printf("===============================================\n");					
 						++i;
 						}
 						else
 							printf("	ERRO ...\n H� uma conta registrada com esse dom�nio!\n");
 							
 						printf("(SISTEMA - CONTAS REGISTRADAS: %d contas )\n",i);
 						system("pause");				
				  break;
				  				  
				case 2:
						cont_reincidencia=0;
						printf("OP��O ESCOLHIDA:%d <Consultar conta>\n",OPC);
						fflush(stdin);
						printf("\n1. Consulta por n�mero da conta \n2. Consulta por nome de benefici�rio\n");
						scanf("%d",&OP);
					
						if(OP==1){
							printf("Digite o n�mero da conta do benefici�rio para realizarmos a busca: \n");
							scanf("%d",&num);
								for(j=0;j<=i;++j){
							
									if(conta[j].num == num){
										printf("NOME BENEFICI�RIO: %s\n",conta[j].name);
										printf("N�MERO DA CONTA  : %d\n",conta[j].num);
										printf("SALDO EM CAIXA   : $%.2f reais\n",conta[j].saldo);
										cont_reincidencia++;								
									}
							
								}
							if(cont_reincidencia == 0)
							printf("[N�o h� contas cadastradas com esse n�mero] !!!\n");
							
						}
					
						if(OP==2){
							fflush(stdin);
							printf("Digite o nome do benefici�rio: ");
							gets(nome);
						
							for(j=0;j<=i;++j){
								if(strcmp(nome,conta[j].name) == 0 ){
								printf("NOME BENEFICI�RIO: %s\n",conta[j].name);
								printf("N�MERO DA CONTA  : %d\n",conta[j].num);
								printf("SALDO EM CAIXA   : $%.2f reais\n",conta[j].saldo);
								cont_reincidencia++;			
								}
							}
							if(cont_reincidencia == 0){
							printf("[N�o h� contas cadastradas com esse nome !!!]\n");
							system("pause");
							}
						}
					
					system("pause");
				  break;
				
				case 3:
					printf("	Contas registradas na empresa: %d contas	\n",i);
					system("pause");
				break;
				
				case 4:
					cont = 0;
					cont_reincidencia = 0;
					printf("OP��O ESCOLHIDA:%d <EXCLUIR conta>\n",OPC);
					printf("Digite o n�mero da conta que deseja excluir: ");
					scanf("%d",&num);
					
						for(j=0;j<=qn;++j){
							
							if(conta[j].num == num ){
							fflush(stdin);
							printf("Deseja mesmo excluir a conta do usu�rio \nNome: %s\nN�mero: %d\nSaldo: %.2f$ ????\nTecle [sim] caso queira prosseguir: ",conta[j].name,conta[j].num,conta[j].saldo);	
							gets(option);
							strcpy(teste,"sim");
								if(strcmp(option,teste)==0){				
								strcpy(conta[j].name , excluir );
								conta[j].num = conta[-1].num;
								conta[j].saldo = conta[-1].saldo;	
								++cont;	
								--i; // usado na op��o pra ver qntd de contas abertas;		
										
								}
								else{
									printf("\nOp��o n�o reconhecida,tente novamente !\n");
									cont_reincidencia++;
								}
								
							}
						}
						
						if(cont==1)
							printf("\nA conta do usu�rio foi exclu�da !\n");
						if(cont==0 && cont_reincidencia == 0)
							printf("\n Erro #401, n�o foi localizada nenhuma conta com esse n�mero de identifica��o !\n");
							
				system("pause");
				break;
				case 5:
					cont = 0;
					
					printf("OP��O ESCOLHIDA: %d < FAZER UM DEP�SITO BANC�RIO >\n",OPC);
					printf("Digite o n�mero da conta que deseja depositar: ");
					scanf("%d",&num);
						for(j=0;j<=qn;++j){
							if(num == conta[j].num){
								++cont;
								printf("< Nome benefici�rio: %s    N�mero da conta: %d     Saldo atual: %.2f $reais > \n Informe a quantia a ser depositada em $ : ",conta[j].name,conta[j].num,conta[j].saldo);
								scanf("%f",&dep);
								conta[j].saldo += dep;
								printf("Dep�sito de %.2f $reais efetuado com sucesso .\n",dep);
							}
						}
						if(cont == 0 )
							printf("Lamentamos, nenhuma conta foi localizada.\n");
						
				system("pause");
				break;
				
				case 6:
					cont=0;
					printf("OP��O ESCOLHIDA: %d < TRANSFER�NCIA BANC�RIA >\n",OPC);
					printf("Entre com o n�mero da sua conta: ");
					scanf("%d",&num);
					for(j=0;j<=qn;++j){
						if(num == conta[j].num){
							cont++;
							printf("  DADOS DA SUA CONTA: \nNome: %s     N�mero da conta: %d      Saldo: %.2f$reais",conta[j].name,conta[j].num,conta[j].saldo);
							printf("\n\nDigite o n�mero da conta que deseja transferir o dinheiro: ");
							scanf("%d",&num2);
								for(c=0;c<=qn;++c){
									if(num2 == conta[c].num){
										cont_reincidencia++;	
										printf("\n\n  DADOS DA CONTA RECEBEDORA: \nNome: %s		N�mero da conta: %d		Saldo: %.2f$reais",conta[c].name,conta[c].num,conta[c].saldo);
										printf("\n *Entre com o valor a ser transferido ($) : ");
										scanf("%f",&dep);
										conta[j].saldo -= dep;
										conta[c].saldo += dep;
										printf("\nTransf�rencia realizada com sucesso!\n");
									}
								}
								if(cont_reincidencia == 0)
									printf("Conta RECEBEDORA n�o encontrada ... tente novamente \n");	
						}
					}
					if(cont == 0 )
						printf("Conta TRANSFERINTE n�o encontrada ... tente novamente\n");
					
				system("pause");
				break;
				case 7:
					
					printf("OP��O ESCOLHIDA:%d <Sair>\nFechando o programa ....\n",OPC);
					system("pause");
				break;
				
				default:
					printf("Op��o inexistente ... tente outra vez !\n");
					system("pause");
				break;
			}
			
	 }while(OPC!=7);
	 
 	
 }
