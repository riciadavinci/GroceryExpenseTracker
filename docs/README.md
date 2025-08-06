## Software Requirements

_**Tech Stack**_: C++17, Qt6 (core, widgets, sql), SQLite Database, CMake, MSVC 2022 compiler, Google-Test


### Tasks (_board overview_):
- [ ] Define the Entities in detail:
    - [ ] GroceryBill
    - [ ] BillItem
    - [ ] define categories of BillItem (ex: Fruits & Vegetables, Instant Foods, etc.)
- [ ] Implement data classes:
    - [ ] GroceryBill
    - [ ] BillItem
- [ ] Define Abstract Repositories:
    - [ ] IGroceryBillRepository
    - [ ] IBillItemRepository
- [ ] Implement DatabaseManager class
    - [ ] Connect & Disconnect
    - [ ] Default values of fields
- [ ] Implement SQL Repositories:
    - [ ] SqlGroceryBillRepository
    - [ ] SqlBillItemRepository
- [ ] Implement widgets (Qt's model-view pattern):
    - [ ] grocery_bill_widgets
        - [ ] GroceryBillModel
        - [ ] GroceryBillEditor
        - [ ] AddGroceryBillWidget
        - [ ] EditGroceryBillWidget (this includes delete)
        - [ ] SearchGroceryBillWidget
    - [ ] bill_item_widgets
        - [ ] BillItemModel
        - [ ] BillItemEditor
        - [ ] AddBillItemWidget
        - [ ] EdutBillItemWidget (this includes delete)
        - [ ] SearchBillItemWidget (does this make sense??)
    - [ ] dashboard_widgets (show stats with date range)
- [ ] Miscellaneous tasks:
    - [ ] Implement miscellaneous classes after consideration
        - [ ] GroceryStore
        - [ ] ItemCategory
        - [ ] GroceryStoreAddress??
    - [ ] Add in-memory caching to GroceryBillModel, BillItemModel
    - [ ] Ability to add/manage ItemCategory (item categories)
    - [ ] Ability to add/manage GroceryStore (supermarkets/stores/shops)
    - [ ] Ability to add/manage QuantityType (Kg, grams, Liters, number, etc.)
    - [ ] Generate PDF of a given bill
    - [ ] Export bill(s) to CSV/Excel??
- [ ] Future Tasks:
    - [ ] Improve design/visuals with Style-sheets/QML
    - [ ] Add doxygen documentation
    - [ ] Add code coverage
    - [ ] Store photo of a GroceryBill as a blob?
    - [ ] Move to REST-APIs (RestGroceryBillRepository, RestBillItemRepository, etc.)
         - [ ] Then keep the SQLite Database as local persistent cache (in case of no internet connection)
    - [ ] Maybe allow conversion of currencies??
    - [ ] Show locations on a map in-case address field is present
    - [ ] Import (extract) bill data from photo (OCR/OpenCV/Tesseract??)

--- 

### Class/Entitiy declarations:

1. GroceryBill
```C++
class GroceryBill
{
    QString m_bill_id; // UUID with a custom prefix
    QString m_store_id; // Foreign key - ID of GroceryStore class - QString name, bool is_franchise/is_chain, vector of addresses?. Selected from drop-down menu
    double m_amount; // round calculations to 2nd decimal places! Unit-test for accuracy!!
    QDate m_bill_date;
    QTime m_bill_time;
    QVector<BillItem> m_items;
    QDateTime m_created_on; // Meta-data
    QDateTime m_modified_on; // Meta-data
};
```

2. BillItem
```C++
class BillItem
{
    QString m_item_id; // UUID with a custom prefix
    QString m_parent_bill_id; // Foreign key - ID of GroceryBill class
    QString m_item_category_id; // Foreign key - ID of ItemCategory class
    double m_price; // Round-off to 2nd decimal place
    Enum Currency; // Euro as default or add it to TODO as future task?
    double m_quantity;
    QString m_quantity_type_id; // Foreign key - ID of QuantityType class (select from drop-down menu)
    QDateTime m_created_on; // Meta-data
    QDateTime m_modified_on; // Meta-data
};
```
