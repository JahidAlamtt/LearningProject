/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.librarymanagement;

/**
 *
 * @author CSE Lab
 */
    public class Magazine extends LibraryItem implements Brrowable {
    
    private int issueNumber;

    public Magazine( String itemid, String title, String author, int issueNumber) {
        super(itemid, title, author);
        this.issueNumber = issueNumber;
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
        return 0.25 * a;
    }


       public void displayInfo (){
    System.out.println("Item: Magazine") ;
    super.displayInfo();
    System.out.println("Issue Number: " + issueNumber);
    }
    
    
}
