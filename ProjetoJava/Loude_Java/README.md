# Trabalho-Java
# Trabalho-Java
# Trabalho-Java
jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                String usuario = jFormattedTextField1.getText();
                String senha = jPasswordField1.getText();
                try {
                    Connection connection = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/DJauto",
                        "root", "");

                    PreparedStatement start = (PreparedStatement) connection
                        .prepareStatement("Select usuario, senha from usuarios where usuario=? and senha=?");

                    start.setString(1, usuario);
                    start.setString(2, senha);
                    ResultSet result = start.executeQuery();
                    if (result.next()) {
                       TelaDEComprar tela = new TelaDEComprar();
                       tela.setVisible(true);
                    } else {
                        JOptionPane.showInputDialog(this, "Invalido senha e ou usuario ! ");
                    }
                } catch (SQLException sqlException) {
                    sqlException.printStackTrace();
                }
            }
        });
