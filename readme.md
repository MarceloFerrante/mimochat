Encripta
	envia chave publica
	recebe chave publica
	usa chave publica
	
desencripta
	usa chave privada


trata email:	
	se tiver email pedindo chat
		responde com chave criptografica
			opcional: autoassinatura do email com chave criptografica 
			opcional: modo secreto, só responde se na lista de amigos
		aguarda email com ip:porta
	se tiver email com ip:porta
		apaga email
		checa lista de amigos:
			faz conexao p2p ou ignora

servidor (quem pediu conexao)
	envia email criptografado para cliente
		abre servidor com ip:porta
		envia email com ip:porta pedindo chat
	conexao p2p
		aguarda sinal no ip:porta
			gera chave criptografica
			envia chave publica pro cliente
		aguarda resposta do cliente
			decifra pacote do cliente
		se responde com chave publica:
			cifra mensagem de com chave publica do cliente
			envia mensagem ok pro cliente
			aguarda ok do cliente
		testa conexao
			ping
		
	fechando conexao
		envia sinal de fim
	

cliente (quem faz a conexao)
	Le email 
		na pasta mimochat:
		trata emails
		apaga emails
	conexão p2p
		gera chave criptografica
		envia sinal pro ip:porta
			aguarda chave criptografica publica do servidor
		se conexao responde com chave:
			cifra chave publica do cliente com a chave do servidor
			envia chave do cliente cifrada
			aguarda ok do servidor
		testa conexao
			responde ok pro servidor
			ping
		

