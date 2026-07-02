/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.librarymanagement;

/**
 *
 * @author CSE Lab
 */
public class LibraryItem {
   protected String itemid ;
   protected String title; 
   protected String author;
   
   
   public LibraryItem(String itemid,String title,String author){
   
     this.itemid = itemid;
     this.title = title;
     this.author = author;
   }

    public String getItemid() {
        return itemid;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public void setItemid(String itemid) {
        this.itemid = itemid;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthor(String author) {
        this.author = author;
    }
    
    public double calculateLateFee (double a){
        return a;
    }

  
    public void displayInfo (){
    System.out.println("Item id : " + itemid) ;
    System.out.println("Title : " + title) ;
    System.out.println("Author : " + author) ;
    }
}
