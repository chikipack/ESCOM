package tarea1;
import java.io.*;
import java.net.*;
import java.util.concurrent.Semaphore;

public class SerieGregniz{
    static double piCalculado;
    private static Semaphore semaforo = new Semaphore(1);
    
    static void read(DataInputStream f, byte[] b, int posicion, int longitud) throws Exception{
        while (longitud > 0){
            int n = f.read(b, posicion, longitud);
            posicion = posicion + n;
            longitud = longitud - n;
        }
    }

    static void parametroRecibido(String[] parametro) throws Exception{
        int valorAEvaluar = Integer.parseInt(parametro[0]);
        if(valorAEvaluar < 0 || valorAEvaluar > 4){
            System.out.println("Ingresa un valor valido: 0,1,2,3,4");    
        }else{
            switch(valorAEvaluar){
                case 0:
                System.out.println("Ingresaste el valor 0");
                cliente0();
                break;
                default:
                servidor(valorAEvaluar);
                break;
            }
        }
        return;
    }
    private static void servidor(int valorAEvaluar) throws Exception {
        System.out.println("Hola soy "+valorAEvaluar);
        switch(valorAEvaluar){
            case 1:
                ServerSocket server = new ServerSocket(50001);
                Socket conexion = server.accept();
                DataOutputStream enviar = new DataOutputStream(conexion.getOutputStream());
                DataInputStream recibir = new DataInputStream(conexion.getInputStream());
                byte[] buffer = new byte[34];
                read(recibir,buffer, 0, 34);
                System.out.println(new String(buffer,"UTF-8"));
                double primeraSumatoria=0.0;
                for(int i=0;i<999999;i++){
                    primeraSumatoria = primeraSumatoria + 4.0/((8.0*i)+1.0);
                    //System.out.println(primeraSumatoria);
                }
                enviar.writeDouble(primeraSumatoria);
            break;
            
            case 2:
                ServerSocket server2 = new ServerSocket(50002);
                Socket conexion2 = server2.accept();
                DataOutputStream enviar2 = new DataOutputStream(conexion2.getOutputStream());
                DataInputStream recibir2 = new DataInputStream(conexion2.getInputStream());
                byte[] buffer2 = new byte[34];
                read(recibir2,buffer2, 0, 34);
                System.out.println(new String(buffer2,"UTF-8"));
                double segundaSumatoria=0.0;
                for(int i=0;i<999999;i++){
                    segundaSumatoria = segundaSumatoria - 4.0/((8.0*i)+3.0);
                    // System.out.println(segundaSumatoria);
                }
                enviar2.writeDouble(segundaSumatoria);
            break;

            case 3:
                ServerSocket server3 = new ServerSocket(50003);
                Socket conexion3 = server3.accept();
                DataOutputStream enviar3 = new DataOutputStream(conexion3.getOutputStream());
                DataInputStream recibir3 = new DataInputStream(conexion3.getInputStream());
                byte[] buffer3 = new byte[34];
                read(recibir3,buffer3, 0, 34);
                System.out.println(new String(buffer3,"UTF-8"));
                double tercerSumatoria=0.0;
                for(int i=0;i<999999;i++){
                    tercerSumatoria = tercerSumatoria + 4.0/((8.0*i)+5.0);
                    //System.out.println(tercerSumatoria);
                }
                enviar3.writeDouble(tercerSumatoria);
            break;

            case 4:
            ServerSocket server4 = new ServerSocket(50004);
            Socket conexion4 = server4.accept();
            DataOutputStream enviar4 = new DataOutputStream(conexion4.getOutputStream());
            DataInputStream recibir4 = new DataInputStream(conexion4.getInputStream());
            byte[] buffer4 = new byte[34];
            read(recibir4,buffer4, 0, 34);
            System.out.println(new String(buffer4,"UTF-8"));
            double cuartaSumatoria=0.0;
                for(int i=0;i<999999;i++){
                    cuartaSumatoria = cuartaSumatoria - 4.0/((8.0*i)+7.0);
                    //System.out.println(cuartaSumatoria);
                }
                enviar4.writeDouble(cuartaSumatoria);
            break;

        }
        
        
        
        
    }

