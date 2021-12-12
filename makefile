proje: myshell islem topla cikar tekrar

myshell: myshell.c
	gcc myshell.c -o myshell
	
islem: islem.c
	gcc islem.c -o islem
	
topla:
	gcc topla.c -o topla
		
tekrar: topla.c
	gcc tekrar.c -o tekrar


cikar: cikar.c
	gcc cikar.c -o cikar

clear: 
	rm -rf *o temizle
