void trocaletra(char dado[]){

	int i;

	for (i = 0; i < strlen(dado); i++){

		if(dado[i] == 'a'){
			dado[i] = 'b';
		}
	}

	printf("\nFrase com letras trocadas -> ");
	puts(dado);
}
