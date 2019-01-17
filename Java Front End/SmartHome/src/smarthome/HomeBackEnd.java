/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package smarthome;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;

/**
 *
 * @author rasika
 */
class HomeBackEnd {
    Socket socket ;
    OutputStream output ;
    InputStream input ;
    InputStreamReader reader;
    
    public HomeBackEnd(String host,int port) throws IOException{
        this.socket = new Socket(host, port);
        this.output = socket.getOutputStream();
        this.input = socket.getInputStream();
        this.reader = new InputStreamReader(input);
        
       
     
        //this.closeSocket();
        
    }
    
    public void sendCommand(String Command) throws IOException{
        
        byte[] data = Command.getBytes();
        this.output.write(data);
        //System.out.println("sent "+data.toString());
    }
    
    public void sendCommandAsByteArray(byte [] command) throws IOException{
        String cmd="";
        for(int i=0;i<command.length;i++){
            if(command[i]==0){
                cmd=cmd+'0';
            }else if(command[i]==1){
                cmd=cmd+'1';
            }else{
                cmd=cmd+"2";
            }
        }
        
        byte[] data = cmd.getBytes();
        this.output.write(data);
        System.out.println("sent as byte "+ new String(data));
    }
    
    public String getState() throws IOException{
        byte[] data = new byte[4];
        this.input.read(data);
        System.out.println("getState "+ new String(data));
        return new String(data);
    }
    
    public byte[] getStateByteArray() throws IOException{
        byte[] data = new byte[4];
        this.input.read(data);
        System.out.println("get as byte: "+ new String(data));
        String x= new String(data);
        for(int i =0;i<x.length();i++){
            if(x.charAt(i)=='0'){
                data[i]=0;
            }else{
                data[i]=1;
            }
        }
        return data;
    }
    
    public void getStatePrint() throws IOException{
        int character = this.reader.read();
        System.out.println("getStatePrint "+character);
    }
    
    public void closeSocket() throws IOException{
        this.socket.close();
    }
}
