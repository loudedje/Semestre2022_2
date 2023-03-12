public class numP {

    public static void main(String [] args){
        
        for( int i = 100; i<= 200; i++){
            boolean   vec = true;

            if(i % 2 == 0 && i != 2){
                vec = false;
            }
            if(vec == true){
                for(int z = 3; z <= (i/2); z++){
                    if( i % z == 0){
                        vec = false;
                        break;
                    }
                }
            }
            if(vec == true){
                System.out.println(i);
            }

        }
       
    } 
}
