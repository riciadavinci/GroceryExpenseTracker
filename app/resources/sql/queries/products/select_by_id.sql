SELECT id, category_id, sub_category_id, unit_id, product_name, variant, brand_name, nutri_score 
FROM products p 
WHERE p.id = :product_id;