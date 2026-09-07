# TCS-504 Assignment 1 — Movie Ticket Booking System

**B.Tech CSE, Semester 5 — System Design (TCS-504)**

## Project
A menu-driven C++ console application for a single cinema. It implements the eight required features from Assignment 1: movie listing, show listing, seat availability, multi-seat booking, seat-type pricing, UPI/Card/Cash payment, ticket printing, and cancellation.

## Required OOP concepts
Encapsulation, abstraction, inheritance, runtime polymorphism, compile-time polymorphism, static members, `this`, composition and aggregation are demonstrated in the source files.

## SOLID
Single Responsibility, Open/Closed, Liskov Substitution and Dependency Inversion are mapped in the assignment PDF and reflected in the design.

## Structure
- `src/` — one C++ class per file, with no header files.
- `docs/` — class and sequence diagram text.
- `Assignment_1_Solution.pdf` — complete written assignment solution.
- `main.cpp` — program entry point; it includes the class `.cpp` files in dependency order as required by the no-header-file rule.

## Compile
```bash
g++ -std=c++17 main.cpp -o movie_booking
```

## Run
```bash
./movie_booking
```
On Windows, run `movie_booking.exe`.

## Edge cases
The program rejects invalid seats and menu choices, rejects already-booked seats without changing state, releases seats after failed payment, and makes seats available again after cancellation.
