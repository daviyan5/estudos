
void removeCliente(Banco *bancoIP){
    int enc=encontrarCliente(bancoIP); //função de busca para remover o cliente, no codigo completo alterei a função para que usasse dois parametros
    if(enc!=-1){
        printf("Cliente encontrado:\n\n");
        printf("Nome: %s\n\n",(bancoIP->clientes)[enc-1].nome); //demonstra os dados salvos, para confirmação
        printf("Senha: %s\n\n",(bancoIP->clientes)[enc-1].senha);
        printf("Saldo: %.2f\n\n",(bancoIP->clientes)[enc-1].saldo);
        printf("Deseja prosseguir?\n\n");
        printf("1.......Sim\n\n");
        printf("2.......Nao\n\n");
        int res;
        scanf("%d",&res);
        if (res==1){
            for (int i = enc-1; i < (bancoIP -> qtdCli) - 1; i++){ //copiando os dados na fila, de maneira que cada um dos clientes registrado após o que queremos apagar tenha sua posição diminuída
                (bancoIP -> clientes)[i] = (bancoIP -> clientes)[i+1];
            }
            (bancoIP -> qtdCli)--; 
            bancoIP -> clientes = (Cliente *) realloc(bancoIP -> clientes,(bancoIP -> qtdCli)*sizeof(Cliente)); //efetivamente diminuindo a memoria registrada, realocando com um tamanho menor
            printf("Cliente removido!\n\n");
        }
    }
    else printf("Cliente nao encontrado!");
}
