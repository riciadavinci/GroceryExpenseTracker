CREATE TABLE IF NOT EXISTS grocery_stores (
    id TEXT PRIMARY KEY,
    name TEXT NOT NULL UNIQUE,
    type_id INTEGER,
    FOREIGN KEY (type_id) REFERENCES store_types(id)
);