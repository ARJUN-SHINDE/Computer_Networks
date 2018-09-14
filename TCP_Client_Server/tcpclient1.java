//TCP Clinet side: Hello Client-Server - Interactive Input    M L Dhore  16/08/2013

import java.io.*;
import java.net.*;

public class tcpclient1
{
	public static void main(String args[]) throws IOException
	{
		
		Socket cs = null;
			
		String message = null;
		
		cs = new Socket("192.168.60.255",8001);
		System.out.println("Client socket is created and waiting for server");
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		// To read from console
		System.out.println("Enter Client Message:");
		message = br.readLine();
		
		DataOutputStream ostream = new DataOutputStream(cs.getOutputStream());
		DataInputStream istream = new DataInputStream(cs.getInputStream());
		
		ostream.writeUTF(message);
		ostream.flush();

		//if(clientsocket.getSoTimeout()==0)clientsocket.setSoTimeout(1800); 
		// To set timeout, 0 means infinite time out

		message = istream.readUTF();
		
		System.out.println("Client Says: "+message);
		
		cs.close();
		ostream.close();
		istream.close();
	}
}
