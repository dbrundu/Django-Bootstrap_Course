/******************************************************************************

  Excercise on how to use interfaces in C#

*******************************************************************************/

using System;


namespace Program {
    
    public interface IUser {
      
      string ID {get; set;}
      
      int EnrollYear {get; set;}
      
      string Nominative {get;}
      
    }
  
  
    public class Person : IUser {
      
      public string ID {get; set;}
      
      public int EnrollYear {get; set;}
      
      public string Name {get; set;}
      
      public string Surname {get; set;}
      
      public string Nominative {
          
          get {
              return ID + " " + Name + " " + Surname;
          }
          
      }
      
    }
  
  
    public class Institution : IUser {
      
      public string ID {get; set;}
      
      public int EnrollYear {get; set;}
      
      public string SocialName {get; set;}
      
      public string Nominative {
          
          get {
              return ID + " " + SocialName ;
          }
          
      }
    
    }
      
      
    public class Library {
      
      public static void PrintAllUsers(IUser[] users){
          
          foreach(IUser u in users){
              Console.WriteLine( u.Nominative );
          }
      }
      
    }
    
    
    
    
    public class MainClass {
    
  
        static void Main() {
            
          Person mario = new Person();
          mario.Name = "Mario";
          mario.Surname = "Rossi";
          mario.ID = "0001";
          mario.EnrollYear = 2016;
        
          Institution infn = new Institution();
          infn.SocialName = "INFN";
          infn.ID = "0002";
          infn.EnrollYear = 2020;
          
          IUser[] users = new IUser[] {mario, infn};
          
          Library.PrintAllUsers( users );
          
            
        }
  
    }

    
}


