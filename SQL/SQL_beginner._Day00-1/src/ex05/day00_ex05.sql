SELECT
    (SELECT name FROM person WHERE id = po.person_id) AS NAME
FROM
    person_order as po
WHERE (
menu_id = 13 OR
menu_id = 14 OR
menu_id = 18) and
order_date = '2022-01-07';
