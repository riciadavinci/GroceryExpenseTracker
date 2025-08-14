CREATE TABLE IF NOT EXISTS addresses (
    id TEXT PRIMARY KEY,
    store_id TEXT,
    street_name TEXT,
    house_number TEXT,
    city TEXT,
    zipcode TEXT,
    state TEXT,
    country TEXT,
    latitude REAL,
    longitude REAL,
    created_on DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    modified_on DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (store_id) REFERENCES grocery_stores(id) ON DELETE CASCADE
);