CREATE TABLE IF NOT EXISTS products (
    id TEXT PRIMARY KEY,
    category_id INT NOT NULL,
    sub_category_id INT NOT NULL,
    unit_id INT NOT NULL,
    product_name TEXT,
    variant TEXT
    brand_name TEXT,
    created_on DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    modified_on DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (category_id) REFERENCES categories(id),
    FOREIGN KEY (sub_category_id) REFERENCES sub_categories(id),
    FOREIGN KEY (unit_id) REFERENCES units(id) 
);