CREATE TABLE IF NOT EXISTS pfand_transactions (
    id TEXT PRIMARY KEY,
    grocery_bill_id TEXT NOT NULL,
    date DATE NOT NULL,
    amount REAL NOT NULL,
    pfand_type TEXT CHECK(pfand_type IN ('paid', 'redeemed')) NOT NULL,
    FOREIGN KEY (grocery_bill_id) REFERENCES grocery_bills(id),
);