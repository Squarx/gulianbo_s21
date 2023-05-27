set enable_seqscan = OFF;
EXPLAIN ANALYZE SELECT m.pizza_name, p.name
FROM menu m
JOIN pizzeria p ON m.pizzeria_id = p.id;

