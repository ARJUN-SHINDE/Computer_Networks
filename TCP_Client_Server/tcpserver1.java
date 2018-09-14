//TCP Server side: Hello Client-Server - Interactive Input    M L Dhore  16/08/2013

import java.io.*;
import java.net.*;

public class tcpserver1
{
	public static void main(String args[]) throws IOException
	{
		ServerSocket ss = null;
		Socket socket =null;
			
		String message = null;
		
		ss = new ServerSocket(8001);
		System.out.println("Server socket is created and waiting for client");
		
		socket = ss.accept();
		
		DataOutputStream ostream = new DataOutputStream(socket.getOutputStream());
		DataInputStream istream = new DataInputStream(socket.getInputStream());
		
	//	if(socket.getTcpNoDelay()) socket.setTcpNoDelay(true);
	 // to disable Nagle's Algorithm

		message = istream.readUTF();

		System.out.println("Client Says: "+message);
			
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		// To read from console
		System.out.println("Enter Server Message:");
		message = br.readLine();

		ostream.writeUTF(message);

		System.out.println("Reply to Client:" +message);

		socket.close();
		ostream.close();
		istream.close();
	}
}


