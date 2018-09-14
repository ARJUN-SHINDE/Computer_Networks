import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;


public class Echoserver {
	
	public static void main(String[] args) throws IOException
	{
		 ServerSocket m_ServerSocket = new ServerSocket(1112);
		    int id = 0;
		    System.out.println("Waiting for Client Request");	
		    while (true)
		    {
		      
		      Socket clientSocket = m_ServerSocket.accept();
		      
		      ClientHandler cliThread = new  ClientHandler (clientSocket, id++);
		      cliThread.start();
		    }

	}

}

class ClientHandler extends Thread
{
	
	Socket client=null;
	int clientID = -1;
    boolean running = true;
    
	public ClientHandler(Socket client,int i) 
	{     
      this.client=client;
      clientID=i;  
	}

	public void run() 
	{
//System.out.println("Accepted Client : ID - " + clientID + " : Address - "+ client.getInetAddress().getHostName());	

try {
    BufferedReader   in = new BufferedReader(new InputStreamReader(client.getInputStream()));
    PrintWriter   out = new PrintWriter(new OutputStreamWriter(client.getOutputStream()));
    while (running) 
    {
    	
    	try{
    		String clientCommand=in.readLine();
    		System.out.println(clientCommand);
    		if (clientCommand.equals("null"))
    		{
    			System.out.print("Stopping client thread for client : " + clientID);
    			running=false;
    			break;
    		}
    		else
    		{
    			System.out.println("Address "+client.getInetAddress().getHostName()+" clientID "+clientID +" Client Says :" + clientCommand);    
                
    	        out.write(clientCommand+"\n");// redirect this message to a client Echo
    	                    // we can use method out.println() :new line is imp without it wont work
    	        out.flush();
    		}
    	}catch(Exception e)
    	{client.close();System.out.print("Stopping client thread for client : " + clientID);}
        
    	
        
      
    }
  } catch (Exception e) {
    e.printStackTrace();
  }
	}
}//class end


