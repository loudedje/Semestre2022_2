public class Testeconta {
    public static void main(String[] args) 
    {
        Cliente cliente1 = new Cliente("Djemima", "24354441");

        System.out.println("------Conta Especial-------------------");
        ContaEspecial contaespecial = new ContaEspecial(111, "Loude", 222, 44);
        contaespecial.depositar(223);
        contaespecial.sacar(33.43);
        contaespecial.resumoExtrato();
        System.out.println("-----------");
        contaespecial.fazManutencao();
        System.out.println("-----------");
        contaespecial.extrato();

        cliente1.conta = contaespecial;
        System.out.println("----------INVESTIMENTO-----------------------");
        Investimento Investi = new Investimento(22, "Loude", 22);
        Investi.fazManutencao();
        Investi.resumoExtrato();
        Investi.extrato();

        cliente1.conta = Investi;

        CarteiraPrime cartP = new CarteiraPrime();
        cartP.addClientes(cliente1);

        System.out.println("****************************************");
        //Cliente cliente2 = new Cliente("Loude", "3474839");//
    }    
}

        
       