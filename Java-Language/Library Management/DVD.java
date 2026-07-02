/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.librarymanagement;

/**
 *
 * @author CSE Lab
 */

     public class DVD extends LibraryItem implements Brrowable {
    
    private int Duration;

    public DVD( String itemid, String title, String author, int Duration) {
        super(itemid, title, author);
        this.Duration = Duration;
    }
   
    
    @Override
    public void BrrowItem(){
    System.out.println("Item is borrowed");
    
    }
    @Override
    public void ReturnItem(){
    System.out.println("Item returnd succesfully");
    
    }
    
    public double calculateLateFee (double a){
        return 1.0 * a;
    }


    
           public void displayInfo (){
    System.out.println("Item: DVD") ;
    super.displayInfo();
    System.out.println("Duration : " + Duration);
    }
    
    
}


