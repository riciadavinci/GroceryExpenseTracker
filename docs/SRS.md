# 📄 Software Requirements Specification (SRS)

**Project Name**: Grocery Expense Tracker
**Version**: 1.0
**Prepared by**: Rishikesh Arunkumar Nerurkar

---

## 1. Introduction

### 1.1 Purpose
The Grocery Expense Tracker is a desktop application that allows users to manage grocery-related expenses by recording grocery bills, products, and pfand transactions. The app enables users to track costs, organize purchases into categories, and calculate total expenses.

### 1.2 Scope
The application is intended for personal use on a desktop environment. It provides CRUD functionality for grocery-related data while keeping a set of system-defined reference data (units, categories, subcategories, store types, and currencies).

Key capabilities include:
* Creating and managing products.
* Recording grocery bills and related items.
* Logging pfand (deposit) transactions.
* Associating bills with stores, addresses, and currencies.
* Automatic calculation of discounts and totals.

### 1.3 Definitions & Abbreviations
* **CRUD**: Create, Read, Update, Delete
* **Pfand**: Bottle deposit system in Germany and other regions.
* **Entity**: Database object with attributes.

### 1.4 References
* IEEE 830 SRS template (for structure)
* Qt 6 documentation
* SQLite documentation

---

## 2. Overall Description

### 2.1 Product Perspective
The Grocery Expense Tracker is a **standalone desktop GUI application** with a local SQLite database. There are no external APIs or multi-user access.

### 2.2 Product Features
* CRUD operations on products, bills, bill items, addresses, stores, and pfand transactions.
* Pre-seeded reference data for units, categories, subcategories, currencies, and store types.
* Store and address linkage for location tracking.
* Support for different currencies in bills.
* Automatic computation of total price, discounts, and pfand balances.

### 2.3 User Characteristics
* A single user (the person installing the app).
* Basic knowledge of desktop applications.
* No authentication or user roles required.

### 2.4 Constraints
* Desktop only (Windows, compiled with MSVC 2022).
* Uses SQLite (no external DB).
* Single-user local application (no networking).

### 2.5 Assumptions & Dependencies
* User will maintain data consistency (e.g., select correct category for products).
* Pre-fed data (units, categories, subcategories, store types, currencies) is immutable.
* Qt must be installed/configured on the system.

---

## 3. System Features & Requirements

### 3.1 Entities

#### 3.1.1 Unit
* Fields: {id, shortform, fullform}
* Pre-seeded, read-only.

#### 3.1.2 Category
* Fields: {id, name}
* Pre-seeded, read-only.

#### 3.1.3 SubCategory
* Fields: {id, name, category\_id}
* Pre-seeded, read-only.

#### 3.1.4 Product
* Fields: {id, category\_id, sub\_category\_id, unit\_id, product\_name, variant, brand\_name, nutri\_score}
* User can CRUD.
* Must reference one category, subcategory, and unit.

#### 3.1.5 Address
* Fields: {id, store\_id, street\_name, house\_number, city, zipcode, state, country, latitude, longitude}
* User can CRUD.
* Must belong to exactly one GroceryStore.

#### 3.1.6 StoreType
* Fields: {id, name}
* Pre-seeded, read-only.

#### 3.1.7 GroceryStore
* Fields: {id, name, type\_id}
* User can CRUD.
* Must reference one StoreType.
* Can have 0 or more addresses.

#### 3.1.8 Currency
* Fields: {id, name, code, symbol}
* Pre-seeded, read-only.

#### 3.1.9 GroceryBill
* Fields: {id, total, currency\_id, bill\_date, bill\_time, store\_id, address\_id}
* User can CRUD.
* Must reference a currency and store.
* May reference an address.

#### 3.1.10 BillItem
* Fields: {id, grocery\_bill\_id, product\_id, unit\_price, discount\_percent, discount\_price, quantity, count, total\_price}
* User can CRUD.
* Must reference a grocery bill and product.

#### 3.1.11 PfandTransaction
* Fields: {id, grocery\_bill\_id, date, amount, pfand\_type}
* User can CRUD.
* Must reference one grocery bill.

---

### 3.2 Functional Requirements

**FR1. Product Management**
* The system shall allow CRUD operations on products.
* The system shall enforce category, subcategory, and unit references.

**FR2. Store & Address Management**
* The system shall allow CRUD operations on grocery stores.
* The system shall allow CRUD operations on addresses linked to a store.

**FR3. Bill Management**
* The system shall allow CRUD operations on grocery bills.
* The system shall allow CRUD operations on bill items.
* The system shall automatically compute bill totals and discounts.

**FR4. Pfand Management**
* The system shall allow CRUD operations on pfand transactions.
* The system shall enforce valid pfand types (“paid” or “redeemed”).

**FR5. Reference Data**
* Units, Categories, Subcategories, Currencies, and Store Types shall be pre-seeded.
* The user shall not be able to modify reference data.

---

## 4. Non-Functional Requirements
* **NFR1 (Performance):** App should respond to CRUD actions in < 200ms for local DB queries.
* **NFR2 (Usability):** Provide intuitive GUI with forms and tables for entity management.
* **NFR3 (Portability):** Runs on Windows 10/11 (MSVC 2022 compiled binary).
* **NFR4 (Reliability):** Local data must persist in SQLite DB.
* **NFR5 (Maintainability):** Code structured with CMake modularization (core, widgets, db, tests).

---

## 5. Tech Stack
* **Programming Language:** C++17
* **GUI Framework:** Qt6
* **Build System:** CMake
* **Compiler:** MSVC 2022
* **Database:** SQLite (via QtSql)
* **Testing:** Google Test (gtest)

* *(Optional additions you may list)*:
  * **Logging:** spdlog or Qt’s built-in logging
  * **Packaging:** CPack or Inno Setup for installers
  * **Version Control:** Git + GitHub/GitLab
