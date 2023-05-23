SELECT pizza_name
FROM person_visits
         INNER JOIN person p ON p.id = person_visits.person_id
         INNER JOIN pizzeria pz ON pz.id = person_visits.pizzeria_id
         INNER JOIN menu m ON pz.id = m.pizzeria_id
WHERE p.name = 'Dmitriy'
  AND visit_date = '2022-01-08'
  AND price < 800;


-- +1 greek pizza (720) не удалял после 03
INSERT INTO person_visits
SELECT MAX(id) + 1,
       (SELECT id FROM person WHERE name = 'Dmitriy'),
       (SELECT id FROM pizzeria WHERE name = 'Dominos'),
       DATE '2022-01-08'
FROM person_visits;


REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;
select * from mv_dmitriy_visits_and_eats;

