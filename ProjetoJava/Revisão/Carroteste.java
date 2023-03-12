public class Carroteste {
    //objecto

    public  static void main (String[] args){
        Carro c1 = new Carro();

        c1.nome ="Mada";
        c1.marca = "Fiat";
        c1.ano = 2019;
        c1.vel = 60;
       c1.acelerar(10);
       System.out.println(c1.vel);
       c1.freiar(33);
       System.out.println(20);
    }
}
