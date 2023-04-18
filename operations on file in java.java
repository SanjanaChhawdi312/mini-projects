/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileWriter;
public class Main{
    private void createFile(){
        try{
            File f=new File("FileOperations.txt");
            if(f.createNewFile()){
                System.out.println(f.getName()+" created successfully");
            }
            else{
                System.out.println("File already exists");
            }
        }
        catch(IOException e){
            System.out.println("Unexpected error occured");
        }
    }
    private void getFileInfo(){
        File f=new File("FileOperations.txt");
            if(f.exists()){
                System.out.println("File information=>");
                System.out.println("File Name : "+f.getName());
                System.out.println("Absolute path : "+f.getAbsolutePath());
                System.out.println("Writable? : "+f.canWrite());
                System.out.println("Readable? : "+f.canRead());
                System.out.println("Size of file in bytes : "+f.length());
            }
            else{
                System.out.println("File does not exists");
            }
    }
    private void ReadFile(){
        try{
            File f=new File("FileOperations.txt");
            Scanner reader=new Scanner(f);
            while(reader.hasNextLine()){
                String content=reader.nextLine();
                System.out.println(content);
            }
        }
        catch(FileNotFoundException e){
            System.out.println("Error File not found");
        }
    }
    private void WriteFile(){
        try{
            FileWriter f=new FileWriter("FileOperations.txt");
            Scanner reader=new Scanner(System.in);
            System.out.println("Enter the information to enter in file =>");
            String content=reader.nextLine();
            f.write(content);
            f.close();
        }
        catch(IOException e){
            System.out.println("Error File not found");
        }
    }
    private void deleteFile(){
        File f=new File("FileOperations.txt");
        if(f.delete()){
            System.out.println(f.getName()+" deleted successfully");
        }
        else{
            System.out.println("Unexpected error occured");
        }
    }
    private void updateFile(){
        /*try{
            String oldContent="";
            FileWriter f1=new FileWriter("FileOperations.txt");
            File f=new File("FileOperations.txt");
            Scanner reader=new Scanner(f);
            Scanner input=new Scanner(System.in);
            System.out.println("Enter the word to update in file");
            String change=input.nextLine();
            while(reader.hasNextLine()){
                String data=reader.nextLine();
                oldContent=oldContent+data;
                if(data==change){
                    oldContent=oldContent+change;
                }
            }
            f1.write(oldContent);
            f1.close();
        }
        catch(IOException e){
            System.out.println("Error File not found");
        }*/

    }
	public static void main(String[] args) {
	    int choice,ch=1;
	    Main obj=new Main();
	    do{
	        System.out.println("Menu for operations in file=>");
    		System.out.println("1. Create a new file");
    		System.out.println("2. Get information from file");
    		System.out.println("3. Read from a file");
    		System.out.println("4. Write in a file");
    		System.out.println("5. Delete from file");
    		System.out.println("6. Update in file");
    		System.out.println("\tEnter your choice (1-6) : ");
    		Scanner in=new Scanner(System.in);
    		choice=in.nextInt();
    		switch(choice){
    		    case 1:
    		            obj.createFile();
    		            break;
    		    case 2:
    		            obj.getFileInfo();
    		            break;
    		    case 3:
    		            System.out.println("Displaying content of file=>");
    		            obj.ReadFile();
    		            break;
    		    case 4:
    		            obj.WriteFile();
    		            break;
    		    case 5:
    		            obj.deleteFile();
    		            break;
    		    case 6:
    		            obj.updateFile();
    		            break;
    		    default:
    		        System.out.println("Invalid choice!!");
    		}
    		System.out.println("Do you want to continue (1/0) :  ");
    		ch=in.nextInt();
	    }while(ch==1);
	}
}
