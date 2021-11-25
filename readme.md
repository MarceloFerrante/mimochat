#Encripta

	envia chave publica
	recebe chave publica
	usa chave publica
	
#Desencripta

	usa chave privada


#Trata usuario:

	se tiver usuario pedindo chat
		responde com chave criptografica
			opcional: autoassinatura do usuario com chave criptografica 
			opcional: modo secreto, só responde se na lista de amigos
		aguarda usuario com servidor:porta
		
	se tiver usuario com servidor:porta
		apaga usuario
		checa lista de amigos:
			faz conexao p2p ou ignora

#Servidor (quem pede conexao)

	envia usuario criptografado para cliente
		abre servidor com servidor:porta
		envia usuario com servidor:porta pedindo chat
		
	conexao p2p
		aguarda sinal no servidor:porta
			gera chave criptografica
			envia chave publica pro cliente
		aguarda resposta do cliente
			decifra pacote do cliente
		se responde com chave publica:
			cifra texto de com chave publica do cliente
			envia texto ok pro cliente
			aguarda ok do cliente
		testa conexao
			ping
		
	fecha conexao
		envia sinal de fim
        encerra servidor
	

#Cliente (quem faz a conexao)

	Le usuario 
		na pasta encripta:
		trata emails
		apaga emails
		
	conexão p2p
		gera chave criptografica
		envia sinal pro servidor:porta
			aguarda chave criptografica publica do servidor
		se conexao responde com chave:
			cifra chave publica do cliente com a chave do servidor
			envia chave do cliente cifrada
			aguarda ok do servidor
		testa conexao
			responde ok pro servidor
			ping

	fecha conexao
		envia sinal de fim
        fecha cliente

#Threads
    Usar theads pra testar conexões com clientes em paralelo