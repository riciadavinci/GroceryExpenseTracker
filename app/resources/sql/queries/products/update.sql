UPDATE products 
SET category_id = :category_id, 
    sub_category_id = :sub_category_id, 
    unit_id = :unit_id, 
    product_name = :product_name, 
    variant = :variant, 
    brand_name = :brand_name, 
    nutri_score = :nutri_score,
    modified_on = CURRENT_TIMESTAMP
WHERE id = :product_id;