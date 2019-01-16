/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package smarthome;

import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;

/**
 *
 * @author rasika
 */
class HomeBackEnd {
    Socket socket ;
    OutputStream output ;
    public HomeBackEnd(String host,int port) throws IOException{
        this.socket = new Socket(host, port);
        this.output = socket.getOutputStream();
        byte[] data = "hello".getBytes();
        this.output.write(data);
    }
}
