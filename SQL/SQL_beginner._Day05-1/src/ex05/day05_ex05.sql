CREATE UNIQUE INDEX idx_person_order_order_date
ON person_order (person_id, menu_id)
WHERE order_date = '2022-01-01';
EXPLAIN ANALYSE
select person_id, menu_id from person_order
where order_date = '2022-01-01';