    //Funcion para el cliente 
    static class Worker extends Thread{
        int nodo;
        Worker(int nodo){
            this.nodo = nodo;
        }
        public void run(){
            System.out.println("Hola soy el hilo "+nodo);
            switch(nodo){
                case 1:
                    Socket conexion = null;
                    while(true){
                        try{
                            conexion = new Socket("127.0.0.1", 50001);
                            break;
                        }catch(Exception e){
                            System.out.println("No se pudo establecer la conexcion con el servidor 1, intentando nuevamente");
                        }
                    }
                    //aqui va el codigo una vez que se conecto el cliente con el servidor
                    try{
                        DataOutputStream salida = new DataOutputStream(conexion.getOutputStream());
                        DataInputStream entrada = new DataInputStream(conexion.getInputStream());
                        salida.write("Hola Soy Cliente conectandome a S1".getBytes());
                        semaforo.acquire();
                        piCalculado = piCalculado + entrada.readDouble();
                        semaforo.release();
                        Thread.sleep(1000);
                        conexion.close();
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                break;
                case 2:
                    Socket conexion2 = null;
                    while(true){
                        try{
                            conexion2 = new Socket("127.0.0.1", 50002);
                            break;
                        }catch(Exception e){
                            System.out.println("No se pudo establecer la conexcion con el servidor 2, intentando nuevamente");
                        }
                    }
                    //aqui va el codigo una vez que se conecto el cliente con el servidor
                    try{
                        DataOutputStream salida = new DataOutputStream(conexion2.getOutputStream());
                        DataInputStream entrada = new DataInputStream(conexion2.getInputStream());
                        salida.write("Hola Soy Cliente conectandome a S2".getBytes());
                        semaforo.acquire();
                        piCalculado = piCalculado + entrada.readDouble();
                        semaforo.release();
                        Thread.sleep(1000);
                        conexion2.close();
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                break;
                case 3:
                    Socket conexion3 = null;
                    while(true){
                        try{
                            conexion3 = new Socket("127.0.0.1", 50003);
                            break;
                        }catch(Exception e){
                            System.out.println("No se pudo establecer la conexcion con el servidor 3, intentando nuevamente");
                        }
                    }
                    //aqui va el codigo una vez que se conecto el cliente con el servidor
                    try{
                        DataOutputStream salida = new DataOutputStream(conexion3.getOutputStream());
                        DataInputStream entrada = new DataInputStream(conexion3.getInputStream());
                        salida.write("Hola Soy Cliente conectandome a S3".getBytes());
                        semaforo.acquire();
                        piCalculado = piCalculado + entrada.readDouble();
                        semaforo.release();
                        Thread.sleep(1000);
                        conexion3.close();
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                break;
                case 4:
                    Socket conexion4 = null;
                    while(true){
                        try{
                            conexion4 = new Socket("127.0.0.1", 50004);
                            break;
                        }catch(Exception e){
                            System.out.println("No se pudo establecer la conexcion con el servidor 4, intentando nuevamente");
                        }
                    }
                    //aqui va el codigo una vez que se conecto el cliente con el servidor
                    try{
                        DataOutputStream salida = new DataOutputStream(conexion4.getOutputStream());
                        DataInputStream entrada = new DataInputStream(conexion4.getInputStream());
                        salida.write("Hola Soy Cliente conectandome a S4".getBytes());
                        semaforo.acquire();
                        piCalculado = piCalculado + entrada.readDouble();
                        semaforo.release();
                        Thread.sleep(1000);
                        conexion4.close();
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                break;
            }
        }
    }

    static void cliente0() throws InterruptedException{
        Worker cliente_Serv1 = new Worker(1);
        Worker cliente_Serv2 = new Worker(2);
        Worker cliente_Serv3 = new Worker(3);
        Worker cliente_Serv4 = new Worker(4);
        cliente_Serv1.start();
        cliente_Serv2.start();
        cliente_Serv3.start();
        cliente_Serv4.start();

        cliente_Serv1.join();
        cliente_Serv2.join();
        cliente_Serv3.join();
        cliente_Serv4.join();
        System.out.println("el valor de pi calculado es: "+piCalculado);
    }

    public static void main(String[] args) throws Exception{
        if (args.length > 0){
            parametroRecibido(args);
        }else{
            System.out.println("ingresa un nodo como argumento");
            System.out.println("ej. java SerieGregniz 0");
        }
    }

    
}