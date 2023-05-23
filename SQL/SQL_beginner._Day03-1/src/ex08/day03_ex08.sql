--v1
WITH pz_id_CTE AS (SELECT id
                   FROM pizzeria
                   WHERE name = 'Dominos'),
     max_ind_CTE AS (SELECT MAX(id) + 1 AS next_id
                     FROM menu)
INSERT
INTO menu (id, pizzeria_id, pizza_name, price)
SELECT max_ind_CTE.next_id, pz_id_CTE.id, 'sicilian pizza', 900
FROM max_ind_CTE, pz_id_CTE;

--v2
INSERT INTO menu(id, pizzeria_id, pizza_name, price)
VALUES ((SELECT max(id) + 1 FROM menu),
        (SELECT id FROM pizzeria WHERE name = 'Dominos'),
        'sicilian pizza',
        900);

-- delete last
DELETE
FROM menu
WHERE id = (SELECT MAX(id)
            FROM menu);
-- show table
select *
from menu;