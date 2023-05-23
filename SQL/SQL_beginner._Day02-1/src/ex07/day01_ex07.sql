select pizza_name
from person_visits
         inner join person p on p.id = person_visits.person_id
         inner join pizzeria pz on pz.id = person_visits.pizzeria_id
         inner join menu m on pz.id = m.pizzeria_id
where p.name = 'Dmitriy'
  and visit_date = '2022-01-08'
  and price < 800;

