CREATE UNIQUE INDEX idx_menu_unique ON menu (pizzeria_id, pizza_name);
EXPLAIN ANALYSE
SELECT pizza_name, pizzeria_id
FROM menu
WHERE pizzeria_id = 5
  AND pizza_name = 'supreme';
-- WHERE person_id = 8 AND menu_id = 19;
