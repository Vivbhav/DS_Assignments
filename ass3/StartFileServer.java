    import java.rmi.Naming;
     
    public class StartFileServer {
    	public static void main(String[] args) {
    		try{
    			
    			java.rmi.registry.LocateRegistry.createRegistry(1099);
    			
    			FileServer fs=new FileServer();
    			fs.setFile("itcrowd.avi");			
    			Naming.rebind("rmi://127.0.0.1/abc", fs);
    			System.out.println("File Server is Ready");
    			
    		}catch(Exception e){
    			e.printStackTrace();
    		}
    	}	
    }
     
