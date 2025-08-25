SELECT id, name, category_id 
FROM sub_categories sc
WHERE sc.id = :sub_category_id;