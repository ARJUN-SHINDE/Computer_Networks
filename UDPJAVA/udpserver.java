// UDP Serverside Program : Hello Client Server M L dhore 16/08/2013

import java.io.*;
import java.net.*;

public class udpserver
{
 public static void main(String args[]) throws IOException 
 {
    DatagramSocket ss = null; 
    //ServerSocket serversocket = null; Socket socket =null;
			
	ss = new DatagramSocket(9000); 
	//serversocket = new ServerSocket(8000);
		  
	byte[] receiveData = new byte[512];  
	//DataInputStream istream = new DataInputStream(socket.getInputStream());
	byte[] sendData  = new byte[512]; 
	//DataOutputStream ostream = new DataOutputStream(socket.getOutputStream());
		  
	System.out.println(" UDP Server socket is created and waiting for client");
		
	while(true) 
	 { 
  	   DatagramPacket receivePacket =new DatagramPacket(receiveData, receiveData.length); 
  
	   ss.receive(receivePacket); 
  
	   String message = new String(receivePacket.getData()); 
	   //myoperation = istream.readUTF();

	   System.out.println("Client Says: "+message);
		
	   InetAddress IPAddress = receivePacket.getAddress(); 
  
	   int port = receivePacket.getPort(); 
		  
	   message = "Thanks";
  
	   sendData = message.getBytes(); 
  
	   DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress,port); 
  
	   ss.send(sendPacket); //ostream.writeUTF(myoperation);
		  	 	
	   if(message.equals("Thanks")) break;
	  } 	
	 ss.close();
	 System.out.println("Server Stopped by User program");
  }
}



  
	 
  
		  
		