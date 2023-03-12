public class MaterialTeste {
    public static void main(String[] args) {
        Material teste = new Material(1134 , "Loude", 3);
        teste.addMaterial(3);
        teste.retirarMaterial(6);
        teste.setNome("Djema");
        teste.imprimir();
        


        Material teste1 = new Material (347 , "Djemima");
        teste1.setNome("Mama"); 
        teste1.addMaterial(4);
        teste1.retirarMaterial(66);
        teste1.imprimir();

        

    }
    
}
