/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package smarthome;

import java.io.IOException;

/**
 *
 * @author rasika
 */
public class SmartHome {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
//        HomeBackEnd backEnd = new  HomeBackEnd("localhost",5002);
//        backEnd.sendCommand("hello");
//        backEnd.getState();
        GUI a = new GUI();
        a.display();
        //while(true);
    }
    
}
