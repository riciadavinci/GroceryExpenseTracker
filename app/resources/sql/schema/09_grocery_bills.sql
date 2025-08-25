CREATE TABLE IF NOT EXISTS grocery_bills (
    id TEXT PRIMARY KEY,
    total REAL NOT NULL,
    currency_id INTEGER NOT NULL,
    bill_date DATE NOT NULL,
    bill_time TIME NOT NULL,
    store_id TEXT NOT NULL,
    address_id TEXT NOT NULL,
    created_on DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    modified_on DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (currency_id) REFERENCES currencies(id),
    FOREIGN KEY (store_id) REFERENCES grocery_stores(id),
    FOREIGN KEY (address_id) REFERENCES addresses(id)
);