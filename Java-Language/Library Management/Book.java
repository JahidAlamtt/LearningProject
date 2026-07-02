/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.librarymanagement;

/**
 *
 * @author CSE Lab
 */
public class Book extends LibraryItem implements Brrowable {
    
    private int Page;

    public Book( String itemid, String title, String author, int Page) {
        super(itemid, title, author);
        this.Page = Page;
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
        return 0.5 * a;
    }
    
    public void displayInfo(){
    System.out.println("Item: Book") ;
    super.displayInfo();
    System.out.println("Page : " + Page);
    }
    
}
