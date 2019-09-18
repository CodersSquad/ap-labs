int mystrlen(char *str);

char *mystradd(char *origin, char *addition);

int mystrfind(char *origin, char *substr);


int mystrlen(char *str){
    int n = 0;
    
    while(str[n] != '\0'){
        n++;
    }
   
    return n;
    
}

char *mystradd(char *origin, char *addition){

    int lenght = mystrlen(origin);
    
    int n;
    
    for(n = 0; addition[n] != '\0'; n++){
        origin[lenght + n] = addition[i];
    }
    
    
    origin[lenght + n] = '\0';
    
    return origin;
    
}

int mystrfind(char *origin, char *substr){
    
    int lenght = mystrlen(origin);
    
    int sublenght = mystrlen(substr);
    
    int m = 0;
    
    for(int n = 0; n <= lenght; n++){
        
        if(origin[n] == substr[0] && m < 1){
            m++;
        } else if(origin[n] == substr[m]){
            m++;
        } else {
            m = 0;
        }
        
        if(n >= sublenght){
            return 1;
        }
        
    }
    
    return 0;
}
