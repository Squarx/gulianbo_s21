CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats as
select pizza_name
from person_visits
         inner join person p on p.id = person_visits.person_id
         inner join pizzeria pz on pz.id = person_visits.pizzeria_id
         inner join menu m on pz.id = m.pizzeria_id
where p.name = 'Dmitriy'
  and visit_date = '2022-01-08'
  and price < 800;

SELECT * FROM mv_dmitriy_visits_and_eats;


SELECT pizza_name
FROM person_visits
         INNER JOIN person p ON p.id = person_visits.person_id
         INNER JOIN pizzeria pz ON pz.id = person_visits.pizzeria_id
         INNER JOIN menu m ON pz.id = m.pizzeria_id
WHERE p.name = 'Dmitriy'
  AND visit_date = '2022-01-08'
  AND price < 800;

