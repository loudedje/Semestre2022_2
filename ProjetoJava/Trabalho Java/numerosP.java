public class numerosP {
 
        public static void main(String [] args){
            
            for( int i = 2; i<= 48; i++){
                boolean numero = true;
    
                if(i % 2 == 0 && i != 2){
                    numero= false;
                }
                if(numero == true){
                    for(int x = 3; x <= (i/2); x++){
                        if( i % x == 0){
                            numero = false;
                            break;
                        }
                    }
                }
                if(numero == true){
                    System.out.println(+i);
                }
    
            }
           
        }    
            
    }
    
    

