import java.io.*;
import java.net.*;
public class Echoclient
{
 
	public static void main(String ar[]) throws UnknownHostException, IOException
	{
		Socket s=new Socket("127.0.0.1",1112);
		new communication (s);
	}
}

class communication implements Runnable
{
    Socket s;
    Thread t;
    boolean running=true;
   
    public communication (Socket s) throws IOException
	{   		
		t=new Thread(this);
		this.s=s;
	    t.start();
	}
	public void run() 
	{
		try {
		    BufferedReader   keyb = new BufferedReader(new InputStreamReader(System.in));
		    BufferedReader   in = new BufferedReader(new InputStreamReader(s.getInputStream()));
		    PrintWriter   out = new PrintWriter(new OutputStreamWriter(s.getOutputStream()));
		    while (running) 
		    {
		      System.out.println("Enter client Msg:");	
		      String clientCommand = keyb.readLine();
		     	      
		      if (clientCommand.equalsIgnoreCase("stop")) 
		       {
		    	         out.write(clientCommand+"\n");
		    	         out.flush();
		                 running = false;
		                 System.out.println("Connection Closed");
		                 s.close();
			    	  		       
		      } else 
		      {
		        out.write(clientCommand+"\n"); 
		        // we can use method out.println() :new line is imp without it wont work
		        out.flush();
		      }
		      if (clientCommand.equalsIgnoreCase("stop"))
		      {
		    	     running = false;
	                 
	          }
		      else
		      {
		    	   String servercmmmand=in.readLine();// read the input from socket
			       System.out.println("Echo msg:-"+servercmmmand);
		      }
		    }
		  } catch (Exception e) {
		    e.printStackTrace();
		  }
	}
	
}
