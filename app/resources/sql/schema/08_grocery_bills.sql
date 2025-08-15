CREATE TABLE IF NOT EXISTS grocery_bills (
    id TEXT PRIMARY KEY,
    bill_date DATETIME NOT NULL,
    total REAL NOT NULL,
    store_id TEXT NOT NULL,
    address_id TEXT NOT NULL,
    created_on DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    modified_on DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (store_id) REFERENCES grocery_stores(id),
    FOREIGN KEY (address_id) REFERENCES addresses(id)
);