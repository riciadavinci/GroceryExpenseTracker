CREATE TABLE IF NOT EXISTS bill_items (
    id TEXT PRIMARY KEY,
    product_id TEXT,
    unit_price REAL,
    discount_amount REAL,
    discount_percentage REAL,
    quantity REAL,
    count INTEGER,
    total_price REAL,
    FOREIGN KEY (product_id) REFERENCES products(id) ON DELETE CASCADE
);