public class GuessGame {
    Player p1;
    Player p2;
    Player p3;
    public void starGame(){
        p1 = new Player();
        p2 = new Player();
        p3 = new Player();

        int guessp1 = 0;
        int guessp2 = 0;
        int guessp3 = 0;

        boolean p1isRight = false;
        boolean p2isRight = false;
        boolean p3isRight = false;

        int targetNumber = (int) (Math.random() * 10);
        System.out.println("Estou pensando em um numero entre 0 e 9....");
        while(true){
            System.out.println(" o numero a adinhar é " +targetNumber);
            
            p1.guess();
            p2.guess();
            p3.guess();

            guessp1 = p1.number;
            System.out.println("O jogador um forneceu o palpite: " +guessp1);
            guessp2 = p2.number;
            System.out.println( " O jogador dois forneceu o palpite: " +guessp2);
            guessp3 = p3.number;
            System.out.println("o jogador três forneceu o palpite: " +guessp3);

            if (guessp1 == targetNumber){
                p1isRight = true;
            if (guessp2 == targetNumber){
                p2isRight = true;
            }
            if (guessp3 == targetNumber){
                p3isRight = true;
            if (p1isRight || p2isRight || p3isRight){
                System.out.println(" Temos um vendedor! ");
                System.out.println("O jogador um acertou? " +p1isRight);
                System.out.println("O jogador dois acertou? " +p2isRight);
                System.out.println(" O jogador três acertou? " +p3isRight);
                System.out.println("Fim de Jogo");
                break;
             } else {
                System.out.println("Os jogadores terão que tentar novamente.");

            }

            
            }

            }
        }


    }

}
