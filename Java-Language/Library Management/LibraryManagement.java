/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.librarymanagement;

/**
 *
 * @author CSE Lab
 */
import java.util.ArrayList;

public class LibraryManagement {

    public static void main(String[] args) {

        ArrayList<LibraryItem> items = new ArrayList<>();

        items.add(new Book("B101", "Java Programming", "James Gosling", 650));
        items.add(new Magazine("M205", "Science Today", "Editorial Board", 58));
        items.add(new DVD("D310", "Artificial Intelligence", "Documentary Studio", 120));

        for (LibraryItem item : items) {

            item.displayInfo();

            // Interface methods
            Brrowable b = (Brrowable) item;
            b.BrrowItem();

            System.out.printf("Late Fee (7 days): $%.2f%n",
                    item.calculateLateFee(7));

            b.ReturnItem();

            System.out.println("--------------------------------------");
        }
    }
}