/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Interface;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.ResultSet;
import javax.swing.JOptionPane;
/**
 *
 * @author loude
 */


public class Veiculos {
    
    public String salvar(float preco , String ano, String modelo , String placa) throws SQLException{
        
           String sql = "INSERT INTO veiculos VALUES(?,?,?,?)";
           
           try{
                 PreparedStatement pstmt = Conexao.getConnection().prepareStatement(sql);
                pstmt.setObject(1, ano);
                pstmt.setObject(2, modelo);
                pstmt.setObject(3, placa);
                pstmt.setObject(4, preco);

                pstmt.execute();
                pstmt.close();
                Conexao.getConnection().close();
           }catch(SQLException e){
               throw new SQLException(e.getMessage());
           }
           return "Cadastro realizado com sucesso!";
    }
    
    
    
    private boolean buscarPorPlaca(String placa) throws SQLException{
        String sql = "SELECT  * FROM veiculos WHERE placa = ?";
        try{
              //System.out.println("Cebolinha");
            PreparedStatement pstmt = Conexao.getConnection().prepareStatement(sql);
            //System.out.println("Depois do statement");
            pstmt.setString(1, placa);
            
            // System.out.println("Antes");
            ResultSet result = pstmt.executeQuery();
          //  System.out.println("Depois");
            
            boolean placaFlag = false;
            if (result.next()) {
               placaFlag = true;
            }
                       
            pstmt.close();
           Conexao.getConnection().close();
           return placaFlag;
      }catch(SQLException e){
          return false;
      }
    }
    
    public String atualizar(float preco , String ano, String modelo , String placa) throws SQLException{
        
        
              boolean isExisted = this.buscarPorPlaca(placa);
              
              if (!isExisted){
                return "Veículo não encontrado!";
              }
              
            String sql = "UPDATE veiculos SET ano = ?, modelo = ?, preco = ? WHERE placa = ?";
           
           try{
                 PreparedStatement pstmt = Conexao.getConnection().prepareStatement(sql);
                pstmt.setObject (1, ano);
                pstmt.setObject(2, modelo);
                pstmt.setObject(3, preco);
                pstmt.setObject(4, placa);

                boolean result = pstmt.execute();
                pstmt.close();
                Conexao.getConnection().close();
                if (result) {
                    return "Atualização realizada com sucesso!";
                }
                
           
           }catch(SQLException e){
               throw new SQLException(e.getMessage());
           }
        return null;
    }
    
    public String remover(String placa ) throws SQLException{
                
              boolean isExisted = this.buscarPorPlaca(placa);
              
              if (!isExisted){
                return "Veículo não encontrado!";
              }
              
            String sql = "DELETE FROM veiculos WHERE placa = ?";
           
 
            try{
                 PreparedStatement pstmt = Conexao.getConnection().prepareStatement(sql);
                pstmt.setObject(1, placa);

                pstmt.execute();
                pstmt.close();
                Conexao.getConnection().close();
                return "Veiculo removido com sucesso!";
           }catch(SQLException e){
               throw new SQLException(e.getMessage());
           }
    }
  public String login(String usuario, String senha) throws SQLException{
        
  String sql = "usuarios FROM veiculos WHERE usuario, senha = ?";
  
  try{
       PreparedStatement pstmt = Conexao.getConnection().prepareStatement(sql);
       pstmt.setObject(1, usuario);
       pstmt.setObject(2, senha);
       
       pstmt.execute();
       pstmt.close();
       Conexao.getConnection().close();
  }catch(SQLException e){
      throw new SQLException(e.getMessage());
  }
  return "Bem-vindo!!";
}

    }


