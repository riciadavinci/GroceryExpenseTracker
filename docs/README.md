## Software Requirements

_**Tech Stack**_: C++17, Qt6 (core, widgets, sql), SQLite Database, CMake, MSVC 2022 compiler, Google-Test


### Tasks (_broad overview_):
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
    - [ ] Add unit-tests (as well as integration and end-to-end tests, eventually)
    - [ ] Add code coverage
    - [ ] Store photo of a GroceryBill as a blob?
    - [ ] Move to REST-APIs (RestGroceryBillRepository, RestBillItemRepository, etc.)
         - [ ] Then keep the SQLite Database as local persistent cache (in case of no internet connection)
    - [ ] Maybe allow conversion of currencies??
    - [ ] Show store locations on a map in-case address field is present
    - [ ] Import (extract) bill data from photo (OCR/OpenCV/Tesseract??)
    - [ ] Add Nutrition Labels for BillItem objects??

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

## Database Schema:

<pre>
[Category]
  category_id (PK)
  category_name

[SubCategory]
  subcategory_id (PK)
  subcategory_name
  category_id (FK → Category)

[Unit]
  unit_id (PK)
  unit_shortform  (e.g., "Kg", "g", "L", "ml", "pcs")
  unit_fullform   (e.g., "Kilograms", "Grams", "Liters", "Milliliters", "Pieces")

[Product]
  product_id (PK)
  category_id (FK → Category)
  subcategory_id (FK → SubCategory)
  brand_name (nullable)
  product_name (nullable)
  variant (nullable)       -- e.g., "1.5% fat", "Boneless Breast", "Organic"
  unit_id (FK → Unit)

[GroceryBill]
  bill_id (PK)
  bill_date
  store_id (FK → GroceryStore) -- optional

[GroceryStore]
  id (PK)
  name TEXT,
  // anything else??

[Address]
-- Address table
CREATE TABLE address (
    id TEXT PRIMARY KEY,           -- e.g., "AD-<UUID>"
    internal_id INTEGER UNIQUE,    -- optional
    store_id TEXT NOT NULL,
    street TEXT,
    city TEXT,
    state TEXT,
    zipcode TEXT,
    country TEXT,
    latitude REAL,
    longitude REAL,
    FOREIGN KEY(store_id) REFERENCES grocery_store(id) ON DELETE CASCADE
);

[BillItem]
  bill_item_id (PK)
  bill_id (FK → GroceryBill)
  product_id (FK → Product)
  unit_price        -- price per unit at purchase
  discount_amount   -- in currency, nullable
  discount_percent  -- nullable
  quantity          -- number of units or weight/volume
  count             -- number of identical packs (default 1)
  total_price       -- final price after discount (precalculated)

</pre>


<pre>
1️⃣ Meat & Poultry

Sub-categories:

Chicken

Beef

Pork

Fish & Seafood

Eggs

Plant-based Proteins (optional, e.g., tofu if you want it here instead of premade)

2️⃣ Dairy

Sub-categories:

Fresh Cheese (e.g., cream cheese, quark, ricotta)

Hard Cheese (e.g., cheddar, gouda)

Milk & Milk Alternatives (e.g., cow milk, soy milk)

Yogurt & Cultured Dairy

Butter & Ghee

3️⃣ Grains

Sub-categories:

Flours (rice flour, wheat flour, corn flour)

Cereals & Muesli (breakfast cereals, granola, muesli)

Flatbreads & Wraps (tortillas, protein wraps, lavash)

Rice & Pasta (uncooked rice, pasta, noodles)

4️⃣ Premade, Instant, & Frozen

Sub-categories:

Ready Meals & Frozen Foods

Frozen Vegetables & Fruits

Convenience Foods (instant noodles, sauces, etc.)

5️⃣ Snacks & Junk

Sub-categories:

Chips & Crisps

Sweets & Chocolates

Biscuits & Cookies

Nuts & Seeds (if consumed as snacks)

6️⃣ Produce

Sub-categories:

Fruits

Vegetables

Herbs & Fresh Spices

7️⃣ Drinks

Sub-categories:

Water

Juices & Smoothies

Soft Drinks

Coffee & Tea

Alcoholic Beverages (optional if you want to track)

8️⃣ Bakery & Baked Goods

Sub-categories:

Bread

Pastries & Cakes

Buns & Rolls

9️⃣ Condiments & Sauces

Sub-categories:

Cooking Sauces (ketchup, mustard, mayonnaise)

Dressings

Vinegars

10️⃣ Herbs & Spices

Sub-categories:

Dried Herbs (oregano, thyme, etc.)

Ground Spices (cumin, cinnamon, etc.)

Salt & Pepper

11️⃣ Oils & Fats

Sub-categories:

Cooking Oils (olive, sunflower, canola)

Butter & Margarine (if not grouped under Dairy)

Specialty Fats (coconut oil, ghee)

12️⃣ Miscellaneous

Sub-categories:

Household Items (paper towels, cleaning)

Personal Care (optional, if you want to track non-food items)

Others

</pre>
