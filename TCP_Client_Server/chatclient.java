//TCP Client Side : Chat Client  M L Dhore  16/08/2013

import java.io.*;
import java.net.*;

public class chatclient
{
  public static void main(String args[]) throws IOException
  {
	Socket cs = null;
		
	String message = null;
		
	cs = new Socket("192.168.60.255",8002);
	System.out.println("Client socket is created and waiting for server");
	DataOutputStream ostream = new DataOutputStream(cs.getOutputStream());
	DataInputStream istream = new DataInputStream(cs.getInputStream());
		
	while(true)
	{
	 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	 // To read from console
	 System.out.println("Client Says:");
	 message = br.readLine();
	 ostream.writeUTF(message);
	 ostream.flush();
	 if(message.equals("end"))
	 {
			cs.close();
			ostream.close();
			istream.close();
			System.exit(0);
	 }
	 message = istream.readUTF();
	 System.out.println("Server Says:" +message);	
    }
		
	}
}
