SELECT id, name, category_id 
FROM sub_categories sc
WHERE sc.category_id = :category_id;